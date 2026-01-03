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
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){
 
        ll n,ev=0,od =0,mno = INT_MAX,mne = INT_MAX,flg =0;
        cin >> n;
        vll a(n);
        fl(i,0,n){
            cin >> a[i];
        }
        ll total_and = a[0];
        fl(i,1,n){
            total_and &= a[i]; 
        }
        cout <<total_and << nl;
    }
    return 0;
}