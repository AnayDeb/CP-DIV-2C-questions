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
	int n,k;
	cin>>n>>k;
	vi a(n),b(n);
	rep(i,0,n) cin>>a[i];
	rep(i,0,n) cin>>b[i];
	vi pre(n);
	pre[0]=a[0];
	rep(i,1,n){
		pre[i]=max(pre[i-1]+a[i],a[i]);
	}
	if(k%2==0){
		cout<<*max_element(pre.begin(),pre.end())<<endl;
		return;
	}
	vi suff(n);
	suff[n-1]=a[n-1];
	for(int i=n-2;i>=0;--i){
		suff[i]=max(suff[i+1]+a[i],a[i]);
	}
	int ans=-1e18;
	rep(i,0,n){
		ans=max(ans,pre[i]-a[i]+suff[i]+b[i]);
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

