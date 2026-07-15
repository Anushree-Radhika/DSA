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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0,cn = 0;
    fl(i,0,n){
        if(s[i] == '#'){
            cnt++;
        }
        else{
            cn = max(cn,cnt);
            cnt= 0;
        }
        //cout << cn << " ";
    }
    cn = max(cnt,cn);
    cout << (cn+1)/2 << nl;
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