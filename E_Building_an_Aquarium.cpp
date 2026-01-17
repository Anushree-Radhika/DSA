#include <bits/stdc++.h>
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
const ll INF = 2e18;
const ll MOD = 1e9 + 7;
int check(vll&a,ll mid){
    ll i = 0,n = a.size(),ans = 0;
    ll lb = 0,ub= n-1,mb=0;
    while(lb <= ub){
        mb = (lb) + (ub - lb)/2;
        if(a[mb] <= mid){
            ans = mb;
            lb += 1;
        }
        else{
            ub -= 1;
        }
    }
    return ans;
    

}
void solve(){

    ll n,x;
    cin >> n >> x;
    vll a(n),prefixsum(n);
    ll height = 0;
    map<ll,ll>mp;
    fl(i,0,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    fl(i,0,n){
        if(i>0){
            prefixsum[i] = prefixsum[i-1] + a[i];
        }
        else{
            prefixsum[i] = a[i];
        }
    }
    ll buck = n*a[n-1] - prefixsum[n-1],addressi = 0,addressj = n-1;
    if(x > buck){
        x -= buck;
        ll rem = x/n;
        height += rem + a[n-1];
    }
    else if(buck == x){
        height = a[n-1];
    }
    else{
        ll low = a[0],high = a[n-1];
        while(low <= high){
            ll mid = low + (high - low)/2;

            int m = check(a,mid);
            // cout << m << nl;
            if((m+1)*mid -prefixsum[m] <= x){
                height = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    cout << height << nl;
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
