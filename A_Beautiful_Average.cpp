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
 

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    fl(i,0,n){
        cin >> a[i];
    }
    float favg =0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            float avg = (float)sum/(j-i+1);
            favg = max(avg,favg);
        }
    }
    cout << favg << nl;

    //  ll n;
    // cin >> n;
    // vll a(n);
    // fl(i,0,n) cin >> a[i];
    
    // float maxAvg = 0;
    // for (int i = 0; i < n; i++) {
    //     ll sum = 0;
    //     for (int j = i; j < n; j++) {
    //         sum += a[j];
    //         float avg = (float)sum / (j - i + 1);
    //         maxAvg = max(maxAvg, avg);
    //     }
    // }
    // cout << fixed << setprecision(6) << maxAvg << nl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}