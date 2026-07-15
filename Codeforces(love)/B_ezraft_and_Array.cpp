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
  if(n == 1){
    cout << 1 << nl;return;
  }
  else if(n == 2){
    cout << -1 << nl;return;
  }
  else if(n == 3){
    cout << 1 << " " << 2 << " " << 3 << nl;return;
  }
  else{
    cout << 1 << " " << 2 << " " << 3 << " ";
  }
  a[0] =1,a[1] = 2,a[2] = 3;
  fl(i,3,n){
    a[i] = 2*a[i-1];
    cout << a[i] << " ";
  }
  cout << nl;

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