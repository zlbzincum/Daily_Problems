#include <bits/stdc++.h>

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
	string s;
	cin >> s;
	int ex, ey;
	cin >> ex >> ey;

	map<char, pair<int, int>> mp;
	mp['U'] = {0, 1};
	mp['D'] = {0, - 1};
	mp['L'] = {-1, 0 };
	mp['R'] = {1, 0};

	if(abs(ex) + abs(ey) > n ||((ex + ey - n) & 1)) {
		cout << -1;
		return;
	}

	vector<int> acc_x(n + 1, 0), acc_y(n + 1, 0);

	for (int i = 0;i < n; i ++) {
		auto pair = mp[s[i]];
		int dx = pair.first;
		int dy = pair.second;
		acc_x[i + 1] = acc_x[i] + dx;
		acc_y[i + 1] = acc_y[i] + dy;
	}

	auto check = [&] (int l, int r) -> bool {
		return abs(acc_x[l] + acc_x[n] - acc_x[r] - ex) + abs(acc_y[l] + acc_y[n] - acc_y[r] - ey) > r -l;

	};

	int l = 0, r = 0, ans = n + 1;

	while(l <= n ) {
		while(r  < n && check(l, r)) r ++;
		if (check(l, r)) break;
		ans = min(ans, r - l);
		l ++;
	}

	cout<<ans;
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