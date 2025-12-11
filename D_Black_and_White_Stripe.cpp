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

    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll i=0,j=0;
    ll blk = 0,ans = INT_MAX;
    while(j<n){
        if(s[j] == 'B'){
            blk++;
        }
        if(j-i+1 == k){
            ans = min(k-blk,ans);
            if(s[i] == 'B'){
                blk--;
            }
            i++;
        }
        j++;
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