/******************
*	Subham kumar  *
	
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
ll n,m,k;
ll val[1000];
ll a[1000][1000];
ll b[1000][1000];
ll dp[2000][100][100][2];
ll iter=0;
ll doit(ll cst,ll i,ll j , ll flag){
//	iter++;
	//cout<<i<<" "<<j<<endl;
	if(i>=n || j>=m || cst<=0){return 0;}

	ll aa=0,bb=0,c=0,d=0;
	if(dp[cst][i][j][flag]!=-1){return dp[cst][i][j][flag];}
	if(flag){
		if(cst-a[i][j]>=0){		
		aa = b[i][j]+max(doit(cst-a[i][j],i+1,j,0),max(doit(cst-a[i][j],i,j,1),doit(cst-a[i][j],i,j+1,1)));	
		}
		bb = max(doit(cst,i,j+1,1),doit(cst,i+1,j,0));
		return dp[cst][i][j][flag]=max(aa,bb);
	}
	else{
		c  = doit(cst-val[i],i,j,1);
		d  = max(doit(cst,i,j+1,0),doit(cst,i+1,j,0));
		return dp[cst][i][j][flag]=max(c,d);
	}
}	
int main(){
boost;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;	
		memset(dp,-1,sizeof dp);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(val,0,sizeof val);

		for(int i=0;i<n;i++){cin>>val[i];}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>b[i][j];
				}
		}

		ll ans = doit(k,0,0,0);

		cout<<ans<<endl;



		

		}
 	



return 0;
}
 	
