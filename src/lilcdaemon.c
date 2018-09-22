/************************************************************************************\
*
*   Name:           Little C Daemon, The Simple, Small Daemonizing Function
*   Source:         https://github.com/youdouble/lil-c-daemon
*   License:        https://github.com/youdouble/lil-c-daemon/blob/master/LICENSE
*   Copyright:      (C) 2018 Joshua Whittington
*   Contact:        lilc_git@doubleyoudouble.me
*   Note:           This is the initial tests of a daemonizing function for SBC's
*                   [Ie. MT7688, AR9331, SOM9331 and more]
*
\************************************************************************************/

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>
#include "lilcdaemon.h"

int lilcdaemon(int setvalumask, char* setvaldirchange, int setclosestd, int setsighandler){

        int fd; // File Descriptor for TTY
        struct sigaction saio; // Signal Handler

        //Set U Mask
        if((setvalumask >= 0) && (umask(setvalumask) == -1)) {
                return(-1);
        }

        //Fork Process
        switch(fork()) {
        case -1: return(-1);
        case 0: break;
        default: _exit(0);
        }

        //Set Sid
        if(setsid() == -1 ) {
                return(-1);
        }

        //Change Root Directory
        if ((setvaldirchange != 0) && (chdir(setvaldirchange) == -1)) {
                return(-1);
        }

        //Close STDIN/OUT
        if ((setclosestd == 1) && (fd = open("/dev/null", O_RDWR, 0)) != -1) {
                (void)dup2(fd, STDIN_FILENO);
                (void)dup2(fd, STDOUT_FILENO);
                (void)dup2(fd, STDERR_FILENO);

                if (fd > 2) {
                        (void)close(fd);
                }
        }

        //Set Sig Handler
        if(setsighandler == 1) {
                saio.sa_handler = signal_handler;
                saio.sa_flags = 0;
                saio.sa_restorer = NULL;

                if(sigemptyset(&saio.sa_mask)) {
                        return(-1);
                }

                if(sigaction(SIGHUP, &saio, NULL)) {
                        return(-1);
                }

                if(sigaction(SIGTERM, &saio, NULL)) {
                        return(-1);
                }
        }

        return(0);
}

//Signal Handler Logic - Be Sure to configure this area if you plan to use it!
void signal_handler(int sig){
        switch(sig) {
        case SIGHUP:
                syslog(LOG_WARNING, "Received SIGHUP signal."); //Reload Configuration
                break;
        case SIGTERM:
                syslog(LOG_INFO, "Received SIGTERM signal."); //Terminate Daemon Gracefully
                exit(0);
                break;
        default:
                break;
        }
}
