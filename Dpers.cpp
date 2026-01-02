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
#define endl '\n'

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
/* Observation:
 * ->	G(s) is the number of distinct nodes present in a undirected cyclic graph.
 * 
 * ->	G(s) we should take the set of pairs which does not make a cycle that 
 * 		will help in maximising the res.
 * 
 * ->	F(s) can be imagined as a graph, if there or more segments overlaps and
 * 		there are starting from same indices and ending at same indices that
 * 		overlapping has a cyle present in it.
 * 			-> These is the main observation in these problem 
 * 			-> implementation is easy. 
 * Main Logic:
 * -> 	Just sorting according to the first element because we are looking keeping
 * 		the distinct element that has same start that will avoid cycles present
 * 		and also we will keep the pair of numbers that has larger segment 
 * 		which will help in maximising the F(s).
 * 			-> these is a greedy thinking again.
 * 
 */
void solve() {
	int n; cin>>n;
	
	vector<pair<int,pair<int,int>>> a(n);
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		a[i].first=x;
		a[i].second={y,i};
	}
	
	sort(all(a));
	
	vi ans;
	rep(i,0,n){
		auto [x,y]=a[i];
		int ind=y.second;
		
		rep(j,i+1,n){
			if(x!=a[j].first) break;
			
			if(a[j].second.first>y.first){
				ind=a[j].second.second;
			}
			i=j;
		}
		
		ans.pb(ind+1);
	}
	
	sort(all(ans));
	
	cout<<ans.size()<<endl;
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

