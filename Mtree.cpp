#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

#define int long long
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,a,b) for(int i = (a); i < (b); i++)

// ===== GCD =====
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

// ===== LCM =====
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// ===== PRIME CHECK =====
bool isPrime(int n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0) return false;
    return true;
}

// ===== SOLVE FUNCTION =====
void solve() {
	int n; cin>>n;
	
	// Making the adjacency list for the graph...
	unordered_map<int,vector<int>>adj;
	vi indegree(n+1,0);
	rep(i,0,n-1){
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		
		if(x>y){
			// Greedily we take the indegrees...
			adj[u].pb(v);
			adj[v].pb(u);
			indegree[u]+=1;
		}
		else{
			adj[u].pb(v);
			adj[v].pb(u);
			indegree[v]+=1;
		}
	}
	// Pushing the vertices with 0 indegree for the multisource BFS..
	unordered_map<int,bool>vis;
	queue<int>q;
	rep(i,1,n+1){
		if(indegree[i]==0){
			q.push(i);
			vis[i]=true;
		}
	}

	// Keeping the ans in vector...
	int i=1;
	vi ans(n+1);
	// Doing the BFS or we can say the whole the algorithm as TOPO SORT..
	while(!q.empty()){
		auto front=q.front();
		q.pop();
		
		ans[front]=i++;
		
		for(auto u:adj[front]){
			if(!vis[u]){
				indegree[u]-=1;
				if(indegree[u]==0) {
					q.push(u);
					vis[u]=true;
				}
			}
		}
	}
	// Printing the list...
	rep(i,1,n+1) cout<<ans[i]<<" ";
	cout<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

