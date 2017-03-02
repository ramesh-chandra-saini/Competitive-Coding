/*Viral Advertising Hacker Rank Problem Solution .*/

day = int(raw_input())
N = 5
ans = 0
while day:
    day-=1
    ans += N/2
    N = (N/2)*3
print ans

