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
    ll t=1;
    cin>>t;

    while(t--){

        ll n,count =0,count1 = 0;
        cin >> n;

        vll a(n);
        fl(i,0,n){
            cin >> a[i];
            if(a[i] == 0){
                count ++;
            }
            if(a[i] == -1){
                count1 ++;
            }
        }
        if(count1 %2 != 0){
            count += 2;
        }
        cout << count << endl;
    }
    return 0;
}