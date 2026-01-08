#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vll vector<long long> 
#define pub push_back 
#define pop pop_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"
 
void solve() {
   ll n;cin>>n;
   ll sum=0;
   ll cnt=0;
   vll a(n);
   fl(i,0,n){
    cin>>a[i];
    if(a[i]==0)cnt++;
    sum+=a[i];
   }
   
    cout<<sum+cnt<<nl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}