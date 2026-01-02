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
 * -> 	The main observation here is that to make a larger number present in a 
 * 		array we will need the smaller to make it.
 * 			-> But also the larger value cannot be larger than 2*smaller value.
 * 			-> If the larger value is smaller than 2*smaller value, we can 
 * 			   always make the value required.	
 * 
 * Main Logic:
 * -> 	Logic is simple implementation finding the mini and checking the
 * 		condition.
 * 
 */
void solve() {
	int n; cin>>n;
	
	vi a(n);
	rep(i,0,n-1) cin>>a[i];
	
	int mini=a[0];
	bool f=true;
	rep(i,1,n-1){
		mini=min(mini,a[i]);
		if(a[i]>a[i-1]){
			if(a[i]>=2*a[i-1] or a[i]>=2*mini) {
				//cout<<mini<<" ";
				f=false;
				break;
			}
		}
	}
	
	if(f) puts("YES");
	else puts("NO");
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

