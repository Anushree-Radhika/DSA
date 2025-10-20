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
    int t;
    cin >> t;
    while(t--){
        ll n ,xo = 0;
        cin >> n;
        vll a(n);
        fl(i,0,n){
            cin >> a[i];
            xo = xo ^ a[i];
        }
        if(xo == 0){
            cout << 1 << nl;
            cout << 1 << " " << n << nl;

        }
        else if(n % 2 == 0){
            cout << 2 << nl;
            cout << 1 << " " << n << nl;
            cout << 1 << " " << n << nl;
        }
        else{
            cout << 4 << nl;
            cout << 1 << " " << n-1 << nl;
            cout << 1 << " " << n-1 << nl;
            cout << n-1 << " " << n << nl;
            cout << n-1 << " " << n << nl;
        }
    }
    return 0;
}