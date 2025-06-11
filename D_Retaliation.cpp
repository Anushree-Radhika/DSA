#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++){
        int n,flag=1;
        cin >> n;
        vector <int> a(n);
        for(auto &x : a){
            cin >> x;
        }
        int x2 = (2*a[0] - a[1])/(n+1) ;
        int x1 = a[0] - n*x2;

        if(((2*a[0] - a[1]) < 0) || (2*a[0] - a[1]) % (n+1) != 0 || (x1 <0)){
            cout << "NO" << endl;
            continue;
        }

        for(int i =0;i<n ;i++){
            if((a[i] - (i+1)*x1 - (n-i)*x2) != 0){
                flag = 0 ;
                break;
            }
        }
        if(flag == 0)
            cout << "NO" << endl ; 
        else if(flag == 1)
            cout << "YES" << endl;    
    }
    return 0;
}