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
ll presum[150005];
void solve(){

    ll n,sum = 0,ans = 0,mx1 =-INF,mn1 = INF;
    cin >> n;
    vll div;
    if(n == 1){
        cout << 0 << nl;return;
    }
    fl(i,0,n){
        ll  x;
        cin >> x;
        if(i==0){
            presum[0] = x;
        }
        else{
            presum[i] = presum[i-1] + x;
            if(n%i == 0){
                div.pub(i);
            }
        }
        mx1 = max(mx1,x);mn1 = min(mn1,x);
    }
    ans = max(ans,mx1-mn1);
    for(auto i:div){
        if(n%i == 0){
            ll j = i,mx1 =-INF,mn1 = INF,last = 0;
            while(j<=n){
                mx1 = max(mx1,presum[j-1] - last);
                mn1 = min(mn1,presum[j-1] - last);
                last = presum[j-1];
                j+=i;
            }
            ans = max(ans,mx1-mn1);
            // cout << ans << nl;
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
