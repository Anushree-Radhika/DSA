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
    fl(i,0,n){
        cin >> a[i];
    }
    ll last = 0;
    if(a[0] == a[1] && a[0] == 1){
        cout << "NO" << nl;return;
    }
    fl(i,0,n-1){
        if(i == 0){
            last = a[i] - 1;
            a[i+1] += last;
            a[i] = 1;
        }
        else{
            last = a[i] - a[i-1] - 1;
            if(last < 0){
                cout << "NO" << nl;return;
            }
            a[i+1] += last;
            a[i] = a[i-1] + 1;
        }
    }
    fl(i,0,n-1){
        if(a[i] == a[i+1] || a[i] > a[i+1]){
            cout << "NO" << nl;return;
        }
    }
    cout << "YES" <<nl;
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