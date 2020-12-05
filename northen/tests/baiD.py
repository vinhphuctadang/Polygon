n, x, y = map(int, input().split())
dis = list(map(int, input().split()))

res = 10000000000

tmp = 0
u = x
for i in range(n):
    v = (u + 1) % n
    tmp += dis[u]
    if v == y:
        res = min(res, tmp)
        break
u = x
tmp = 0
for i in range(n):
    v = (u - 1 + n) % n
    tmp += dis[u]
    if v == y:
        res = min(res, tmp)
        break

print(res)