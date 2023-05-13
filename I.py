# github.com/OptonGroup/ulivt-spring-2023

def next_permutation(ns):
    ans = ""

    sm = 0
    for el in ns:
        sm += int(el)
        if sm >= 10:
            sm = (sm%10) + (sm//10)
        ans += str(sm)
    return ans

import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())
sf = input()
s = sf.replace("0", "9")

cnt = dict()
for el in "0123456789":
    cnt[el] = 0

for el in s:
    cnt[el] += 1

ns = next_permutation(s)
pp = 1
while ns != s:
    for el in ns:
        cnt[el] += 1
    ns = next_permutation(ns)
    pp += 1

mnog = k // pp
ost = k % pp
if ost == 0:
    mnog -= 1
    ost = pp
for el in "0123456789":
    cnt[el] *= mnog

for iter in range(ost):
    for el in sf:
        cnt[el] += 1
    sf = next_permutation(sf)

for el in "0123456789":
    print(cnt[el], end=" ")
