#include<bits/stdc++.h>
#include<numeric>
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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
void solve(){

    ll n,x = 0,q, k =0;
    cin >> n >> q;
    vll sum(n),pm(n);
    fl(i,0,n){
        cin >> x;
        if(i == 0){
            sum[i] = x;
            pm[i] = x;
        }
        else{
            sum[i] = sum[i-1] + x;
            pm[i] = max(pm[i-1],x);
        }
    }
    fl(i,0,q){
        cin >> k;
        auto lim = upper_bound(all(pm),k);
        ll idx = distance(pm.begin(),lim) - 1;
        if (idx < 0) {
            cout << 0 << " ";
        } else {
            cout << sum[idx] << " ";
        }
    } 
    cout << nl;   
    return;
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