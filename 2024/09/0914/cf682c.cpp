#include <bits/stdc++.h>
#define x first
#define y second
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define de(a) cerr << #a <<" = "<< a <<'\n';
#define endl '\n'
#define deg(a) cerr << #a <<" = "<< a <<' ';
//#define int long long 
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

void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (auto &v : nums) cin >> v;

	vector<int> edge(n, 0);
	vector<vector<int>> tree(n);

	for(int i = 1;i < n ;i ++) {
		int p;
		cin >> p >> edge[i];
		p --;
		tree[p].emplace_back(i);
	}

	vector<int> dp(n, 0), stk = {0};
	int ans = 0, upper = 1e9 + 5;

	while(!stk.empty()) {
		int u = stk.back();
		stk.pop_back();
		ans ++;

		for(auto v: tree[u]){
			dp[v] = max(0, dp[u]) + edge[v];
			if(dp[v] <= nums[v]) stk.emplace_back(v);
		}

	}

	cout<<n - ans;



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