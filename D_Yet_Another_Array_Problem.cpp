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

        ll n;
        cin >> n ;
        vll a(n);
        fl(i,0,n){
            cin >> a[i];
        }
        ll flag = 0;
        vll primes ;
        for(ll i =2;i*i <= pow(10,18);i++){
            for(int j = 0;j<n;j++){
                int x = __gcd(i,a[j]);
                if(x == 1){
                    cout << i <<nl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }
    }  
    return 0;
}