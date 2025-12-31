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
/*
->  Its main logic is that we want the x to be made ,we can just go from the
	and try to find the answer... As the condition given we can find x in two ways 
	-> if we bring that from (a+b/2,b/2) then we get (2*x-2^k+1) equation which gives 
		the ans.
	-> if we bring that from (a/2,b+a/2) then we get (2*x) equation which gives the ans.
	
	Its basically a easy problem of 1100 rated just need to find the equations.
*/
void solve() {
	int k,x;
	cin>>k>>x;
	
	vi ans;
	int reach=pow(2,k);
	while(x!=reach){
		if(x>reach){
			x=2*x-pow(2,k+1);
			ans.pb(2);
		}
		else if(x<reach){
			x*=2;
			ans.pb(1);
		}
	}
	cout<<ans.size()<<endl;
	reverse(ans.begin(),ans.end());
	rep(i,0,ans.size()) cout<<ans[i]<<" ";
	cout<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

