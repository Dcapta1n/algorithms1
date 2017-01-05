/******************
*	Subham kumar  *
	
*******************/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
#define  F  first
#define  S 	second
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
vii g[20000];
	ll dis[400000];

	ll vis[400000];

	void djik(int s){
		priority_queue< ii , vector<ii> ,greater<ii> > q;
		dis[s]=0;
		
		q.push(mp(0,s));
		while(!q.empty()){
		 ii p = q.top();
		 q.pop();
		if(vis[p.S]==1){continue;}
		vis[p.S]=1;
		 int v = p.S;
		

		for(int i=0;i<g[v].size();i++){
			int u = g[v][i].S;
		
				if(dis[v]+g[v][i].F<dis[u]){
					q.push(mp(g[v][i].F,g[v][i].S));
				
					dis[u]=dis[v]+g[v][i].F;
			}
		
		
		}
		

		}

	}

int main(){
boost;
	int t;
	cin>>t;
	while(t--){
		ll v,k;
		cin>>v>>k;
		memset(vis,0,sizeof vis);
		fill(dis,dis+100000,INT_MAX);
		memset(g,0,sizeof g);
		for(int i=0;i<k;i++){
			ll a ,b ,c;
			cin>>a>>b>>c;
			g[a].pb(mp(c,b));
		}
		ll a ,b;
		cin>>a>>b;
		djik(a);
		if(dis[b]==INT_MAX){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<dis[b]<<endl;
	}

 	



return 0;
}
 	
