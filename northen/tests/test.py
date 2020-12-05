
a = 1
for i in range(1000):
    tmp = list(str(a*2))
    tmp.sort()
    b = ''.join(tmp)
    print(b)
    a = int(b)
