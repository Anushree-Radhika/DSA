#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define F first
#define S second 
#define ll long long 
#define vll vector<long long> 
#define vpll vector<pair<ll,ll>>
#define pub push_back 
#define pop pop_back 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fl(i,x,n) for (ll i = x; i < n; i++)
#define nl "\n" 
#define input(x,v) for(auto &x:v)cin>>x;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
bool palindrome(ll num){
    string s = to_string(num);
    fl(i,0,s.length()/2){
        if(s[i] != s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}

// Creates a palindrome by mirroring the given prefix
ll buildPalindrome(ll half, int targetLen) {
    string s = to_string(half);
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    // If target length is odd, the last character of 'half' shouldn't be duplicated
    if (targetLen % 2 != 0) {
        s += rev.substr(1);
    } else {
        s += rev;
    }
    
    // Return 0 if the generated length doesn't match what we expected
    if ((int)s.length() != targetLen) return -1;
    
    try {
        return stoll(s);
    } catch (...) {
        return -1;
    }
}

void solve() {
    ll n;
    cin >> n;

    if (n < 0) {
        cout << -1 << nl;
        return;
    }

    string s = to_string(n);
    int len = s.length();
    
    vll candidates;
    candidates.push_back(0); // Fallback base case

    // We check three possible digit lengths: len, len-1, len-2
    for (int L = max(1, len - 2); L <= len; L++) {
        int halfLen = (L + 1) / 2;
        
        // Find the base prefix for length L based on n
        ll baseHalf = 0;
        if (L == len) {
            baseHalf = stoll(s.substr(0, halfLen));
        } else {
            // If the length is smaller, start from the maximum possible prefix (e.g., 999...)
            string maxHalf(halfLen, '9');
            baseHalf = stoll(maxHalf);
        }

        // Search a wide window around the base prefix to guarantee hitting all mod 12 cycles
        for (ll i = -150; i <= 50; i++) {
            ll curHalf = baseHalf + i;
            if (curHalf > 0) {
                ll pal = buildPalindrome(curHalf, L);
                if (pal != -1 && pal <= n) {
                    candidates.push_back(pal);
                }
            }
        }
    }
    sort(candidates.rbegin(), candidates.rend());
   
    for (ll a : candidates) {
        if ((n - a) % 12 == 0) {
            cout << a << " " << n - a << nl;
            return;
        }
    }

    cout << -1 << nl;
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