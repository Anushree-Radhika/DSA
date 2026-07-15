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

    ll n;
    cin >> n;

    string s;
    cin >> s; 
    int ans = INT_MAX; 


    for (char c = 'a'; c <= 'z'; c++)
    {
        int tmp = 0; 
        bool isPoss = true; 

        int i = 0, j = n - 1;

        
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++; 
                j--; 
                continue; 
            }

            if (s[i] == c)
            {
                tmp++; 
                i++; 
            }
            else if (s[j] == c)
            {
                tmp++; 
                j--; 
            }
            else
            {
                isPoss = false;
                break;
            }
        }

        if (!isPoss)
            tmp = INT_MAX; 

        ans = min(ans, tmp); 
    } 

    if (ans == INT_MAX)
        ans = -1; 

    cout << ans << "\n";
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