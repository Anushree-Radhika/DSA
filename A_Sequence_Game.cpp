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

        ll n,flag =0;
        cin >> n;
        vll a(n);
        fl(i,0,n){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ll x;
        cin >> x;
        fl(i,0,n){
            if(x == a[i]){
                flag = 1;
                cout << "YES" << nl;
                break;
            }
        }
        if(flag == 0){
            if(x > a[0] && x < a[n-1]){
                cout << "YES" << nl;
            }
            else{
                cout << "NO" << nl;
            }
        }
    }
    return 0;
}