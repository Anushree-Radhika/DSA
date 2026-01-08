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
ll median(int g,int c,int l){
    ll ans = 0;
    if(g > c && g > l){
       ans =  c > l?c :l;
    }
    else if(c > l && c > g){
        ans = l>g?l:g;
    }
    else{
        ans = g>c?g:c;
    }
    return ans;
}
void solve(){

    ll g,c,l;
    cin >> g >> c >> l;
    ll mx = 0,medi=0,mn = 0;
    mx = max(max(g,c),l);
    mn = min(min(g,c),l);
    if(mx-mn >= 10){
        cout << "check again" << nl;
    }
    else{
        medi = median(g,c,l);
        cout << "final " << medi << nl;
    }
    return;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
    return 0;
}