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

        ll n,p,sum =0,count = 0,d=0,idx=0;
        cin >> n >> p;
        vll a(n),b(n);
        vector<pair<ll, ll>> k(n);
        fl(i,0,n){
            cin >> a[i];
        }
        fl(i,0,n){
            cin >> b[i];
        }
        fl(i,0,n){
            k[i] = {a[i] ,b[i]};
        }
        sort(k.begin(),k.end(),[](const pair<ll, ll>& m,const pair<ll, ll>& n) {
            return m.second < n.second;
        });
        sum += p ;count++;
        for(auto it : k){
            if(count != n && it.second < p){
                if(count == n){
                    break;
                }
                else if(count + it.first <= n){
                    sum += it.first * it.second;count += it.first;
                } 
                else{
                    sum += (n - count) * it.second;count = n;
                }   
            }
            else{
                break;
            }
        }
        sum += (n-count)*p;
        cout << sum << nl;
    }
    return 0;
}