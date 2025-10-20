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

    ll n,c=0,mi = INT_MAX,ma = INT_MIN,ans = 0;
    cin >> n ;
    map<int,int> ar;
    fl(i,0,n){
        int x;
        cin >> x;
        ar[x] ++;
        if(x > ma){
            ma = x;
        }
        if(x < mi){
            mi = x;
        }
    }
    if(ar.size() == 1){
        cout << 0 << nl;
    }
    else{
        ans = n - ar[ma] - ar[mi];
        cout << ans << nl;
        return 0;
    }
}