/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!" 
 * -> Lets Fucking GOO!!
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
#define rep(i,a,b) for(int i = (a); i <=(b); ++i)
#define per(i,a,b) for(int i= (a); i>=(b); --i)
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
/* Observations:
 * 
	1 5 6 11 8
	1 7 11 9 4
	4 6 1 3 2
	7 5 4 2 3
	
	0 0 0 0 0 0 
	0 1 0 0 0 0 
	0 0 0 0 0 0 
	0 0 0 0 0 0 
	0 0 0 0 0 0 
	->	These is a simple obsevation problem with only the concept of 2d prefix sum.
	->	The main observation is the only time gold is lost is the first after then the spaces
	get empty can be taken every other gold.
 * 
 * Main Logic:
 * 
 */
void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	
	string s[n];
	rep(i,0,n-1) cin>>s[i];
	
	vector<vi> pre(n+1,vi (m+1,0));
	rep(i,0,n-1){
		rep(j,0,m-1){
			pre[i+1][j+1]=pre[i][j+1]+pre[i+1][j]-pre[i][j]+(s[i][j]=='g');
		}
	}
	
	auto func=[&](int x,int y)->pair<int,int>{
		if(x<0) x=0;
		if(y<0) y=0;
		if(x>n) x=n;
		if(y>m) y=m;
		return {x,y};
	};
	
	int mini=1e18;
	rep(i,0,n-1){
		rep(j,0,m-1){
			if(s[i][j]=='.'){
				auto [x1,y1]=func(i-k+1,j-k+1);
				auto [x2,y2]=func(i+k,j+k);
				
				mini=min(mini,pre[x2][y2]+pre[x1][y1]-pre[x2][y1]-pre[x1][y2]);
			}
		}
	}
	cout<<pre[n][m]-mini<<endl;
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

