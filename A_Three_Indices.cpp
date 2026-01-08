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
// continue;
//cout << 1 << " " << 1 << " " << n << " " << m ;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){

        ll n,i=0,fg = 0,idx = 0;
        cin >> n;
        vector<ll>p(n);
        fl(i,0,n){
            cin >> p[i];
        }

        while(i<n){
            if(p[i] < p[i+1]){
                idx = i;
                break;
            }
            i++;
        }
        if(i == n){
            cout << "NO" << endl;continue;
        }
        while(i<n-1){
            if(i+2 < n && p[i+1] > p[i+2]){
                cout << "YES" << endl;
                cout << idx+1 << " " << i+2 << " " << i+3 << endl;fg = -1;
                break;
            }
            i++;
        }
        if(fg != -1){
            cout << "NO" << endl;
        }
    }
    return 0;
}  