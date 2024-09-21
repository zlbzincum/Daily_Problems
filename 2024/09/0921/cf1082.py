import os,io


fmax = lambda x, y:x if x > y else y

fmin = lambda x, y:x if x < y else y
if __name__ == '__main__':
    n = int(input())
    s = input()

    ans = 0
    cnt  = 0
    l = r = 0

    while l < n:

        while(r < n and cnt + (s[r] == 'S') <= 1):
            cnt += (s[r] == 'S')
            r += 1

        ans = fmax(ans, r - l)
        cnt -= (s[l] == 'S')
        l += 1

    print(fmin(ans, s.count('G')))