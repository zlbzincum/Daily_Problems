
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

def main():
    n = int(input())
    nums = list(input.split())

    edge = [0]
    tree = [[]]

    for i  in range(1, n):
        p, c = map(int,input.split())
        edge.append(c)
        tree[p - 1].append(i)

    dp = [0] * n

    stk = [0]
    ans = 0

    while stk:
        u = stk.pop()
        ans += 1

        for v in tree[u]:
            dp[v] = fmax(0, dp[u]) + edge[v]
            if dp[v] <= nums[v]:
                stk.append(v)

    print(n - ans)

main()

