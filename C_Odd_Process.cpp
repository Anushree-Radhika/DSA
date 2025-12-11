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
    vll od,ev,ans;
    ll total = 0;
    fl(i,0,n){
        ll x;
        cin >> x;
        total += x;
        if(x%2 == 1){
            od.pub(x);
        }
        else{
            ev.pub(x);
        }
    }
    ll odsz = od.size(),evsz = ev.size(),sum = 0,k = evsz,j = 0,cnt = 0;
    if(od.empty()){
        while(n--){
           cout << 0 << " ";
        }
        cout << nl;
        return;
    }
    sort(od.begin(),od.end(),greater<>());
    if(ev.empty()){
        ll flag = true;
        ll c = n-1;
        while(c >= 0 ){
            if(!flag){
                ans.pub(0);
            }
            else{
                ans.pub(od[j]);
            }
            c--;flag = !flag;
        }
        fl(i,0,n){
            cout << ans[i] << " ";
        }
        cout << nl;
        return;
    }
    sort(ev.begin(),ev.end(),greater<>());
    sum += od[0];cnt++;
    ans.pub(sum);j=0;
    while(k--){
        sum += ev[j];
        ans.pub(sum);
        j++;
        cnt++;
    }
    ll maxs= sum,maxse = sum - ev[evsz-1];
    k = n-cnt;bool flag = true;
    while(k > 1){
        if(flag){
            ans.pub(maxse);  
        }
        else{
            ans.pub(maxs);
        }
        cnt++;
        k--;
        flag = !flag;
    }
    if((total % 2) == 0){
        ans.pub(0);
    }
    else{
        ans.pub(maxs);
    }
    fl(i,0,n){
        cout << ans[i] << " ";
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