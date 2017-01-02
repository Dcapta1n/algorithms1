#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define boost cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
vi g[10000000];

void bfs(int v,int s){ //s is the starting node
vi col(v+1); //colour of the node
vi d(v+1); //distance from source 
vi pi(v+1); // parent of the current node
	fill(col.begin(),col.end(),-1);
	fill(d.begin(),d.end(),INT_MAX);
	fill(pi.begin(),pi.end(),0);
	
col[s]=0;//-1 for white 0 for grey and 1 for black
d[s]=0;
pi[s]=0;
queue<int> q;
q.push(s); ///pushing the first node in  the queue

while(!q.empty()){
	int u = q.front();
	
	q.pop();
	for(int i=0;i<g[u].end()-g[u].begin();i++){ //iterating till no child of the current node is left out
		
		int node = g[u][i];
		//cout <<node<<endl;
		//cout <<col[node]<<endl;
		if(col[node]==-1){
			col[node]=0;
			d[node]=d[u]+1;
			pi[node]=u;
			q.push(node);
			}
				
	}
	col[u]=1;
		
}
for(int i=1;i<v;i++){
	cout <<d[i]<<endl;
}
}

int main(){
cout << "No of vertices and edges"<<endl;
int v,e,uu,vv;
cin >>v>>e;	 //no of vertex and edgess
for(int i=0;i<e;i++){

cin >>uu >>vv; //taking edges as input(2,1) means an edge is in between 2 and 1
g[uu].pb(vv);
g[vv].pb(uu);
}
bfs(v,1); //starting bfs from node 1

return 0;
}
