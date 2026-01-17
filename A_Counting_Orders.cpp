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
// continue;
//cout << 1 << " " << 1 << " " << n << " " << m ;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
void solve(){
 
    ll n;
    cin >> n;
    vll a(n),b(n);
    fl(i,0,n){
        cin >> a[i];
    }
    fl(i,0,n){
        cin >> b[i];
    }
    ll ans=1,i=0,j=0,co=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(i<n){
        while(j<n && (a[i] > b[j])){
            co++;
            j++;
        }
        ans = (ans*co)%MOD;co--;
        if(co <0){
            cout << 0 << nl;
            return;
        }
        i++;
    }
    cout << ans%MOD << nl;
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