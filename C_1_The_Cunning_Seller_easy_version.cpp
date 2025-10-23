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

        ll n,rem = 0,deals = 0,cost = 0;
        cin >> n;

        string s;s = "";
        while(n!= 0){
            rem = n % 3;
            deals = rem;
            s = (char(rem)) + s;
            n = n/3;
        }
        ll x = 0;
        for(int i = s.length() - 1;i >= 0;i--){
            
            cost += int(s[i]) * ((pow(3,x+1)) + (x*(pow(3,x - 1))));
            x++;
            
        }
        cout << cost << nl;
    }
    return 0;
}