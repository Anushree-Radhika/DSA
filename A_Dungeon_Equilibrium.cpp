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
    map<ll,ll>mp;
    fl(i,0,n){
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll count = 0;
    for(auto i:mp){
        if(i.F == i.S){
            continue;
        }
        else{
            if(i.F > i.S){
                count += i.S;
            }
            else{
                count += i.S-i.F;
            }
        }
    }
    cout << count << nl;
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