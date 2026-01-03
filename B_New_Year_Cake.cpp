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
ll layers(ll a,ll b){
    ll count = 0;
    ll expb = 2,expa = 1;
    while(a >= expa && b >= expb ){\
        count++;
        a -= expa;
        expa*= 4;
        count++;
        b -= expb;
        expb*=4;
    }
    if(a >= expa){
        count++;
        a -= expa;
        expa*= 4;
    }
    return count;
}
void solve(){

    ll a,b;
    cin >> a >> b;
    ll ac = a, bc = b;
    ll f = layers(a,b);
    ll s = layers(bc,ac);
    cout << max(f,s) << nl;
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