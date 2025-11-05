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

        ll x,y,z;
        cin >> x >> y >> z;
        
        ll ac = x & y,ba = y & z,cb = z & x;
        if((ac == ba) && (ac == cb) && (ba == cb)){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }       
    }
    return 0;
}