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
 * ->	One main observation here was the upper bound and the lower bound
 * 		the lower bound min can be n and the maximum can be n*(n+1)/2
 * 
 * -> 	Another observation is you can make any sum between these range and
 * 		make the tree greedily from left to right.
 * 
 * Main Logic:
 * -> 	The logic is we greedily go from right to left and try to make the 
 * 		sum that we need to remove like for ex(if we want to make a sum of 10
 * 		with node 5, then we need remove n*(n+1)/2-10 , which is 5, so will
 * 		try to make these sum).
 * 
 * -> 	We will keep the edges in a vector type ans which will keep the
 * 		u -> v connection through indices and val.
 */
void solve() {
	int n,m;
	cin>>n>>m;
	
	int sum=n*(n+1)/2;
	vi a(n+1);
	rep(i,1,n) a[i]=i;
	
	if(m>sum or m<n){
		cout<<-1<<endl;
		return;
	}
	
	int minus=sum-m,curr=0;
	vi ans(n+1);
	rep(i,1,n){
		ans[i]=i;
	}
	
	per(i,n,1){
		if(curr+(i-1)<=minus){
			curr+=(i-1);
			ans[i]=1;
		}
		else continue;
	}
	/*
	rep(i,1,n) cout<<ans[i]<<" ";
	cout<<endl;
	*/
	int maxi=-1;
	rep(i,1,n) maxi=max(maxi,ans[i]);
	
	bool f=true;
	per(i,n,1){
		if(ans[i]==maxi and i==maxi) {
			f=false;
			continue;
		}
		if(f) continue;
		else{
			if(i==ans[i]){
				ans[i]=maxi;
			}
		}
	}
	
	cout<<maxi<<endl;
	rep(i,1,n){
		if(i==ans[i]) continue;
		cout<<i<<" "<<ans[i]<<endl;
	}
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

