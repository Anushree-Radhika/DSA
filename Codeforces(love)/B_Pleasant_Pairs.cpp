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
    ll n,x;
    cin >> n;
    vpll a;
    fl(i,0,n){
        cin >> x;
        a.pub({x,i+1});
    }
    sort(all(a));
    ll cnt = 0,l = 0,r = n-1;
    while(l<r && (a[l].F*a[r].F > 2*n)){
        r--;
    }
    fl(i,l,r+1){
        fl(j,i+1,r+1){
            if((a[i].F*a[j].F) == (a[i].S+a[j].S)){
                cnt++;
            }
            if(a[i].F*a[j].F > 2*n){
                break;
            }
        }
    }
    cout << cnt << nl;
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