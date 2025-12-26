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
	//storing the elements frequency
	vi a(n);
	map<int,int>mp;
	rep(i,0,n) { cin>>a[i]; mp[a[i]]+=1;}
	// keeping the distinct elements in the vector
	vi v;
	int sum=0,cnt=0;
	for(auto i:mp){
		if(i.second & 1) v.pb(i.first);
		sum+=(i.second/2)*2*i.first;
		cnt+=(i.second/2)*2;
	}
	//now seeing if better sum can be find with including one element
	int finsum=0,m=v.size();
	rep(i,0,m){
		if(v[i]<sum) finsum=max(finsum,sum+v[i]);
	}
	//now seeing if better sum can be find with other element
	rep(i,1,m){
		if(v[i]-v[i-1]<sum){
			finsum=max(finsum,sum+v[i]+v[i-1]);
		}
	}
	//checking if cnt of pair is greater or not else it will just be sum
	if(cnt>2) finsum=max(sum,finsum);
	cout<<finsum<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

