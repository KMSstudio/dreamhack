from pwn import *

p = process('./auto-math')

for i in range(1000):
    p.recvuntil(b') ')
    data = p.recv().split(b' ')
    print(data)
    num1 = int(data[0])
    num2 = int(data[2])
    
    if data[1] == b'*':
        p.sendline(str(num1 * num2))
    else:
        p.sendline(str(num1 + num2))

p.interactive()
