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

        ll n,flag = 0;
        cin >> n ;

        string s,t;
        cin >> s >> t;
        int has[26] ={0};
        fl(i,0,n){
            has[s[i] - 'a']++;
            has[t[i] - 'a']--;
        }
        fl(i,0,26){
            if(has[i] != 0){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            cout << "NO" << nl;
        }
        else{
            cout << "YES" << nl;
        }
    }
    return 0;
}