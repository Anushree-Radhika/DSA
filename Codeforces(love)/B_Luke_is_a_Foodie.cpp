#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
#define pub push_back 
// #define pop pop_back 
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

    ll n,x;
    cin >> n >> x;
    vector<ll>a(n,0);
    fl(i,0,n){
        cin >> a[i];
    }
    stack<ll>mn,mx;
    ll j=0,k=0,cnt = 0;
    ll fg1 = 0,fg2 = 0;
    mn.push(a[0]);mx.push(a[0]);
    fl(i,1,n){
        fg1 = 0,fg2 = 0;
        if(!mn.empty()){
            j = abs(a[i] - mn.top());
            if(a[i] < mn.top()){
                mn.pop();
                mn.push(a[i]);
                fg1 = 1;
            }
        }
        if(!mx.empty()){
            k = abs(a[i] - mx.top());
            if(a[i] > mx.top()){
                mx.pop();
                mx.push(a[i]);
                fg2 = 1;
            }
        }
        if((j > (2*x)) || (k > (2*x))){
            cnt ++;
            if(fg2 == 1){
                mn.pop();
                mn.push(a[i]);
            }
            if(fg1 == 1){
                mx.pop();
                mx.push(a[i]);
            }
        }
    }
    cout << cnt << nl;
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
