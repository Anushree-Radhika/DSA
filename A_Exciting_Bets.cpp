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
 
        ll a,b,c = 0,g = 0;
        cin >> a >> b;
        if(a == b){
            g = 0;
            c= 0;
        }
        else if(a> b){
            g = a - b;
            c = min(b%g , g - b%g);
        }
        else{
            g = b - a;
            c = min(a%g , g - a%g);
        }
        cout << g << " " << c << endl;
    }
    return 0;
}