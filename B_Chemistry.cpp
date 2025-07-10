#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
 
    int t;
    cin >> t;
    while(t--){
        // string s of length  ,int k

        int n,k,count =0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int>hasmap(26);
        for(int i=0;i<n;i++){
            hasmap[s[i] - 'a'] ++;
        }
        for(int j=0;j<26;j++){
            if(hasmap[j] %2 != 0){
                count ++;
            }
        }
        if(count - k <= 1 ){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}