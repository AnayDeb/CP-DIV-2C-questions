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
	
	vi a(n+1),b(n+1);
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,n+1) cin>>b[i];
	
	vi ranges(2*n+1);
	rep(i,1,2*n+1) ranges[i]=2*n+1;
	
	multiset<int>ms;
	rep(i,1,n+1) ms.insert(b[i]);
	
	rep(i,1,n+1){
		ms.insert(a[i]);
		int l=*ms.begin(),r=*ms.rbegin();
		ranges[l]=min(ranges[l],r);
		ms.erase(ms.find(b[i]));
	}
	
	int res=0,k=2*n+1;
	for(int i=2*n;i>=1;--i){
		k=min(k,ranges[i]);
		res+=2*n+1-k;
	}
	cout<<res<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

