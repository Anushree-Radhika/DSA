#include<bits/stdc++.h>
using namespace std;
int main(){
   
   int tc;
   cin >> tc;
   while(tc--){

       long long n,k;
       cin >> n >> k;
       vector<int>a(n);
       for(int i=0;i<n;i++){
        cin >> a[i];
       }
       sort(a.begin(),a.end());
       int count = 1,largest = 0;

       for(int i=0;i<n-1;i++){
            if(a[i+1] - a[i] <= k){
                count++;
            }
            else{
                count = 1;
            }
            largest = max(largest,count);
        }
        if( n == 1){
            cout << 0 << endl;
        }
        else{

            cout << n-largest << endl;
        }
   }
   return 0;
}
