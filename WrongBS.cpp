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
	
	string s; cin>>s;
	
	bool f=true;
	rep(i,0,n){
		if(s[i]=='1') { f=false; break;}
	}
	if(f){
		cout<<"YES"<<endl;
		for(int i=n;i>=1;--i){
			cout<<i<<" ";
		}
		cout<<endl;
		return;
	}
	
	int cnt=0;
	rep(i,0,n){
		if(s[i]=='0') cnt+=1;
		else{
			if(cnt==1){
				cout<<"NO"<<endl;
				return;
			}
			cnt=0;
		}
	}
	if(cnt==1){
		cout<<"NO"<<endl;
		return;
	}
	
	cout<<"YES"<<endl;
	vi ans(n);
	rep(i,0,n){
		if(s[i]=='1'){
			ans[i]=i+1;
		}
	}
	
	vi keep;
	rep(i,0,n){
		if(s[i]=='1') keep.pb(i+1);
	}
	
	int prev=-1;
	rep(i,0,keep.size()){
		int curr=keep[i];
		if(prev==-1){
			int temp=curr-1;
			while(temp!=0){
				cout<<temp<<" ";
				temp-=1;
			}
			prev=curr;
			cout<<curr<<" ";
		}
		else{
			int temp=curr-1;
			while(temp!=prev){
				cout<<temp<<" ";
				temp-=1;
			}
			prev=curr;
			cout<<curr<<" ";
		}
	}
	if(keep.back()!=n){
		int temp=n;
		while(temp!=keep.back()){
			cout<<temp<<" ";
			temp-=1;
		}
	}
	cout<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

