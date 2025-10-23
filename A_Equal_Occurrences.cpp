#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vll vector<long long> 
#define pub push_back 
#define pop pop_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        ll n,count = 0;
        cin >> n;
        map<ll,ll>mp;set<ll>s;
        fl(i,0,n){
            ll x;
            cin >> x;
            s.insert(x);
            mp[x] ++;
        }
        ll ans = 0;
        auto i = s.begin();
        for (int j = 0; j < s.size(); j++){
            ll q = *i++;
            ll u = mp[q];
            count = 0;
            for(auto it : mp){
                if(it.second >= u){
                    count ++;
                }
            }
            ans = max(ans,count*u);
        }
        cout << ans << nl;
    }
    return 0;
}