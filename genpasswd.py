import random

data = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[]{};'\:\"|,./<>?`~"
l = len(data)
key = [random.randint(0, 100) for i in range(16)]
pw = [ord(data[random.randint(0, l-1)]) - key[i] for i in range(16)]

print("password: " + "".join([chr(pw[i] + key[i]) for i in range(16)]))
print("key: " + str(key).translate(str.maketrans('[]', '{}')))
print("pw: " + str(pw).translate(str.maketrans('[]', '{}')))
