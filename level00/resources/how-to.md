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