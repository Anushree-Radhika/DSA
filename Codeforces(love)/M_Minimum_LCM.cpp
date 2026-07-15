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
 
    ll n ,ans =INT_MAX;
    cin >> n;
    pair<int,int>a;
    if(n%2 == 0){
        cout << n/2 << " " << n/2 << nl;
    }
    else{
        for(ll i=1;i<n/2;i=i+2){
            if((n-i)%i == 0){
                ll x = (i*(n-i))/(__gcd(i,n-i));
                ans = min(ans,x);
                if(ans >= x){
                    a = {i,n-i};
                }
                else{
                    break;
                }
            }
        }
        cout << a.F << " " << a.S << nl;
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