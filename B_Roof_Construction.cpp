#include<bits/stdc++.h>
#include<numeric>
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

void solve(){
 
    ll n;
    cin >> n;
    vector<ll>p;
    ll po = log2(n);
    // cout << po << nl;
    ll i = n-1,in = 0;
    if(n == pow(2,po)){
        for(i = n-1;i>=0;i--){
            if(((i >> po-1)&1) == 1){
                p.pub(i);
            }
            else{
                in = i;
                break;
            }
        }
        for(i = 0;i <= in;i++){
            p.pub(i);
        }
    }
    else{
        for(i = n-1;i>=0;i--){
            if(((i >> po)&1) == 1){\
                p.pub(i);
            }
            else{
                in = i;
                break;
            }
        }
        for(i = 0;i <= in;i++){
            p.pub(i);
        }
    }
    fl(i,0,p.size()){
        cout << p[i] << " ";
    }
    cout << nl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
