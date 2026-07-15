#include<bits/stdc++.h>
#include<numeric>
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
void solve() {

    ll n,s,sum = 0;
    cin >> n >> s;
    vll a(n),prefx(n,0);
    ll idx = -1;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        prefx[i] = sum;
        if(prefx[i] == s){
            idx = i;
        }
    }
    if(sum < s){
        cout << -1 << nl;
        return;
    }
    ll l = 0,r = idx,ans = idx+1;
    while(l<=r && r<n){
        if(prefx[r] - prefx[l] < s){
            r++;
        }
        else if(prefx[r] - prefx[l] == s){
            ans = max(ans,r-l);
            r++;
        }
        else{
            l++;
        }
    }
    cout << n - ans << nl;
    
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