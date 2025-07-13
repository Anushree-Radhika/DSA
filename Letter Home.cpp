#include<bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin >> t;


	while(t--){


		int n,s;
	    cin >> n >> s;
	    int x[n];
	    for(int i=0;i<n;i++){
		    cin >> x[i];
	    }
	    int minval = INT_MAX,maxval = INT_MIN,ans=0,count =0;

	    for(int i=0;i<n;i++){
	    	minval = min(minval,x[i]);
	    	maxval = max(minval,x[i]);
	    }
	    if(s < maxval){
	    	ans = maxval - s;
	    	count ++;
	    }
	    if(s > minval){
	    	if(ans > (s-minval)){
	    	    if(count == 1)
	    		    ans += 2*(s - minval) ;  
	    	}
	    	else
	    		ans = 2*(ans) + s - minval;
	    }
	    cout << ans<< endl;
	}
	return 0;
}
