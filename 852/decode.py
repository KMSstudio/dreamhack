hex_list = [(hex(i)[2:].zfill(2).upper()) for i in range(256)]

with open('encfile', 'r') as f:
    encode = f.read()
decode = ""

for i in range(0,len(encode),2):
    hex_val = hex(int(encode[i:i+2],16))[2:].zfill(2).upper()
    index = hex_list.index(hex_val)
    decode += str(hex_list[(index + 128) % len(hex_list)])

with open('decode.png','wb') as f:
    f.write(bytes.fromhex(decode))