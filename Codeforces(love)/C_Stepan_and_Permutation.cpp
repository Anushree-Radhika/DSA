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
    ll n,x,y;
    cin >> n >> x >> y;
    vll p(n);
    fl(i,0,n){
        cin >> p[i];
    }
    fl(i,0,n){
        ll nm = p[i] - i - 1;
        nm = abs(nm);
        if(x-y != 0){
            if((nm%x == 0)||(nm%y == 0)||(nm%(x+y) == 0)){
                continue;
            }
            else if((nm%(abs(x-y)) == 0)){
                ll q = nm/(abs(x-y)) ;
                if(x > y){
                    if(q*x >= n || q*y < 0){
                        cout << "NO" <<nl;
                        return;
                    }
                }
                else{
                    if(q*x < 0 || q*y >= n){
                        cout << "NO" <<nl;
                        return;
                    }
                }
            }
            else{
                cout << "NO" << nl;
                return;
            }
        }
        else{
            if(nm%x == 0){
                continue;
            }
            else{
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;
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