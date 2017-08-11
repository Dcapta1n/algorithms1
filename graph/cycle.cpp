/******************
*	Subham kumar  *
*				  *	
*******************/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
#define  F first 
#define  S second
typedef pair<ll,ll> ii;
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define fl(i,a,b) for(int i=int(a);i<=int(b);i++)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define PI 3.14159265359
#define N 4000000
#define mod 1000000007
#define white 0
#define grey 1
#define black 2
vi g[N]; // adjacency list


//code to find cycle;
void dfs(int s,int p){
  col[s]=grey; //
  for(int i=0;i<g[s].size();i++){
    int v=g[s][i];
    if(col[v]==white){
      dfs(v,s);
    }else if(col[v]==grey and v!=p ){
      //found cycle;
    }
  }
  col[v]=black;
}


int main(){
boost;
	  int t;
    cin>>t;
    while(t--){
      ll n,m;
      cin>>n>>m;
      for(int i=0;i<m;i++){ 
        ll u,v;
        cin>>u>>v; //taking input of graph in adjacency list
        g[u].pb(v);
      }
    
    for(int i=1;i<=n;i++){
      if(col[i]==white){
        dfs(i,-1);
      }
    }
  
    }



 	



return 0;
}
 	
