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
void solve(){

    ll n,a,b;
    cin >> n >> a >> b;

    if(n%2){
        if(a%2 && b%2){
            cout << "YES" << nl;
        }
        else if(b>a && b%2){
            cout << "YES" << nl;
        }
        else{
            cout << "NO" << nl;
        }
    }
    else{
        if(a%2 == 0 && b%2 == 0){
            cout << "YES\n";
        }
        else if(b>a && b%2 ==0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
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