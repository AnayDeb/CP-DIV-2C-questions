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
	
	n*=2;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	
	if(n==2){
		cout<<a[n-1]-a[0]<<endl;
		return;
	}
	
	vi ans1,ans2;
	{
		int sum=0;
		rep(i,0,n){
			if(i & 1) sum+=a[i];
			else sum-=a[i];
		}
		ans1.pb(sum);
	}
	{
		int sum=0;
		rep(i,0,2) sum-=a[i];
		rep(i,2,n-2) {
			if(i & 1) sum-=a[i];
			else sum+=a[i];
		}
		rep(i,n-2,n) sum+=a[i];
		ans2.pb(sum);
	}
	for(int i=1;i<n-1-i;i+=2){
		ans1.pb(ans1.back()-2*a[i]+2*a[n-1-i]);
	}
	for(int i=2;i<n-1-i-1;i+=2){
		ans2.pb(ans2.back()-2*a[i]+2*a[n-1-i]);
	}
	
	rep(i,0,ans2.size()) cout<<ans1[i]<<" "<<ans2[i]<<" ";
	if((n/2) & 1) cout<<ans1.back()<<" ";
	cout<<endl;
	
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

