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
void solve() {

    ll n,count = 0;
    cin >> n;
    vll x(n,0),y(n,0);
    fl(i,0,n){
        cin >> x[i];
    }
    fl(i,0,n){
        cin >> y[i];
    }

    multiset<ll>num;
    fl(i,0,n){
        num.insert(y[i] - x[i]);
    }
    while (num.size() > 1)
    {
        int val1 = *num.begin();
        num.erase(num.begin());

        auto it = num.lower_bound(-val1);

        if (it == num.end())
            continue;

        count++;
        num.erase(it);
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