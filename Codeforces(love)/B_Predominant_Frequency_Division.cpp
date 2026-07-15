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
void solve(){

    ll n;
    cin >> n;
    vll a(n),one(n,0),two(n,0),thr(n,0);
    ll c1=0,c2=0,c3=0;
    fl(i,0,n){
        cin >> a[i];
        if(a[i] == 1){
            c1++;
        }
        else if(a[i] == 2){
            c2++;
        }    
        else{
            c3++;
        }
        one[i] = c1;two[i] = c2;thr[i]=c3;

    }
    vll c;
    fl(i,0,n){
        if(one[i] >= two[i] + thr[i]){
            c.pub(i);
        }
        for(auto x:c){
            if(i != x && one[i] - one[x]+ two[i] -two[x] >= thr[i] - thr[x]){
                if(i == n-1){
                    continue;
                }
                else{
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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