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

void solve(){

    ll n,as = 1;
    cin >> n;
    vll b(n);
    fl(i,0,n){
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    ll last = b[0];
    fl(i,0,n){
        if(i>0 && (b[i] > last)){
            as++;
            last = b[i];
        }
    }
    cout << as << nl;
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