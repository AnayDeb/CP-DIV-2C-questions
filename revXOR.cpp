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
	if(n==0) {puts("YES"); return;}
	
	int cnt=0;
	string s="";
	while(n!=0){
		if(1 & (n)) { cnt+=1; s+='1';}
		else s+='0';
		n>>=1;
	}
	reverse(s.begin(),s.end());
	
	string ne="";
	bool ok=false;
	for(int i=s.size()-1;i>=0;--i){
		if(s[i]=='1') ok=true;
		if(ok) ne+=s[i];
		else continue;
	}
	
	bool f=true;
	rep(i,0,ne.size()/2+1){
		if(ne[i]!=ne[ne.size()-1-i]) {
			f=false;
			break;
		}
	}
	
	if(cnt%2==0 and f) puts("YES");
	else puts("NO");
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

