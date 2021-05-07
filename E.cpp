#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ASHISH_DANGI
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// idea is we find min weight if we take  x items and possible cost y
void solve()
{
	int n , w ;
	cin >> n >> w ;
	int a , b;
	vector< array < int  , 2 >  > arr(n); // wieght value
	for (int i = 0 ; i < n ; i++)
		cin >> a >> b  , arr[i] = {a , b} ;

	// max val we can attain is N*V = 1e5 (in worst case); (sum of all values )

	vector<vector<ll>> dp(n + 1, vector<ll>(100001, INT_MAX)) ;

	for (int i = 0 ; i <= n ; i++)
	{
		dp[i][0] = 0;
		if (i == 0)continue;
		for (int v = 1 ; v <= 100000 ; v++)
		{
			if (arr[i - 1][1] <= v )
				dp[i][v] = min(dp[i - 1][v] , dp[i - 1][v - arr[i - 1][1]] + arr[i - 1][0] ) ;
			else
				dp[i][v] = dp[i - 1][v];
		}
	}


	ll ans ;
	for (int i = 100000 ; i >= 0 ; i--)
	{
		if (dp[n][i] <= w)
		{
			ans = i ;
			break;
		}
	}
	cout << ans << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}
