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

int comp(int a,int b){
    return a > b;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--){
        
        ll n,op =0,mxnum = 0,count = 0,note = 0;
        cin >> n;
        vll a(n),cp(n);
        fl(i,0,n){
            cin >> a[i];
        }
        fl(i,0,n-1){
            mxnum  = max(mxnum,a[i]);
            mxnum = max(mxnum ,note);
            if(i%2 == 0 && a[i] >= a[i+1]){
                // mxnum = max(mxnum,a[i+1]);
                a[i+1] = mxnum;
                if(a[i+1] <= a[i]){
                    a[i] --;count++;
                }
            }
            if(i%2 != 0 && a[i] <= a[i+1]){
                a[i] = mxnum;
                note = a[i+1];
                if(a[i+1] >= a[i]){
                    count =count + a[i+1] - mxnum + 1;
                    a[i+1] = mxnum - 1;
                }
            }
        }
        cout << count << nl;
    }
    return 0;
}