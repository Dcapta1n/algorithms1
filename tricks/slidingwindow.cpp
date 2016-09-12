///sliding window algo....

//motivation problem : http://codeforces.com/problemset/problem/279/B -easy

#include<iostream>
using namespace std;

int main(){
  int n,m;
  
  cin >> n >> m;
  int a[n];
  for(int i=0;i<n;i++){ cin >> a[i]; }
  
  int win=0; //size of window 
  
  int l=0,r=0; //left index & right index
  int ans=0;
  for( r=0 ; r<n ; r++ ){
  
        sum+=a[r];
  
        win++; //increasing window size
        
        while(sum>m && l<n){
  
          sum-=a[l];
  
          l++;
  
          win--; //window size decreases on moving left pointer
        }
      
      ans = max(ans,win); // to get max window size 
  
  }
  cout << ans << endl;
return 0;
}
