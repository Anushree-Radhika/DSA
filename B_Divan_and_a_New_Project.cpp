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
// continue;
//cout << 1 << " " << 1 << " " << n << " " << m ;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
void solve(){

    ll n,x,ans = 0,j=0;
    bool fg = true;
    cin >> n;
    vector<pair<ll,ll>>a(n);
    vll as(n);
    fl(i,0,n){
        cin >> x;
        a[i] = {x,i};
    }
    ll snz = a.size(),sz= snz;
    if(snz%2){
        sz += 1;
    }
    snz /= 2,sz /=2; 
    sort(a.begin(),a.end());
    for(auto i:a){
        if(fg){
            as[i.S] = sz;
            fg = !fg;
            ans += 2*(i.F)*sz;
            sz--;
        }
        else{
            as[i.S] = -snz;
            fg = !fg;
            ans += 2*(i.F)*snz;
            snz--;
        }
    }
    cout << ans << nl << 0 << " ";
    fl(i,0,n){
        cout << as[i] << " ";
    }
    cout << nl;
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