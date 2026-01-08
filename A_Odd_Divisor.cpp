#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define pub push_back 
#define pop pop_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"
#define input(x,v) for(auto &x:v)cin>>x;
// continue
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){

        ll n,cp,fg =0;
        cin >> n;cp = n;
        if(n%2 == 1){
            cout << "YES" << nl;continue;
        }
        else{
            while(cp != 0){
                cp = cp/2;
                if(cp != 1 && cp%2 == 1){
                    fg= 1;
                    cout << "YES" << nl;break;
                }

            }
            
        }
        if(fg == 0){
            cout << "NO" << nl;
        }
    }
    return 0;
}


    