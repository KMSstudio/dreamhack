class Caesar:
    def __init__(self, key):
        assert isinstance(key, int) and 1 <= key <= 255
        self._key = key

    def encrypt(self, msg):
        msg_enc = b""
        for b in msg:
            msg_enc = msg_enc + bytes([(b + self._key) % 256])
        return msg_enc

    def decrypt(self, msg):
        msg_dec = b""
        for b in msg:
            msg_dec = msg_dec + bytes([(b - self._key) % 256])
        return msg_dec

def main():
    with open("encfile", "r") as f:
        enc = f.read()
    enc = list(bytes.fromhex(enc))
    
    for key in range(1, 255):
        try:
            cipher = Caesar(key)
            dec = cipher.decrypt(enc)
            decypher = dec.decode('ascii')
            if not 'DH' in decypher: continue
            print(f"k={key}: {dec}")
        except:
            continue
if __name__ == "__main__":
    main()