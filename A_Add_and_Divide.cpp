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
 
int count(ll num,ll di){
    ll x = num,count = 0;
    while(x!= 0){
        x = x/di;
        count++;
    }
    return count;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while(t--){

        ll a,b;
        cin >> a >> b;
        if(a < b){
            cout << 1 << endl;
            continue;
        }
        if(a == b){
            cout << 2 << nl;continue;
        }
        ll ans = INT_MAX,flag = 0;
        if(b == 1){
            b++;
            flag = 1;
        }
        
        for(ll i=b;i<=a;i++){

            // ll x = 1 + (int)(log(a)/log(i));
            // if(x + i - b >  ans){
            //     break;
            // }
            // ans = min(ans,x+i-b);
            int c = count(a,i);
            if(c + i-b > ans){
                break;
            }
            ans = min(ans,c + i-b);
        }
        if(flag == 1){
            cout << ans + 1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}