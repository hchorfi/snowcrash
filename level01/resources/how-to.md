Level01 instructions

On this level, there is no useful information on the home directory, or any file owned by flag01 noticed like how we did in the previous level.

While checking the users and groups on the snowcrash machine `/etc/passwd`, we can easy notice tha the user `flag01` doesn't follow the pattern like other. and use a word instead of `x` that means the actual password is in `/etc/shadow` (hashed) that we do not have the right to access it.
```
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```
But here, we have a clear hash that mostly a DES(unix data encryption standard) since it doesn't start with $ and it's a 13 length char and the first 2 ones are `42` (salt)
For this type of hashes the most used solution is brut forcing it using dictionaries.
I used `hashcat` in the beginning but it took too much time, depending of the position of the hash on the dictionary file. (there is some example dictionaries with the most known passwords came with hashcat by default).
Then i used `John the Ripper` and it was much faster.
```
> john ./hash.txt
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 64/64])
Press 'q' or Ctrl-C to abort, almost any other key for status
abcdefg          (?)
1g 0:00:00:00 100% 2/3 100.0g/s 76800p/s 76800c/s 76800C/s veronica..bigman
Use the "--show" option to display all of the cracked passwords reliably
Session completed
```

```
level01@SnowCrash:~$ su flag01
Password:
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
flag01@SnowCrash:~$ su level02
Password:
level02@SnowCrash:~$
```