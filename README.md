### SnowCrash
1337 snowcrash | an introduction project to cyber security

General instructions

We need to get the token to access flagxx user, so we can run `getflag` or run it from another user if it have the right permission to do it. This command will give us the flag to access to the next level.

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

