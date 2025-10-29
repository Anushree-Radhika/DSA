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

        ll n,ceven = 0,codd = 0,flag = 0;
        cin >> n ;
        vll a(n);
        fl(i,0,n){
            cin >> a[i];
            if(a[i] % 2 != 0){
                codd ++;
            }
            else {
                ceven ++;
            }
        }
        if(codd == n || ceven == n){
            flag = 1;
        }
        if(flag == 1){
            fl(i,0,n){
                cout << a[i] << " ";
            }
            cout << nl;
        }
        else {
            sort(a.begin(),a.end());
            fl(i,0,n){
                cout << a[i] << " ";
            }
            cout << nl;

        }
    }
    return 0;
}