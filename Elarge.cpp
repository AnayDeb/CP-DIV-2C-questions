/*
 * -> Anay Deb
 * "Everything is EASY... Just needs a little time!" 
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
/* Observations:
 * 		
 * 	-> 	If we optimise the subarray of 2 and subarray of 3 greedily the sum of 
 * 		even minus the sum of odd get optimised.
 * 
 * 	-> 	There is no point of minimising the elements of even indices (according to
 * 	 	our operation given in our question) ,we should always apply it in odd
 * 		indices and try to minismise.
 * 		
 * Main Logic:
 * -> 	The main logic is simple greedy we will just check the subarray of 2 and
 * 		the subarray of 3 , we will try to minimises the odd sum greedily.
 * 
 */
void solve() {
	int n; cin>>n;
	
	vi a(n+1);
	rep(i,1,n+1) cin>>a[i];
	
	int ans=0;
	// For length 2...
	for(int i=2;i<n+1;i+=2){
		if(a[i-1]>a[i]){
			int need=a[i-1]-a[i];
			ans+=need;
			a[i-1]-=need;
		}
	}
	//rep(i,1,n+1) cout<<a[i]<<" ";
	// For length 3...
	
	for(int i=2;i<n;i+=2){
		if(a[i-1]+a[i+1]>a[i]){
			int need=(a[i-1]+a[i+1])-a[i];
			ans+=need;
			if(need<=a[i+1]){
				a[i+1]-=need;
			}
			else{
				int temp=a[i+1];
				a[i+1]=0;
				need-=temp;
				a[i-1]-=need;
			}
		}
	}
	
	cout<<ans<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

