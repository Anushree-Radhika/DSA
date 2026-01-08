#include<bits/stdc++.h>
using namespace std;

int main(){
    // Add these two lines for Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){

        int n;
        cin >> n;
        string s;
        cin >> s;
        int c0=0,c1=0;
        string str = s;
        sort(s.begin(), s.end());
        for(int i=0;i<str.length();i++){
            if(str[i] == '0') c0++;
            else c1++;
        }
        char ch = (c0 >= c1)? '1' : '0';
        int count = 0;
        for(int i=0; i < str.length(); i++){
            if(s[i] == ch && str[i] != s[i]){
                count++;
            }
        }
        cout << count << "\n"; // Using "\n" is also slightly faster than endl
    }
    return 0;
}