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

void solve()
{
	int n, m ;
	cin >> n >> m;
	vector< vector<int> > grid(m, vector<int>(n));
	for(int i = 0;i < m;i ++) {
		for(int j = 0;j < n;j ++) {
			cin >> grid[i][j];
		}
	} 

	int ans = 0, idx = 0;

	for(int i = 0; i < n - 1; i ++){
		vector<int> diff;
		for(int j = 0; j < m; j ++){
			diff.emplace_back(grid[j][n - 1] - grid[j][i]);
		}

		sort(diff.begin(),diff.end());

		int cur = 0;

		for(int j = 0; j < m; j ++) {
			
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