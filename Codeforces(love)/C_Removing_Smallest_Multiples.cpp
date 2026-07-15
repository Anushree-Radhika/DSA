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
ll prime(ll p){
    for(ll i = 2;i<=sqrt(p);i++){
        if(p%2 == 0){
            return i;
        }
    }
    return 0;
}
void solve() {

    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll sum = 0;
    vll vis(n+1,0);
    fl(i,0,n){
        if(s[i] == '0'){
            if(vis[i+1] == 1){
                for(auto x = 2*(i+1);x <= n;x += i+1){
                    if(vis[x] != 1 && s[x-1] == '0'){
                        sum += i+1;
                        vis[x] = 1;
                    }
                    else{
                        if(s[x-1] == '0'){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
            else{
                sum += i+1;
                for(auto x = 2*(i+1);x <= n;x += i+1){
                    if(vis[x] != 1 && s[x-1] == '0'){
                        sum += i+1;
                        vis[x] = 1;
                    }
                    else{
                        if(s[x-1] == '0'){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << sum << nl;
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