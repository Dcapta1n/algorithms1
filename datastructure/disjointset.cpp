/*
implementaion of union find disjoint set data structure
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

lli  P[1000000]; //to store parent
int rank[100000]; 

void init(int n){ //to intitalize the elements
	for(int i =0;i<n;i++){
		P[i]=i;
	}
	memset(rank,0,sizeof rank);
}

int find(int i){
	return (P[i]==i)?i:(P[i]=find(P[i]));
}

bool isSameSet(int i , int j){	// return if the two element belkong to same set
	return find(i)==find(j);
}

void union2(int i,int j){ //union 2 disjoint set to 1
	if(!isSameSet(i,j)){
		int x = find(i),y=find(j);
		if(rank[x]>rank[y])P[y]=x;
		else{	P[x]=y;
			if(rank[x]==rank[y]){rank[y]++;}
		}
	}
}

int main(){
boost;


 	



return 0;
}
