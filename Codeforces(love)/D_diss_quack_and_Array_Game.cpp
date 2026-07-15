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
void solve() {
    ll n;
    cin >> n;
    vll a(n,0);
    vll nume,numo;
    vll pr(100001,0);
    ll cnt = 0,ans = 0;
    fl(i,0,n){
        cin >> a[i];
        if(a[i] == 1){
            cnt++;
        }
        else if(a[i]%2 == 0){
            nume.pub(a[i]);
        }
        else{
            numo.pub(a[i]);
        }
    }
    pr[1] = 1,pr[1+1] = 2,pr[3] = 3;
    
    if(cnt >= 1){
        ans += cnt;
        ll d = 0;
        fl(i,0,nume.size()){

        }
    }
    else{
        if(numo.size() >= 1){

        }
    }


}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}