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

ll dp[3000][3000][2]; // dp[L][R][i] (array of segment [L,r] and ith player turn )
/*  
    maximise X-Y  ->
    X+Y = sum
    maximise X - (sum -X) - >  2*x -sum
    maximise X
*/

void solve()
{
    ll n , sum = 0;
    cin >>  n;
    vector<ll> arr(n);
    for (ll i = 0 ; i < n ; i++)
        cin >> arr[i] , sum += arr[i];


    for (ll i = 0 ; i < n ; i++)
        dp[i][i][0] = arr[i] , dp[i][i][1] = 0;
    /*
    R>L
    R-L (diff) is increasing
    */

    for (ll diff = 1 ; diff < n ; diff++)
    {
        for (ll L = 0 ;  diff + L < n ; L++)  // increasing lengths of segments
        {
            ll R = diff + L ;
            dp[L][R][0] = max(arr[L] + dp[L + 1][R][1] , arr[R] + dp[L][R - 1][1]);
            dp[L][R][1] = min(dp[L + 1][R][0] , dp[L][R - 1][0]);

        }
    }

    ll x  = dp[0][n - 1][0] ;
    ll ans  = (2 * x) - sum ;

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

