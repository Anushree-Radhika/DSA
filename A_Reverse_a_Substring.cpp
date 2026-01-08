#include<bits/stdc++.h>
using namespace std;
int main(){

    long long n,flag = 0;
    string s;cin >> n;cin >> s;
    for(long long i=0;i<n-1;i++){
        if(s[i] > s[i+1]){
            flag = 1;
            cout << "YES\n" ;
            cout << i+1 << " " << i + 2 << endl;
            break;
        }
    }
    if(flag == 0)  {
        cout << "NO" << endl;
    }
    return 0;
}