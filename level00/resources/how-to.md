Level00

General instructions

For this level and most of other levels we need to get the token to access flagxx user, so we can run `getflag` or run it from another user if it have the right permission to do it. This command will give us the flag to access to the next level.

Like the most of the introductionary CTFs, gathering information it's very importent to not lost in the maze of geting the flag, always think simple first, looks for pattern then elaborate your searching metodology and stick with it.

For all levels i always start with the following:

- Checking home directory with permissions `ll` `ls -la`
- Checking files & directories that have the permission of the wanted user with `find`
- Cheking the most linux known folders and directories like
	- `/home/`** Home directories of all users. Look for SSH keys, passwords, scripts.
    - `/root/`** Root user’s home directory. Usually inaccessible without root privileges.
    - `/etc/`** System configuration files.
    - `/etc/passwd`** List of system users. Check for misconfigured accounts.
    - `/etc/shadow`** Stores **hashed passwords** (root access needed). Try cracking with **John the Ripper**.
    - `/etc/hosts`** Local DNS mappings (can be useful for web exploitation).
    - `/etc/cron.d/`** Scheduled cron jobs—possible privilege escalation.
    - `/etc/sudoers`** Controls sudo permissions (check for misconfigurations).
    - `/var/www/`** Default web server directory (check for web exploits).
    - `/var/log/`** System logs (can contain sensitive data).
    - `/var/mail/`** User mailboxes (possible credentials).
    - `/dev/shm/`** Shared memory space (can be used for temporary file privilege escalation).
    - `/tmp/`** Temporary directory (often world-writable, good for dropping malicious scripts).
    - `/proc/`** Information about running processes (check environment variables for credentials).
- Checking running services `ps aux` 
- ...

Level00 instructions

No useful information on the home directory, but after checking files owned by `flag00` (since we nee to run `getfalg`) we found two of them with the same content
```
level00@SnowCrash:~$ find / -user flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
level00@SnowCrash:~$ cat /usr/sbin/john /rofs/usr/sbin/john
cdiiddwpgswtgt
cdiiddwpgswtgt
```
Tested that token to access `flag00` but it doesn't work. With the help of ChatGpt it turned out that it's a rotation encrypted word.
Using `dcode.fr`, i managed to decrypt the word using César Code with all possible rotations, the noticeable one was `nottoohardhere` and it was correct
```
level00@SnowCrash:~$ su flag00
Password:
Don't forget to launch getflag !
flag00@SnowCrash:~$
flag00@SnowCrash:~$
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
flag00@SnowCrash:~$ su level01
Password:
level01@SnowCrash:~$
```