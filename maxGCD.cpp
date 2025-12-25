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
	int n,k,ans=1; cin>>n>>k;
	
	map<int,int>mp;
	vi a(n+1);
	rep(i,1,n+1) {cin>>a[i]; mp[a[i]]+=1;}
	
	sort(a.begin(),a.end());
	
	rep(i,1,n+1){
		
		int start=1,end=n,index=-1;
		int sum=mp[i]+mp[2*i]+mp[3*i];
		while(start<=end){
			int mid=(start+end)/2;
			if(4*i<=a[mid]){
				index=mid;
				end=mid-1;
			}
			else start=mid+1;
		}
		
		if(index!=-1) sum+=n-index+1;
		int left=n-sum;
		if(left<=k) ans=max(i,ans);
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

