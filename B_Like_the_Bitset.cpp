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

        ll n,k,count = 0,mxcount = 0,c=0;
        cin >> n >> k;
        string s;
        cin >> s;
        fl(i,0,n){
            if(s[i] == '1'){
                c++;
                count ++;
            }
            else{
                mxcount = max(count,mxcount);
                count = 0;
            }
        }
        mxcount = max(count,mxcount);
        if(mxcount >= k){
            cout << "NO" << nl;
        }
        else{
            int inh = 1;
            cout << "YES" << nl;
            fl(i,0,n){
                if(s[i] == '0'){
                    cout << ++c << " ";
                }
                else{
                    cout << inh++ << " ";
                }
            }
            cout << nl;
        }
    }
    return 0;
}