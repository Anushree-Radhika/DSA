#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
#define pub push_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"
#define input(x,v) for(auto &x:v)cin>>x;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
unordered_map<string,ll> s,s2;
unordered_map<string,ll> dp(string &a){
    if(a == ""){
        return s;
    }
    if(s.find(a) != s.end()){
        return s;
    }
    if(a.length() == 1){
        s[a]++;
        //cout << a<< nl; 
    }
    else{
        fl(i,0,a.length()-1){
            //cout << a << nl;
            s[a]++;
            string s1 = a.substr(0,i);
            string s2 = a.substr(i+2,a.length() - i+2);
            ll x = a[i] - '0',y = a[i+1] - '0';
            int z = ((x+y)%10);
            string nw = s1 + to_string(z) +  s2;
            // ll num = stoll(nw);
            // nw = to_string(num);
            //cout << nw <<nl;
            s = dp(nw);
        }
    }
    return s;
}
void solve(){

    string a,b;
    cin >> a >> b;
    unordered_map<string,ll>m,n;
    m = dp(a);
    s.clear();
    n = dp(b);
    s.clear();
    ll ans = 0;
    for(auto x:m){
        if(n.find(x.F) != n.end()){
            string zz = x.F;
            ll l = zz.length();
            ans = max(ans,l);
        }
        // cout << x.first << " ";
    }
    if(ans == 0){
        cout << -1 << nl;
        return;
    }
    cout << ans << nl;
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