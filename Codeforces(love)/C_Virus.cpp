#include<bits/stdc++.h>
#include<numeric>
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
void solve() {

    ll n,m;
    cin >> n >> m;
    vll a(m,0);
    fl(i,0,m){
        cin >> a[i];
    }
    sort(all(a));
    vll gaps(m,0);
    fl(i,0,a.size()-1){
        gaps.pub(a[i+1] - a[i] - 1);
    }
    gaps.pub(n + a[0] - a[m-1] - 1);
    ll numSaved = 0, numDays = 0;
    sort(rall(gaps));
    for(auto gap : gaps){
        ll currGap = gap - numDays * 2;
        if (currGap > 0) {
            numSaved++;

            currGap -= 2;
            if (currGap > 0){
                numSaved += currGap;
            }

            numDays += 2;
        }
    }
    cout << (n - numSaved) << nl; 
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