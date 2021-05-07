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
ll dp[101][100001];
ll knapsack(vector< array<int , 2 > >&arr , int i , int  n , int W  )
{
	if (i == n or W == 0)
		return  0 ;

	if (dp[i][W])
		return dp[i][W];
	ll choice1 = 0 , choice2 = 0;
	if (arr[i][0] <= W) // take it
		choice1 = knapsack(arr, i + 1 , n , W - arr[i][0]) + arr[i][1];

	choice2 = knapsack(arr , i + 1 , n , W);

	return dp[i][W] = max(choice2, choice1) ;

}

void solve()
{
	int n  , w , a, b;
	cin >> n >> w ;
	vector< array<int , 2 > >  arr (n);
	for (int i = 0 ; i < n ; i++)
	{
		cin >> a >> b ;
		arr[i] = {a, b};
	}

	ll res = knapsack(arr, 0, n , w);
	cout << res << endl ;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}
