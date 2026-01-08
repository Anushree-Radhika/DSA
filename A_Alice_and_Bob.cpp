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

    ll n,a,count = 0,less = 0,big=0;
    cin >> n >> a;
    vll v(n);
    fl(i,0,n){
        cin >> v[i];
        if(v[i] > a){
            big++;
        }
        else if(v[i] == a){
            count++;
        }
        else{
            less++;
        }
    }
    ll b = 0;
    if(less < big){
        b = a+1;
    }
    else {
        b = a-1;
    }
    cout << b << nl;
    return;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}