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

void solve(){
 
    ll n;
    cin >> n;
    vector<ll>p;
    p.push_back(0);
    fl(i,1,n){
        ll x = ceil(log2(n));
        if(pow(2,i) == x){
            x+=1;
        }
        ll j = 0,num = 0,m = 1;
        while(j<x){
            int c = ((i >> j)&1);
            // cout << c << nl;
            int d = ((i >> j+1)&1);
            // cout << d << nl;
            num += m * (c^d);
            m *= 2;
            j++;
        }
        // cout << num << " ";
        p.push_back((num));
    }
    fl(i,0,p.size()){
        cout << p[i] << " ";
    }
    cout << nl;
}
