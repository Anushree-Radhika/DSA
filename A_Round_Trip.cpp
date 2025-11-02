#include <bits/stdc++.h>
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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){

        ll r0,x,d,n,c = 0;
        cin >> r0 >> x >> d >> n;
        string s;
        cin >> s;
        ll q = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                c++;
                r0 -= d;
            }
            else{
                if(r0 < x){
                    c++;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}  
