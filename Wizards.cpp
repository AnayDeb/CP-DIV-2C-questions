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
bool check(string s,int n,vi a){
	// These function checks whether the string is correct or not !
	vi pre(n),suff(n);
	pre[0]=(s[0]=='L');
	rep(i,1,n){
		if(s[i]=='L') pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1];
	}
	
	suff[n-1]=(s[n-1]=='R');
	for(int i=n-2;i>=0;--i){
		if(s[i]=='R') suff[i]=suff[i+1]+1;
		else suff[i]=suff[i+1];
	}
	// Creating the ans vector to check with the a vector;
	vi ans(n);
	rep(i,0,n) ans[i]=pre[i]+suff[i];
	
	bool f=true;
	rep(i,0,n) if(ans[i]!=a[i]) { f=false; break;}
	
	return f;
}
void solve() {
	int n; cin>>n;
	
	vi a(n);
	rep(i,0,n){ cin>>a[i];}
	
	// We know that the abs diff between the value cannot be zero so..
	bool f=true;
	rep(i,1,n){
		if(abs(a[i]-a[i-1])>1) {f=false; break;}
	}
	if(!f) {
		cout<<0<<endl; 
		return;
	}
	// Checking if all the elements are same !!
	bool ok=true;
	int comp=a[0];
	rep(i,1,n) if(a[i]!=comp) {ok=false; break;}
	if(ok){
		// Making two strings that are possible !
		string temp1="",temp2="";
		bool o=true;
		rep(i,0,n){
			if(o) {temp1+='L'; o=!o;}
			else {temp1+='R'; o=!o;}
		}
		o=false;
		rep(i,0,n){
			if(o) {temp2+='L'; o=!o;}
			else {temp2+='R'; o=!o;}
		}
		// Now checking for the two strings possible!
		if(check(temp1,n,a) and check(temp2,n,a)){
			cout<<2<<endl;
			return;
		}
		else if(check(temp1,n,a) or check(temp2,n,a)){
			cout<<1<<endl;
			return;
		}
		else {
			cout<<0<<endl;
			return;
		}
	}
	// Creating a char vector for the rest of the checking !
	vector<char>s(n,'#');
	rep(i,1,n){
		if(a[i]-a[i-1]==0) continue;
		else if(a[i]-a[i-1]==1){
			if(s[i]=='#') s[i]='L';
			else {
				if(s[i]=='R'){ cout<<0<<endl; return;}
			}
			if(s[i-1]=='#') s[i-1]='L';
			else {
				if(s[i-1]=='R') { cout<<0<<endl; return;}
			}
		}
		else if(a[i]-a[i-1]==-1){
			if(s[i]=='#') s[i]='R';
			else {
				if(s[i]=='L') { cout<<0<<endl; return;}
			}
			if(s[i-1]=='#') s[i-1]='R';
			else {
				if(s[i-1]=='L') { cout<<0<<endl; return;}
			}
		}
	}
	// Filling the gaps in S vector!
	rep(i,1,n){
		if(s[i]=='#'){
			if(a[i]-a[i-1]==0){
				if(s[i-1]=='L') s[i]='R';
				else if(s[i-1]=='R') s[i]='L';
			}
		}
	}
	if(s[n-1]=='#'){
		if(a[n-1]-a[n-2]==0){
			if(s[n-2]=='L') s[n-1]='R';
			else if(s[n-2]=='R') s[n-1]='L';
		}
	}
	// Filling from the last
	for(int i=n-2;i>=0;--i){
		if(a[i]-a[i+1]==0){
			if(s[i+1]=='L') s[i]='R';
			else if(s[i+1]=='R') s[i]='L';
		}
	}
	if(s[0]=='#'){
		if(a[0]-a[1]==0){
			if(s[1]=='L') s[0]='R';
			else if(s[1]=='R') s[0]='L';
		}
	}
	
	vi pre(n),suff(n);
	pre[0]=(s[0]=='L');
	rep(i,1,n){
		if(s[i]=='L') pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1];
	}
	
	suff[n-1]=(s[n-1]=='R');
	for(int i=n-2;i>=0;--i){
		if(s[i]=='R') suff[i]=suff[i+1]+1;
		else suff[i]=suff[i+1];
	}
	// last check for the S vector...
	vi ans(n);
	rep(i,0,n) ans[i]=pre[i]+suff[i];
	
	bool z=true;
	rep(i,0,n){
		if(ans[i]!=a[i]){
			z=false;
			break;
		}
	}
	if(z) cout<<1<<endl;
	else cout<<0<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

