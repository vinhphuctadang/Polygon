n, x, y = map(int, input().split())
dis = list(map(int, input().split()))

# precompute
x-=1
y-=1
res = 10000000000

# forward
tmp = 0
u = x
for i in range(n):
    v = (u + 1) % n
    tmp += dis[u]
    # print(dis[u])

    if v == y:
        res = min(res, tmp)
        break
    u = v
# backward
u = x
tmp = 0
for i in range(n):
    v = (u - 1 + n) % n
    tmp += dis[v]
    # print(dis[v])
    if v == y:
        res = min(res, tmp)
        break
    u = v

print(res)