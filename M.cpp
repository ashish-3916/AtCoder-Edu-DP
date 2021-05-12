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

const int mod = 1e9 + 7;
long long add(long long a , long long b)
{
    long long ans = ((a % mod) + (b % mod)) % mod;
    if (ans < 0) ans += mod;
    return ans;
}
const int N  = 1e5 + 1;
int dp [100][N];

void solve()
{
    int n , k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];
    //  cout << findways(arr , n , k);
    // dp [ith position][k_candies] -> ways
    for (int i = 0 ; i < n  ; i++) // zero candies in n children
        dp[i][0] = 1 ;

    for (int c = 0 ; c <= arr[0] ; c++) // candies to first child
        dp[0][c] = 1;

    for (int i = 1 ; i < n; i++)
    {
        vector<int> prefix(k + 2); // 1 based prefix
        for (int j = 0; j <= k ; j++)
            prefix[j + 1] = add(prefix[j] , dp[i - 1][j]) ;

        for (int j = 1 ; j <= k ; j++)
            dp[i][j] = add(prefix[j + 1] , -1 * prefix[j - min(j, arr[i])] ); // 1 based prefix
        //dp[i][j] =  dp[i-1][j] + dp[i-1][j-1] + dp[ i-1][j-2] ......... dp[i-1][j - arr[i]] ;
    }

    cout << dp[n - 1][k] << endl;

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
int findways(int arr[] , int  n , int k )
{
    if (k == 0)
        return 1 ;
    if (n == 0)
        return k == 0;
    if (dp[n][k])
        return dp[n][k];

    int ans = 0 ;
    for (int i = 0 ; i <= arr[0] ; i++)
    {
        ans = add(ans, findways(arr + 1 , n - 1 ,  k - i ) );
    }
    return dp[n][k] = ans ;
}
*/
