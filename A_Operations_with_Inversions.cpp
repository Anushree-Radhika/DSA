#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define pub push_back 
// #define pop pop_back 
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
    ll cnt = 0;
    ll an[n];
    stack<ll>a;
    fl(i,0,n){
        cin >> an[i];
    }
    fl(i,0,n){
        if(a.empty()){
            a.push(an[i]);
        }
        else{
            if(a.top() > an[i]){
                cnt++;
            }
            else{
                a.push(an[i]);
            }
        }
    }
    cout << cnt << nl;
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
