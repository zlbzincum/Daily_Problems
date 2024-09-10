#include <bits/stdc++.h>
#define x first
#define y second
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define de(a) cerr << #a <<" = "<< a <<'\n';
#define endl '\n'
#define deg(a) cerr << #a <<" = "<< a <<' ';
#define int long long 
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define PII pair<int, int>

using namespace std;
using LL = long long;

constexpr int MOD = 1e9 + 7, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f; 
constexpr int N = 1e6 + 10;
vector<int> zz_word_hint;

string Y = "YES\n";
string O = "NO\n";

// 只需要找到最大的k即可
void solve()
{
	int n, t;
	cin >> n >> t;
	vector<int> vals(n), ts(n);
	for (int i = 0; i < n;i ++) {
		cin  >> vals[i] >> ts[i];
	}

	int ans = 0, tot = 0;
	priority_queue<int> pq;

	//vals 的 倒序排序 时，下标地址存在order中
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);

	sort(order.begin(), order.end(), [&] (int i, int j) { return vals[i] > vals[j];});

	for (auto &i: order) {
		pq.push(ts[i]);
		tot += ts[i];
		if (tot > t) {
			tot -= pq.top();
			pq.pop();
		}
		ans  =  max(ans, min((int)pq.size(), vals[i]));
	}
	cout << ans <<'\n';
	cout << ans << endl;

	int cnt  = 0;
	sort(order.begin(), order.end(), [&] (int i, int j) {return ts[i] < ts[j];});
	for (auto &i: order ) {
		if(vals[i] >= ans && cnt < ans) {
			cnt ++;
			cout << i + 1 << ' ';
		}
	}

}  
 
signed main()
{
	IOS;
	int T= 1;
	//cin >> T, cin.get();
	while(T --)
	{
		solve();
	}
	return 0;
}