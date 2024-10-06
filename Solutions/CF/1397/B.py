n = int(input())
a = [int(item) for item in input().split()]

if n == 1:
    print(0)
    exit()

ans = -1
a.sort()
for p in range(1, int(pow(1000000000, 1.0/(n-1)))+2):
    cur = 0
    for i in range(n):
        cur += abs(a[i]-pow(p, i))
    if ans == -1:
        ans = cur
    else:
        ans = min(ans, cur)
print(ans)