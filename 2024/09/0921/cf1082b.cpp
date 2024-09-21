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
	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = 0, cnt_g = 0, l = 0, r = 0, cnt = 0;

	while(l < n) {
		if(s[l] == 'G') cnt_g ++;

		while(r < n && cnt + (s[r] == 'S') <= 1){
			cnt += (s[r ++] == 'S');
		}

		ans = max(ans, r - l);
		cnt -= (s[l ++] == 'S');
	}

	cout << min(cnt_g, ans)<<endl;
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