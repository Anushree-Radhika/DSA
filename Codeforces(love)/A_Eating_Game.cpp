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
    ll n;
    cin >> n;
    vll a(n);
    vll xx;
    ll mx = INT_MIN,idx = -1;
    fl(i,0,n){
        cin >> a[i];
        if(mx < a[i]){
            mx = a[i];
            idx = i+1;
            xx = {};
            xx.pub(i+1);
        }
        else if(mx == a[i]){
            xx.pub(i+1);
        }
    }
    cout << xx.size() << nl;
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