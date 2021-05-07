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
const int mod = 1e9 + 7;
long long add(long long a , long long b)
{
	long long ans = ((a % mod) + (b % mod)) % mod;
	return ans;
}


void solve()
{
	int n , m ;
	cin >> n >> m ;

	vector<vector<int>> arr(n + 1 , vector<int>(m + 1 , 1));

	char c ;
	for (int i = 0 ; i < n ; i++)
		for (int  j = 0 ; j < m ; j++)
		{
			cin >> c ;
			(c == '.') ? arr[i][j] = 0 : arr[i][j] = 1 ;
		}

	vector<vector<ll>> cost(n + 1 , vector<ll>(m + 1 ,  0));
	arr[n][m - 1] = 0;
	cost[n][m - 1] = 1;

	for (int i = n - 1 ; i >= 0  ; i--)
	{
		for (int j = m - 1 ; j >= 0 ; j-- )
		{
			if (!arr[i + 1][j])
				cost[i][j] = add(cost[i + 1][j] , cost[i][j]);
			if (!arr[i][j + 1])
				cost[i][j] = add(cost[i][j + 1] , cost[i][j]);
		}
	}

	cout << cost[0][0] << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}
