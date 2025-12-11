// #include<bits/stdc++.h>
// #include<numeric>
// using namespace std;
// #define F first
// #define S second 
// #define ll long long 
// #define vll vector<long long> 
// #define vpll vector<pair<ll,ll>>
// #define pub push_back 
// #define pop pop_back 
// #define all(v) (v).begin(), (v).end()
// #define rall(v) (v).rbegin(), (v).rend()
// #define fl(i,x,n) for (ll i = x; i < n; i++)
// #define nl "\n"
// #define input(x,v) for(auto &x:v)cin>>x;
// // continue;
// //cout << 1 << " " << 1 << " " << n << " " << m ;
// const ll INF = 1e18;
// const ll MOD = 1e9 + 7;

// double area(vector<pair<ll,ll>>coordinate){
//     ll x[3],y[3];
//     ll j = 0;
//     for(auto i:coordinate){
//         x[j] = i.first;
//         y[j] = i.S;
//         j++;
//     }
//     double r = (abs((x[0]*(y[1] - y[2])) + (y[0]*(x[2] - x[1])) + x[1]*y[2] - x[2]*y[1]));
//     return r;
// }

// void areeea(vpll a,ll &maxarea,vpll coord){
//     for(auto i:a){
//         coord.pub(i);
//         ll are = area(coord);
//         maxarea = max(maxarea,are);
//         coord.pop();
//     }   
// }

// void allpossible(vpll f1,vpll f2,vpll f3,vpll f4,ll &maxarea,vpll coord){
//     for(ll i=0;i<f1.size()-1;i++){
//         for(ll j = i+1;j<f1.size();j++){
//             coord.pub(f1[i]);
//             coord.pub(f1[j]);
//             areeea(f2,maxarea,coord);
//             areeea(f3,maxarea,coord);
//             areeea(f4,maxarea,coord);
//             coord.clear();
//         }
//     }
// }
// void solve(){
//     ll w,h;
//     cin >> w >> h;
//     vector<pair<ll,ll>> x0,xh,y0,yw;
//     ll k1,k2,k3,k4;
//     cin >> k1;
//     fl(i,0,k1){
//         ll a;
//         cin >> a;
//         x0.pub({a,0});
//     }
//     cin >> k2;
//     fl(i,0,k2){
//         ll a;
//         cin >> a;
//         xh.pub({a,h});
//     }
//     cin >> k3;
//     fl(i,0,k3){
//         ll a;
//         cin >> a;
//         y0.pub({0,a});
//     }
//     cin >> k4;
//     fl(i,0,k4){
//         ll a;
//         cin >> a;
//         yw.pub({w,a});
//     }
//     1st horizontal bar;
//     vector<pair<ll,ll>> coord;
//     ll maxarea = 0;
//     allpossible(x0,xh,y0,yw,maxarea,coord);
//     coord.clear();
//     // 2nd horizontal bar;
//     allpossible(xh,x0,y0,yw,maxarea,coord);
//     coord.clear();
//     // 1st verticl line
//     allpossible(y0,x0,xh,yw,maxarea,coord);
//     coord.clear();
//     // 2nd vertical line
//     allpossible(yw,x0,y0,xh,maxarea,coord);
//     coord.clear();
//     cout << maxarea << nl;
// }
// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#include<numeric>
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
double area(vector<pair<ll,ll>>coordinate){
    ll x[3],y[3];
    ll j = 0;
    for(auto i:coordinate){
        x[j] = i.first;
        y[j] = i.S;
        j++;
    }
    double r = (abs((x[0]*(y[1] - y[2])) + (y[0]*(x[2] - x[1])) + x[1]*y[2] - x[2]*y[1]));
    return r;
}
void solve(){
 
    ll w,h;
    cin >> w >> h;
    vector<pair<ll,ll>> x0,xh,y0,yw;
    ll k1,k2,k3,k4;
    cin >> k1;
    fl(i,0,k1){
        ll a;
        cin >> a;
        x0.pub({a,0});
    }
    cin >> k2;
    fl(i,0,k2){
        ll a;
        cin >> a;
        xh.pub({a,h});
    }
    cin >> k3;
    fl(i,0,k3){
        ll a;
        cin >> a;
        y0.pub({0,a});
    }
    cin >> k4;
    fl(i,0,k4){
        ll a;
        cin >> a;
        yw.pub({w,a});
    }
    // 1st horizontal bar;
    vector<pair<ll,ll>> coord;
    ll maxarea = 0,are=0;
    coord.pub(x0.front());
    coord.pub(x0.back());
    for(auto i:y0){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:yw){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:xh){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    coord.clear();
    // 2nd horizontal bar;
    coord.pub(xh.front());
    coord.pub(xh.back());
    for(auto i:y0){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:yw){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:x0){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    coord.clear();
    // 1st verticl line
    coord.pub(y0.front());
    coord.pub(y0.back());
        for(auto i:x0){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:yw){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:xh){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    coord.clear();
    // 2nd vertical line
    coord.pub(yw.front());
    coord.pub(yw.back());
    for(auto i:y0){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:x0){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    for(auto i:xh){
        coord.pub(i);
        are = area(coord);
        maxarea = max(maxarea,are);
        coord.pop();
    }
    coord.clear();
    cout << maxarea << nl;
 
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