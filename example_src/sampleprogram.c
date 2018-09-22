/************************************************************************************\
*
*   Name:           Shite Sample Program to Test lil-c-daemon
*   Source:         https://github.com/youdouble/lil-c-daemon
*   License:        https://github.com/youdouble/lil-c-daemon/blob/master/LICENSE
*   Copyright:      MIT - 2018 Joshua Whittington
*   Contact:        lilc_git@doubleyoudouble.me
*
\************************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include "../src/lilcdaemon.h"

int main(int argc, char* argv[]){

        int x;

        openlog("lilcdaemon", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_DAEMON);

        if ( lilcdaemon(0, "/", 1, 1) != 0 ) {
                syslog(LOG_INFO, "%s", "Failed to Daemonize.");
                closelog();
                exit(-1);
        }

        for( x = 0; x < 100; x = x + 1 ) {
                sleep(1);
                syslog(LOG_INFO, "Sample Program output test #%i", x);
        }

        closelog();
        return (0);
}
