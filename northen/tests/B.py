n, k = map(int, input().split())
F = list(map(int, input().split()))
L = list(map(int, input().split()))

mn = 0
for i in range(n):
    if F[i] == 0 and L[i] == 1:
        mn+=1

mx = 0
for i in range(n):
    # top = k
    if F[i] == 1:
        mx += k-1
    else:
        mx += k
print(mn, mx)
    