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
    vll s(n),ans;
    map<int,int>mp;
    map<int,pair<int,int>>index;
    bool flag = true;
    ll start = 1,end = 0;
    fl(i,0,n){
        cin >> s[i];
        mp[s[i]]++;
        if(i > 0 && s[i] != s[i-1]){
            end = i;
            index[s[i-1]] = {start,end};
            start = end + 1;
        }
    }
    if(end != n){
        index[s[n-1]] = {start,n};
    }
    for(auto i:mp){
        if(i.second == 1){
            flag = false;break;
        }
        else{
            if(!index.empty()){
                ll sr = index[i.first].first;
                ll en = index[i.first].second;
                // cout << sr << en << " "; 
                ans.push_back(en );
                fl(j,sr,en){
                    ans.push_back(j);
                }
            }
            else{
                ll sr = 1;
                ll en = n;
                ans.push_back(en);
                fl(j,sr,en){
                    ans.push_back(j);
                }
            }
        }
    }
    if(flag == false){
        cout << -1 ;
    }
    else{
        fl(k,0,n){
            cout << ans[k] << " ";
        }
    }
    cout << nl;
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