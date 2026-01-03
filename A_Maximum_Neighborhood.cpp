#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define pub push_back 
#define pop pop_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"
#define input(x,v) for(auto &x:v)cin>>x;
// continue;
//cout << 1 << " " << 1 << " " << n << " " << m ;
const ll INF = 1e18;
const ll MOD = 1e9-1;
void solve(){
    ll n;
    cin >> n;
    ll term1 = n*n,ans = 0;
    ll term2 = n*n-1;
    if(n == 1){
        cout << 1 << nl;
        return;
    }
    if(n == 2){
        cout << 9 << nl;
        return;
    }
    ans = max(2*term1 + term2 - n,4*term2-n);
    ans = max(ans,5*term2-5*n);
    cout << ans << nl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}