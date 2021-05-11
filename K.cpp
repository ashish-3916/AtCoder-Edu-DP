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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int K = 1e5 + 1;
int dp[K][2];
void solve()
{
	int n , k ;
	cin >> n >> k ;
	int arr[n];

	for (int i = 0; i < n ; i++) cin >> arr[i];

	// dp[remainng_stones][player_to_start] = winner
	dp[0][1] = 0;
	dp[0][0] = 1;

	for (int i = 1 ; i <= k ; i++)
	{
		for (int j = 0; j < 2 ; j++)
		{	bool check = false;
			for (int idx = 0 ; idx < n ; idx++)
			{
				if (arr[idx] <= i)
				{	if (dp[i - arr[idx]][j ^ 1] == j)
					{
						dp[i][j] = j;
						check = true;
						break;
					}
				}
			}
			if (!check)
				dp[i][j] = j ^ 1;

		}
	}

	int winner = dp[k][0];
	if (winner == 0)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
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
const int K = 1e5 + 1;
int dp[K][2];
int game(int arr[] , int n , int k , int player)
{
    for (int i = 0 ; i < n ; i++)
    {
        if (arr[i] <= k)
        {   int winner ;
            if (dp[k - arr[i]][player ^ 1] != -1)
                winner = dp[k - arr[i]][player ^ 1] ;
            else
            {
                winner = dp[k - arr[i]][player ^ 1] = game(arr , n , k - arr[i] , player ^ 1);
            }
            if (winner == player)
                return player;
        }
    }
    return dp[k][player] = player ^ 1;
}
*/
