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
// ll lcm(int a,int b){
//     ll gcd = __gcd(a,b);
//     ll cmm = (a*b)/gcd;
//     return cmm;
// }
int prime(ll n){
    for(int i=2;i*i <= n;i++){
        if(n%i == 0){
            return i;
        }
    }
    return 0;
}
void solve(){
    ll n;
    cin >> n;
    pair<int,int>p;
    if(n%2 == 0){
       p = {n/2,n/2};
    }
    else{
        ll x = prime(n);
        if(x == 0){
            p = {1,n-1};
        }
        else{
            ll a = n/x;
            ll b = n-a;
            p = {a,b};
        }
    }
    cout << p.F << " " << p.S << nl;
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