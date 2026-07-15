#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
#define pub push_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n"
#define input(x,v) for(auto &x:v)cin>>x;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
void solve(){

    // ll n,cnt = 0,idx = -1;
    // char c;
    // cin >> n >> c;
    // string s = "";
    // cin >> s;
    // fl(i,0,n){
    //     if(s[i] != c){
    //         cnt++;
    //     }
    //     else{
    //         if(i == 0){
    //             continue;
    //         }
    //         ll num = i+1,f = 1;
    //         for(ll j =i;j<=n;j+=num){
    //             if(s[j] != c){
    //                 f = 0;
    //                 break;
    //             }
    //         }
    //         if(f){
    //             idx = i+1;
    //         }
    //     }
    // }
    // if(cnt == 0){
    //     cout << 0 << nl;
    // }
    // else if(s[n-2] == c){
    //     cout << 1 << nl << n-1 << nl;
    // }
    // else if(s[n-1] == c){
    //     cout << 1 << nl << n << nl;
    // }
    // else if(idx != -1){
    //     cout << 1 << nl << idx << nl;
    // }
    // else{
    //     cout << 2 << nl << n-1 << " " << n << nl;
    // }

    ll n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s; 
    bool check0 = true;
    fl(i,0,n){
        if (s[i] != c){
            check0 = false;
            break;
        }
    }
    if (check0){
        cout << "0\n";
        return;
    }
    ll val1 = -1;
    for (ll i = 2; i <= n; i++){
        bool isPoss = true;
        for (ll j = i; j <= n; j += i){
            if (s[j - 1] != c){
                isPoss = false;
                break;
            }
        }

        if (isPoss){
            val1 = i;
            break;
        }
    }
    if (val1 != -1){
        cout << "1\n";
        cout << val1 << "\n";
        return;
    }
    cout << "2\n";
    cout << n - 1 << " " << n << "\n";
}   
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}