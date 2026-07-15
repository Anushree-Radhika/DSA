#include<bits/stdc++.h>
using namespace std;
int main(){

   int tc;
   cin >> tc;
   while(tc--){

      int n;
      cin >> n;
      string s;
      cin >> s;

      int counter = 1,largest=0;

      for(int i=0;i<s.length()-1;i++){

         if(s[i] == s[i+1]){
            counter ++;
         }
         else{
            counter=1;
         }
         largest = max(largest,counter);

      }
      if(s.length() == 1){
         cout << 2 << endl;
      }
      else{
         
           cout << largest +1 << endl;
      }
   }
   return 0;
}
