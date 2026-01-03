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
const ll MOD = 1e9-1;
void solve(){

    ll n,c= 0;
    cin >> n;
    string s;
    cin >> s;
    ll flag = 0;
    fl(i,0,n){
        if(s[i] == '0'){
            c++;
        }
    }
    if(c == n){
        cout << 0 << nl;
        return;
    }
    ll ans = INT_MAX;
    fl(i,0,n-3){
        ll count = 0,c5 = 0;
        if(s[i] == '2'){
            count ++;
        }
        if(s[i+1] == '0'){
            count++;
        }
        if(s[i+2] == '2'){
            count++;
        }
        if(s[i+3] == '6'){
            count++;
        }
        if(s[i+3] == '5'){
            c5++;
        }
        if(count == 4){
            cout << 0 << nl;
            return;
        }
        else{
            if(count == 3 && c5 == 1){
                flag ++;
            }
            ans = min(ans ,4-count);
        }
    }
    if(flag == 0){
        cout << 0 << nl;
        return ;
    }
    cout << ans << nl;
    return;



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