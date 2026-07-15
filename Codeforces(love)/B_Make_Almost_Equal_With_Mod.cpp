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
    vll a(n);
    ll even = 0,odd = 0,mx = INT_MIN;
    fl(i,0,n){
        cin >> a[i];
        if(a[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
        mx = max(mx,a[i]);
    }
    ll lg = log2(mx);
    if(odd >= 1 && even >= 1){
        cout << 2 << nl;
        return;
    }
    else{
        ll x = 4;
        // cout << lg << nl;
        while(x <= mx){
            map<ll,ll>mp;
            fl(i,0,n){
                mp[a[i]%x]++;
                // cout <<x << " " << mp.size() << " "<< nl;
            }
            if(mp.size()==2){
                cout << x << nl;
                return;
            }
            x*=2;
        }
    }
    sort(all(a));
    cout << a[n/2] << nl;
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