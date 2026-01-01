/*
 * -> Anay Deb
 * "Everything is EASY... just needs a little time!" 
 *  Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define per(i,a,b) for(int i= (b)-1; i>=(a); --i)
//#define endl '\n'

// ---- GCD -----
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

// ----- LCM -----
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// ------ PRIME CHECK -----
bool isPrime(int n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0) return false;
    return true;
}

// ------- SOLVE FUNCTION ------
/* Observations:
 * ->	There is a main observation that to find if there is a edge between two
 * 		vertices we can just ask a query if it return 1 then there is no edge
 * 		else there is edge.
 * 
 * ->	Another observation is that we can find the longest path through 
 * 		giving n query with all the edges , the max return means it has the 
 * 		longest path 
 *  
 * Main Logic:
 * ->	We will make a vector of vector to keep the num corresponding to edges
 * 		so that we can get track of the longest path .
 * 
 * -> 	When we will see the longest path then we will run n-1 edges to find the 
 * 		path between the other edges to find the full paths.
 * 
 */
int query(int u,vi a){
	cout<<"?"<<" "<<u<<" "<<a.size()<<" ";
	rep(i,0,a.size()) cout<<a[i]<<" ";
	cout<<endl;
	
	int ans;
	cin>>ans;
	return ans;
}
void solve() {
	int n; cin>>n;
	
	vi a(n);
	rep(i,0,n) a[i]=i+1;
	
	vector<vector<int>> adj(n+1);
	rep(i,1,n+1){
		adj[query(i,a)].pb(i);
	}
	
	vi ans;
	int first=-1;
	per(i,1,n+1){
		if(adj[i].empty()) continue;
		
		if(first==-1){
			first=adj[i][0];
			ans.pb(adj[i][0]);
			continue;
		}
		
		for(auto j:adj[i]){
			if(query(first,{first,j})!=1){
				first=j;
				ans.pb(j);
				continue;
			}
		}
	}
	
	cout<<"!"<<" "<<ans.size()<<" ";
	rep(i,0,ans.size()) cout<<ans[i]<<" ";
	cout<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) { 
		solve();
	}
	
    return 0;
}

