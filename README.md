# Lil C Daemon

    Little C Daemon is just that, a small simple program that
    daemonizes your Linux programs. Just link it in your script
    and call it. It will be optimized for embedded Linux applications and other low memory systems. 

## Installation

    Add the following in your code of your main file you want to daemonize.

### Code Usage Example 0

    #include "lilcdaemon.h"

    // ( No Umask, No Working Dir Change, No Closing STD, No Handling Signals )

    if ( lilcdaemon(-1, 0, 0, 0) != 0 ){
       exit(-1);
    }

### Code Usage Example 1

    #include "lilcdaemon.h"

    // Umask 0, Working Dir '/', Close STD, Handle Signals

    if ( lilcdaemon(0, "/", 1, 1) != 0 ){
       exit(-1);
    }

## Compile

    gcc -std=gnu99 -o sampledaemon ./example_src/sampleprogram.c ./src/lilcdaemon.c -lm

## Usage

    sudo ./sampledaemon

## Results

Executing `tail` while sampledaemon is running:
```shell
sysop@salish:~/development/embedded/lil-c-daemon/src$ ./sampledaemon && tail -f /var/log/syslog
    Sep 22 09:32:47 salish lilcdaemon[29266]: Sample Program output test #0
    Sep 22 09:32:48 salish lilcdaemon[29266]: Sample Program output test #1
    Sep 22 09:32:49 salish lilcdaemon[29266]: Sample Program output test #2
    Sep 22 09:32:50 salish lilcdaemon[29266]: Sample Program output test #3
    Sep 22 09:32:51 salish lilcdaemon[29266]: Sample Program output test #4
    Sep 22 09:32:52 salish lilcdaemon[29266]: Sample Program output test #5
    Sep 22 09:32:53 salish lilcdaemon[29266]: Sample Program output test #6
```

Executing `ps` while sampledaemon is running:
```shell
sysop@salish:~/development/Embedded/lil-c-daemon$ ps -auxf | grep -i sampledaemo[n]
    USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
    sysop    10007  0.0  0.0   4516    76 ?        Ss   09:56   0:00 ./sampledaemon
```

## Todo

    1. Add build instructions for cross compilation on Openwrt/LEDE
    2. Create sample init scripts for Openwrt/LEDE
    3. Test on Raspberry PI and other Single Board Computers
    4. Clean up and normalize code
    5. Add optional additional features and more usage examples
    6. Test

## Contributing

    1. Why? It's terrible right now, so why not?
    2. Create an Issue
    3. Submit a Pull Request

## History

    2018-09-22: Created initial Daemonizing Code

## Credits

    Creator: Joshua Whittington
    Contact: lilc_git@doubleyoudouble.me

## License

    MIT
    https://github.com/youdouble/lil-c-daemon/blob/master/LICENSE

## Note:    
The `Legacy` connotation is based on the following: [Man 7 Definition SysV](https://www.freedesktop.org/software/systemd/man/daemon.html#SysV%20Daemons "SysV Daemons")
