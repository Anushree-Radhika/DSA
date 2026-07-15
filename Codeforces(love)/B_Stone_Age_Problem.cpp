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
ll calsum(ll sum){

}
void solve(){
 
    ll n,q;
    cin >> n >> q;
    vll a(n);
    ll sum = 0;
    fl(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
   
    ll z,i,x,num = -1;

    map<ll,ll>qu;
    fl(k,0,q){
        cin >> z;
        if(z == 1){
            cin >> i >> x;
            if(qu.find(i) == qu.end()){
                if(num != -1){
                    sum -= num;
                    qu[i]++;
                }
                else{
                    sum -= a[i-1];
                }
            }
            else{
                sum -= a[i-1];
            }
            a[i-1] = x;
            sum += x;
        }
        else{
            cin >> x;
            sum = n*x;
            num = x;
            qu.clear();
        }
        cout << sum << nl;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
    return 0;
}