#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n ;
        vector <int> a(n);
        // a[0] = 1;
        // a[n-1] = 2;
        for(int i =0;i<n;i++){
            a[i] = i+1;   
        }
        swap(a[1],a[n-1]);
        for(auto &i : a)
            cout << i << " ";

        cout << endl;
    }
    return 0;
}