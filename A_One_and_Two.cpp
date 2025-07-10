#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,flag = 0;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        int k = 0;
        while(k <n){
            int mul=1,mult = 1;

            for(int j=0;j<=k;j++){
                mul *= a[j];
            }
            for(int j=k+1;j<n;j++){
                mult *= a[j];
            }
            if(mul == mult){
                flag = 1;
                break;
            }
            k++;
        }
        if(flag == 0){
            cout << -1 << endl;
        }
        else{
            cout << k+1 << endl;
        }

    }
    return 0;
}