Level02 instructions

Looking at the home directory, we can notice the `level02.pcap`. a network packet capture file
Tried to play with `tcpdump` but it was hard to follow the data captured
```
level02@SnowCrash:~$ tcpdump -r level02.pcap -A
```
After that i tried to check it's content with `wireshark` after copying it to my local machine
(i used 14242 on the port forwarding with qemu emulator)
```
scp -P 14242 level02@localhost:/home/user/level02/level02.pcap ./
```
Opening the file with wireshark and following the tcp stream we will have 
```
# following the tcp segments and showing them as UTF-8 give us this
��%
��%
��&���� ��#��'��$
��&���� ��#��'��$
�� ����#����'������
�� 38400,38400����#SodaCan:0����'DISPLAYSodaCan:0����xterm��
������"������!
������"��"bb	B
�����������1������!
��"��
��"��
��!��������"
������"
��"����	�
������������
Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

wwwbugs login: 
l
l
e
e
v
v
e
e
l
l
X
X



Password: 
ft_wandrNDRelL0L



Login incorrect
wwwbugs login:
```
As we can see there is some anprinted characters, if we display the hexDump format we can see it's `7f` which mean 7f. which mean the user correct it's input. `ft_waNDReL0L` is the password for flag02 aft

```
level02@SnowCrash:~$ su flag02
Password:
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
flag02@SnowCrash:~$ su level03
Password:
level03@SnowCrash:~$
