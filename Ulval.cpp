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
	
	vi a(n);
	rep(i,0,n) cin>>a[i];
	
	int sum=0;
	rep(i,0,n){
		if(i & 1) sum-=a[i];
		else sum+=a[i];
	}
	int val=0;
	int maxi=-1e18,mini=1e18;
	rep(i,0,n){
		if(i & 1){
			maxi=max(maxi,2*a[i]-i);
			val=max(val,2*a[i]+i-mini);
		}
		else{
			mini=min(mini,2*a[i]+i);
			val=max(val,maxi-(2*a[i]-i));
		}
	}
	
	//cout<<val<<endl;
	int ans=max({sum,sum+val,sum+((n&1)?n-1:n-2)});
	cout<<ans<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

