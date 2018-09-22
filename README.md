# Lil C Daemon

    Little C Daemon is just that, a small simple program that
    daemonizes your embedded linux programs. Just link it in your script
    and call it.

## Installation

    Add the following in your code of your main file you want to daemonize.

###Example 0

    #include "lilcdaemon.h"

    // ( No Umask, No Working Dir Change, No Closing STD, No Handling Signals )

    if ( lilcdaemon(-1, 0, 0, 0) != 0 ){
       exit(-1);
    }

###Example 1

    #include "lilcdaemon.h"

    // Umask 0, Working Dir '/', Close STD, Handle Signals

    if ( lilcdaemon(0, "/", 1, 1) != 0 ){
       exit(-1);
    }

## Compile

    //Will add command for cross compiling w/ Openwrts Toolchain

    gcc -std=gnu99 -o sampledaemon sampleprogram.c lilcdaemon.c -lm

## Usage

    sudo ./sampledaemon

## Results
```C
    sysop@salish:~/development/embedded/lil-c-daemon/src$ ./sampledaemon && tail -f /var/log/syslog
        Sep 22 09:32:47 salish lilcdaemon[29266]: Sample Program output test #0
        Sep 22 09:32:48 salish lilcdaemon[29266]: Sample Program output test #1
        Sep 22 09:32:49 salish lilcdaemon[29266]: Sample Program output test #2
        Sep 22 09:32:50 salish lilcdaemon[29266]: Sample Program output test #3
        Sep 22 09:32:51 salish lilcdaemon[29266]: Sample Program output test #4
        Sep 22 09:32:52 salish lilcdaemon[29266]: Sample Program output test #5
        Sep 22 09:32:53 salish lilcdaemon[29266]: Sample Program output test #6
```

## Contributing

    1. Why? It's terrible right now, so why not?
    2. Create an Issue
    5. Submit a Pull Request

## History

    2018-09-22: Created initial Daemonizing Code

## Credits

    Creator: Joshua Whittington
    Contact: lilc_git@doubleyoudouble.me

## License

    GNU GPLv3
    https://github.com/youdouble/lil-c-daemon/blob/master/LICENSE
