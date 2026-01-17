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
 
    ll n,k,count= 0;
    cin >> n >> k;
    if(n%2&& k%2){
        n = n-k;
        count++;
        count += n/(k-1);
        count += n%(k-1) == 0?0:1;
    }
    else if(n%2 && k%2 == 0){
        n = n-(k-1);
        count++;
        count += n/(k);
        count += n%(k) == 0?0:1;
    }
    else if(n%2 == 0 && k%2 == 0){
        count += n/k;
        n/=k;
        count +=  n%(k) == 0?0:1;
    }
    else{
        count++;
        count += n/(k-1);
        n/=(k-1);
        count +=  n%(k-1) == 0?0:1;
    }
    cout << count << nl;
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