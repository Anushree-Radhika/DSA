#include<bits/stdc++.h>
using namespace std;
vector<char,pair<int,int>>has(vector<char,pair<int,int>>&mp,string s){
    int x = s.size(),c=1;
    for(int i=0;i<x;i++){
        if(mp[s[i]].second != 0){
            c = mp[s[i]].second + 1;
            mp[s[i]].second = c;
        }
        else{
            c=1;
            mp[s[i]].first = i;
            mp[s[i]].second = c;
        }
    }
    return mp;
}
vector<long long>syama(vector<long long>&a){
    long x = a.size(),i=0;
    vector<long long>z;
    while(i<(x/2)){
        z.push_back(a[i]+a[x-i-1]);
        i++;
    }
    if(x%2 != 0){
        z.push_back(a[x/2]);
    }
    return z;
}
int main(){
    string name1,name2;
    cin >> name1;
    cin >> name2;
    vector<char,pair<int,int>>mp;
    mp = has(mp,name1);
    mp = has(mp,"LOVES");
    mp = has(mp,name2);
    vector<long long>v;
    long long j = 0;
    while(j<mp.size()){
        for(auto i:mp){
            if(i.second.first == j){
                v.push_back(i.second.second);
                j++;
            }
        }
    }
    for(auto i:v){
        cout << i << " ";
    }
    
    vector<long long>num;
    num = syama(v);
    long long si = num.size();
    while(1 && si != 2){
        num = syama(num);
        si = num.size();
        if(si == 2){
            break;
        }
    }
    // for(auto i:num){
    //     cout << i << endl;
    // }
    
    string ans = "";
    for(auto i:num){
        ans += to_string(i);
    }
    cout << ans << endl;
    return 0;
}