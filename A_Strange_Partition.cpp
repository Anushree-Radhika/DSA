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

        ll n,x,count=0;
        cin >> n >> x;
        vll a(n);
        ll sum = 0,maxsum =0,dom = 0;
        vector<pair<ll ,ll>>mp;
        fl(i,0,n){
            cin >> a[i];
            maxsum += ceil((double)a[i]/x);
            sum += a[i];
        }
        dom = ceil((double)sum / x);

        cout << dom << " " << maxsum << nl;
    }
    return 0;
}  