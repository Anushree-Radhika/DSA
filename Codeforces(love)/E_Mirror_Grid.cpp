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

    ll n,ans = 0;
    cin >> n;
    string s = "";
    vector<string>a;
    for(ll i = 0;i<n;i++){
        cin >> s;
        a.pub(s);
    }
    for(ll i = 0;i<n/2;i++){
        for(ll j = 0;j<(n-2*i-1);j++){
            ll cnt0 = 0,cnt1 = 0;
            if(a[i][i+j] == '0'){
                cnt0 ++;
            }
            else{
                cnt1++;
            }
            if(a[n-1-i-j][i] == '0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
            if(a[i+j][n-1-i] == '0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
            if(a[n-1-i][n-1-i-j] == '1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
            ans += min(cnt0,cnt1);
        }
    }
    cout << ans << nl;
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