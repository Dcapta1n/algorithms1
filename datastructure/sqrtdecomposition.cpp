/******************
*	Subham kumar  *
* MNNIT         *
*******************/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
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
ll B;
vector<ll> a;
vector<ll> block;

void init(vector<ll> a){  //intializing sqrt blocks with data

	ll n=a.size();
	ll j =0;

  while(j<n){
		ll i =j;
		ll sum =0;
	
    while(i<j+B and i<n){
			sum+=a[i];
			i++;
			
		}

		block.pb(sum);
		j=i;
	}
}

ll query(vector<ll> a,ll lo,ll hi){
	ll i =lo;
	ll sum =0;


	// breaking query in 3 halves left half will query the from the array until a sqrt block is reached
	// mid half will be used to query from the sqrt block
	// right half will be used to query from the array until the given range is traversed


	while((i)%B!=0 and  i<=hi){ //left half query
		
		sum+=a[i];
		i++;
	}
	//cout<<i<<endl;
	while(i+B<=hi){ //mid half query i.e query from  the sqrt block
		
		sum+=block[i/B];
	
		i+=B;
	}
	while(i<=hi){ //right half query
		//cout<<i<<endl;
		sum+=a[i];
		i++;
	}
	return sum;
}

void update( ll i, ll val){ //simple point update 
  block[i/B]=block[i/B]-a[i]+val;
	a[i]=val;
}

int main(){
boost;
	int n;
	cin>>n;
	B = sqrt(n);
	//vector<ll> a;
	for(int i=0;i<n;i++){
		ll aa;
		cin>>aa;
		a.pb(aa);
	}
  
  
	init(a);
	
	for(int i=0;i<block.size();i++){
		cout<<block[i]<<endl;
	}
  
  
	ll q; // q no of queries
	cin>>q;
	
  for(int i=0;i<q;i++){
		ll lo,hi; 
		
		ll f ; // f = 0 for update f=1 to get sum of values from range lo to hi
		
		cin>>f;
		
		if(f){
		
		cin>>lo>>hi;
		
		ll ans =query(a,lo,hi);
		
		cout<<ans<<endl;

		}

		else{
			ll i ,val;
			cin>>i>>val;
			//cout<<a[i]<<endl;
			update(i,val);
		}

	}	

 	



return 0;
}
 	
