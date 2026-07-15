#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
#define pub push_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"
#define input(x,v) for(auto &x:v)cin>>x;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
ll ask(ll prf,ll n,ll an,ll x){
    ll m = x- (prf+(n*an));
    if(m >= 0){
        return m/n + 1;
    }
    return 0;
}
void solve(){

    ll n,x;
    cin >> n >> x;
    vll a(n),prefx(n,0);
    ll sum = 0;
    fl(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    fl(i,0,n){
        if(i == 0){
            prefx[i] = a[i];
        }
        else{
            prefx[i] = prefx[i-1] + a[i];
        }
    }
    ll l = 0,r = n-1,an = 0,ans = 0,add = 0,m=0,ac=0;
    for(ll i = n-1;i>=0;i--){
        ll c = ask(prefx[i],i+1,ans,x);
        ans += c;
        ac+= (i+1)*c;
    }
    cout << ac << nl;
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