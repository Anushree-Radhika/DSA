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
        
        ll n,k,c0=0,c1 =0,flag = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vll a(n);
        // if(s[0] == '1'){
        //     c1 ++;
        // }
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                for(int j = i-k+1;j<i;j++){
                    if(j >= 0 && s[j] == '1'){
                        flag = 3;
                        break;
                    }
                    else{
                        flag =0;
                    }
                }
                if(flag == 0){
                    c1++;
                }
            }
        }
        cout << c1 << nl;
        
    }
    return 0;
}