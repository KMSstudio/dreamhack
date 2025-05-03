# Alphabet table for trans
ALPHABET = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"

# Mapping
CHAR_TO_VALUE = {ch: idx for idx, ch in enumerate(ALPHABET)}
CHAR_TO_VALUE[b"=" [0]] = 0

def decode(encoded: bytes) -> bytes:
    """Decode"""
    bits = 0
    bit_count = 0
    output = bytearray()

    for ch in encoded:
        value = CHAR_TO_VALUE.get(ch, 0)
        bits = (bits << 5) | value
        bit_count += 5

        if bit_count >= 8:
            bit_count -= 8
            byte = (bits >> bit_count) & 0xFF
            output.append(byte)

    return bytes(output)

if __name__ == "__main__":
    # target.txt 파일 읽기
    with open('target.txt', 'rb') as f:
        data = f.read().strip()

    decoded = decode(data)
    print("Decoded:", decoded)