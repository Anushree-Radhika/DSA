#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n , x,point;
        cin >> n >> x;
        vector<int > a;
        a.push_back(0);
        for(int i=1;i<=n;i++){
            cin >> point;
            a.push_back(point);
        }
        a.push_back(x);
        n = a.size();

        int max_distance = INT_MIN;
        for(int i=1;i<n;i++){
            if(i == n-1){
                max_distance= max(max_distance, 2*(a[i] - a[i-1]));
            }
            else
                max_distance = max(max_distance, a[i] - a[i-1]);
        }
        cout << max_distance << endl;
    }
}