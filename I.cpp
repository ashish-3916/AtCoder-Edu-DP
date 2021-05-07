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

void solve()
{
	int n ;
	cin >> n ;
	vector<double> head(n + 1) , tail(n + 1);

	for (int i = 1 ; i <= n ; i++)
		cin >> head[i] , tail[i] = 1 - head[i];

	vector<vector<double>>dp (n + 1, vector<double>(n + 1, 0));
	//dp[coin][head_count];
	dp[0][0] = 1 ;

	// if we have some coins probab of 0 head_count = all tails ;
	for (int i = 1 ; i <= n ; i++)
		dp[i][0] = dp[i - 1][0] * tail[i];

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= i ; j++)
		{
			// take as head
			dp[i][j] += head[i] * dp[i - 1][j - 1];
			// take a tail
			dp[i][j] += tail[i] * dp[i - 1][j];
		}
	}
	// atleast n/2+1 heads;
	double ans = 0;
	for (int j = n; j >= n / 2 + 1 ; j--)
		ans += dp[n][j];

	cout << fixed << setprecision(10) << ans << endl;

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

/*
double  prob ( double * head , double * tail , int n , int cnt)
{
	if (n == 0)
		return {1} ;

	if (cnt == n)
	{
		double ans = 1;
		for (int i = 0 ; i < n ; i++)
			ans *= head[i] ;
		return ans;
	}

	double ans1 =  prob(head + 1 , tail + 1 , n - 1 , cnt - 1); // head

	double ans2 = prob(head + 1 , tail + 1, n - 1 , cnt); // tail

	double ans  =  head[0] * ans1 + tail[0] * ans2;

	return ans ;
}
void solve()
{
	int n ;
	cin >>  n ;
	double head[n], tail [n] ;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> head[i];
		tail[i] = 1 - head[i];
	}
	double res  = prob(head , tail , n , n / 2 + 1) ;
	cout << fixed << setprecision(9) << res << endl;
}
*/
