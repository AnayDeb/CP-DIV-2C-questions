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
	vii v(n);
	set<int>s;
	rep(i,0,n){
		s.insert(i);
		v[i]={a[i],i};
	}
	sort(v.begin(),v.end());
	int cost=0,i=0;
	while(s.size()>2){
		int ind=v[i++].second;
		auto it1=s.upper_bound(ind);
		int high,low;
		if(it1==s.end()) high=*s.begin();
		else high=*it1;
		auto it2=s.lower_bound(ind);
		if(it2==s.begin()) low=*prev(s.end());
		else {--it2; low=*it2;}
		cost+=min(a[low],a[high]);
		s.erase(ind);
	}
	int maxi=-1;
	for(auto i:s) maxi=max(a[i],maxi);
	cost+=maxi;
	cout<<cost<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

