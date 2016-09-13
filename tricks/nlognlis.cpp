/******************
*	Subham kumar  *
	IT
	MNNIT ALLAHABAD

*******************/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define fl(i,a,b) for(int i=int(a);i<=int(b);i++)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int main(){
boost;
	
	int n;
	cin>>n;
	int a[n],l[100000];
	for(int i=0;i<n;i++){cin>>a[i];}
	
	vector<lli> v(n+1,INT_MAX);
	
	


	for(int i=0;i<n;i++){
	
		*lower_bound(all(v),a[i])=a[i];
	
	}	

	for(int i=0;i<n;i++){
		if(v[i]==INT_MAX){
			cout<<i<<endl;
			return 0;
		}
	}


return 0;
}
 	
