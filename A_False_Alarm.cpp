#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t ;i++){
        int n , x;
        cin >> n >> x ;
        int door_state[n];
        for(int i=0;i<n;i++){
            cin >> door_state[i];
        }
        int count =0,index ;
        for(int j = 0;j < n;j++ )
        {
            if(door_state[j] == 1){
                index = j;
                break;
            }
        }
        index = index +(x);
        while(index < n){
            if(index <n){
                if(door_state[index] == 1){
                    count = 1;
                }
            }
            index ++;
        }
        if(count == 1)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
}