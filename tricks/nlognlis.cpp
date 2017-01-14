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
int main(){
boost;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<ll> v;
	v.pb(a[0]);
	for(int i=1;i<n;i++){
		
		 if(a[i]>v[v.size()-1]){
			v.pb(a[i]);
		}
		else{
			ll bin = lower_bound(all(v),a[i])-v.begin();
			v[bin]=a[i];
		}
	}
	cout<<v.size()<<endl;
	
	 	



return 0;
}
 	
