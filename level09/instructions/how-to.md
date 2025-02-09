Level08 instructions

```
level09@SnowCrash:~$ ./level09 dssdf
dtugj
level09@SnowCrash:~$ ./level09 123
135
level09@SnowCrash:~$ ./level09 1111
1234
level09@SnowCrash:~$ ./level09 1234567
13579;=
level09@SnowCrash:~$ he
head       help       helpztags  hexdump
level09@SnowCrash:~$ he
head       help       helpztags  hexdump
level09@SnowCrash:~$ hexdump token
0000000 3466 6d6b 366d 7c70 823d 707f 6e82 8283
0000010 4244 4483 7b75 8c7f 0a89
000001a
level09@SnowCrash:~$ hexdump token --help
hexdump: invalid option -- '-'
usage: hexdump [-bcCdovx] [-e fmt] [-f fmt_file] [-n length]
               [-s skip] [file ...]
       hd      [-bcdovx]  [-e fmt] [-f fmt_file] [-n length]
               [-s skip] [file ...]
level09@SnowCrash:~$ hexdump -C token --help
hexdump: invalid option -- '-'
usage: hexdump [-bcCdovx] [-e fmt] [-f fmt_file] [-n length]
               [-s skip] [file ...]
       hd      [-bcdovx]  [-e fmt] [-f fmt_file] [-n length]
               [-s skip] [file ...]
level09@SnowCrash:~$ hexdump -C token
00000000  66 34 6b 6d 6d 36 70 7c  3d 82 7f 70 82 6e 83 82  |f4kmm6p|=..p.n..|
00000010  44 42 83 44 75 7b 7f 8c  89 0a                    |DB.Du{....|
0000001a
```