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

    ll n,r,b;
    cin >> n >> r >> b;
    ll slots = (b+1),fill = r/slots,extra = r%slots,cp = fill,cn = 0;
    string s = "",str = "";
    while(fill--){
        str += 'R';
    }
    while(cn < n){
        if(extra > 0){
            s += 'R';extra--;cn++;
        }
        s += str;
        if(b>0){
            s += 'B';
            b--;
        }
        cn += cp + 1;
    }
    cout << s << nl;
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