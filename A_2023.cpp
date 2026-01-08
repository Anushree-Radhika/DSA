#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
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
 
    ll n,k;
    cin >> n >> k;
    vll b(n);
    ll mul =1;
    fl(i,0,n){
        cin >> b[i];
        mul = mul*b[i];
    }
    double q = (double)2023/(double)mul;
    if(ceil(q) == floor(q)){
        cout << "YES" << nl;
        k = k-1;
        cout << q << " ";
        while(k--){
            cout << 1 << " ";
        }
        cout << nl;
    }
    else{
        cout << "NO" << nl;
    }
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