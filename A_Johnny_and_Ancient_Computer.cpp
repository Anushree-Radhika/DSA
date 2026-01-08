#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
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
const ll MOD = 1e9 + 7;


void solve(){

    ll a,b,ans = 0;
    cin >> a >> b;
    if(a>b){
        swap(a,b);
    }
    ll nm = 1;
    if(a!=b){
        nm = b%a;
        if(nm != 0){
            cout << -1 << nl;
            return;
        }
        nm = b/a;
        while(nm!=1){
            if(nm%2 == 1){
                cout << -1 << nl;
                return;
            }
            nm/=2;
            ans ++;
        }
        if(ans > 3){
            nm = ans/3; 
            if(ans % 3 > 0){
                nm += 1;
            }
        }
        else{
            cout << 1 << nl;
            return;
        }
        cout << nm << nl;
    }
    else{
        cout << 0 << nl;
    } 
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