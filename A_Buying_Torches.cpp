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

        ll x,y,k;
        cin >> x >> y >> k;
        ll sticks = 1,answer = 0;
        ll required_sticks = k + y*k;
        if(((required_sticks - 1)% (x-1)) == 0){
            answer = ((required_sticks - 1)/(x-1));
        }
        else{
            answer = ((required_sticks - 1)/(x-1)) + 1;
        }
        answer += k;
        cout << answer << endl; 
    }
    return 0;
}