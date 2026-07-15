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
void solve(){

    ll n;
    cin >> n;
    vll a(n),b(n);
    fl(i,0,n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(b));
    if(b == a){
        cout << 0 << nl;
        return;
    }
    if(a[n-2] > a[n-1] || a[n-1] < 0){
        cout << -1 << nl;
        return;
    }
    cout << n-2 <<nl;
    for(ll i = n-3;i>=0;i--){
        cout << i+1 << " " << n-1 << " " << n << nl;
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