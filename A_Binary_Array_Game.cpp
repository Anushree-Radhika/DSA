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
const ll INF = 2e18;
const ll MOD = 1e9 + 7;
void solve(){
    ll n;
    cin >> n;
    vll a(n);
    ll c1 =0 ,c0 = 0;
    fl(i,0,n){
        cin >> a[i];
        if(a[i] == 1){
            c1++;
        }
        else{
            c0++;
        }
    }
    if(c1 >= c0){
        cout << "Alice" << nl;
    }
    else{
        cout << "Bob" << nl;
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
