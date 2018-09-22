#ifndef LILCDAEMON_H_INCLUDED
#define LILCDAEMON_H_INCLUDED

int lilcdaemon(int setvalumask, char* setvaldirchange, int setclosestd, int setsighandler);
void signal_handler(int sig);

#endif
