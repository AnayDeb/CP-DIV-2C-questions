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
	
	vi a(n),b(n);
	rep(i,0,n) cin>>a[i];
	rep(i,0,n) cin>>b[i];
	
	vector<set<int>>pf(n);
	rep(i,0,n){
		int curr=a[i];
		set<int>temp;
		for(int j=2;j*j<=curr;++j){
			if(curr%j==0){
				while(curr%j==0){
					curr/=j;
				}
				temp.insert(j);
			}
		}
		if(curr>1) temp.insert(curr);
		pf[i]=temp;
	}
	
	unordered_map<int,int>mp;
	rep(i,0,n){
		set<int>temp=pf[i];
		for(auto i:temp){
			mp[i]+=1;
		}
	}
	
	for(auto i:mp){
		if(i.second>=2) { cout<<0<<endl; return;}
	}
	
	rep(i,0,n){
		int curr=a[i]+1;
		for(int j=2;j*j<=curr;++j){
			if(curr%j==0){
				while(curr%j==0){
					curr/=j;
				}
				if(mp[j]>0) { cout<<1<<endl; return;}
			}
		}
		if(curr>1) {
			if(mp[curr]>0) {
				cout<<1<<endl;
				return;
			}
		}
	}
	
	cout<<2<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

