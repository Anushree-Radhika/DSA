#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n , k ,i=0;
        cin >> n >> k ;
        vector<int> a(n);
        cout << endl;
        for(auto &x: a){
            cin >> x ;
        }
        bool ans = is_sorted(a.begin(), a.end());
        if(ans == true ){
            cout << "YES" ;
        }
        else if(k >1){
            cout << "YES";
        }
        else if(k<=1){
            cout << "NO" ;
        }
    }
    return 0;
}