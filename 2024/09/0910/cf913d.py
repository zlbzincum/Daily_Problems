def MII():
    return map(int, input().split())

def main():
    n,t = MII()
    vals = []
    ts = []

    for _ in range(n):
        a, p = MII()
        vals.append(a)
        ts.append(p)

        st_range = list(range(n))
        st_range.sort(key=lambda x: -vals[x])

        ans = 0
        hpd = []
        cur = 0
        for i in st_range:
            heappush(hpd, -ts[i])
            cur