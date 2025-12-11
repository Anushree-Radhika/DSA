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

    ll n;
    cin >> n;
    map<int,int>mp,p;
    fl(i,0,n){
        int z;
        cin >> z;
        p[i] = z;
    }
    string x;
    cin >> x;

    ll c = 0;
    fl(i,0,x.size()){
        if(x[i] == '1'){
            c++;
            mp[i] = c;
        }
    }

    bool ans = true;
    for(auto it:mp){
        int a = it.F;
        if(a == 0 || a == n-1){
            ans = false;
            break;
        }
        ll f1 = 0,f2 = 0;
        fl(i,0,a){
            if(p[i] < p[a]){
                f1 = 1;
            }
        }
        fl(i,a,n){
            if(p[i] > p[a]){
                f2 = 1;
            }
        }
        if(f1 != 1 || f2 != 1){
            ans  = false;
            break;
        }
    }
    if(ans == true){
        cout << c << nl;
        for(int i=0;i<c;i++){
            if(n-1-i >= 0){
                cout << p[i] << " " << p[n-1-i] << nl ;
            }
        }
    }
    else{
        cout << -1 << nl;
    }
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