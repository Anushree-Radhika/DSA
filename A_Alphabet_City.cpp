#include <bits/stdc++.h>
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
ll checkValid(map<char,ll>&mp,ll m,map<char,ll>&countchar){
    ll ans =INT_MAX;
    for(auto i : mp){
        ll total = countchar[i.F];
        ll need = i.S;
        cout << total << need ;
        if (total * m < need * (m + 1))
            return -1;
        
        ll extra = (total * m) - (need * (m + 1));
        ans = min(ans, extra / 2);
    }
    return ans;
}
void solve(){

    ll n,m;
    cin >> n >> m;
    vector<string>s(n);
    map<char,ll>countchar;
    fl(i,0,n){
        cin >> s[i];
        fl(j,0,s[i].length()){
            countchar[s[i][j]]++;
            cout << countchar[s[i][j]] << " ";
        }
    }
    for(int i=0;i<s.size();i++){
        map<char,ll>mp;
        string st = s[i];
        fl(j,0,st.length()){
            mp[st[j]]++;
        }
        ll ans = checkValid(mp,m,countchar);
        // cout << ans << " ";
    }
    cout << nl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // while (t--)
    // {
        solve();
    // }
    return 0;
}