from Crypto.Cipher import DES
from pwn import *

r = remote('host3.dreamhack.games', 9014)
r.recvline()
data = r.recvline()[16:-1]
C = bytes.fromhex(data.decode())

P = b"DreamHack_blocks"
memory = {}

for k1 in range(0, 256*256):
    key1 = b"Dream_" + k1.to_bytes(2, 'big')
    cipher1 = DES.new(key1, DES.MODE_ECB)
    memory[cipher1.encrypt(P)] = k1

ans = None
for k2 in range(0, 256*256):
    key2 = k2.to_bytes(2, 'big') + b"Hacker"
    cipher2 = DES.new(key2, DES.MODE_ECB)
    M = cipher2.decrypt(C)
    if M in memory:
        print(f'k1={memory[M]} k2={k2}')
        ans = b"Dream_" + memory[M].to_bytes(2, 'big') + k2.to_bytes(2, 'big') + b"Hacker"
        break

if ans is None:
    print("키를 찾지 못했습니다.")
    exit(1)

cipher1 = DES.new(ans[:8], DES.MODE_ECB)
cipher2 = DES.new(ans[8:], DES.MODE_ECB)
msg = cipher2.encrypt(cipher1.encrypt(b"give_me_the_flag")).hex()

print(msg)
r.sendline(msg.encode('ascii'))
r.interactive()