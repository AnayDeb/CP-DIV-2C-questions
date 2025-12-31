/*
 * -> Anay Deb
 * "Everything is EASY... Just needs a little time!" 
 *  Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define per(i,a,b) for(int i= (b)-1; i>=(a); --i)
#define endl '\n'

// ---- GCD -----
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

// ----- LCM -----
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// ------ PRIME CHECK -----
bool isPrime(int n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0) return false;
    return true;
}

// ------- SOLVE FUNCTION ------
/*
 * Main Logic:
 * ->	These is DP question where we need to find the max subsequence,
 * 		in the condition that the if a number is present in the subsequence
 * 		then it should be present like ex-> [2,2] or [3,3,3].
 * 
 * -> 	So we cant find it greedily so we need DP here.
 *  
 * -> 	The main logic is that dp[i] gives the max possible subsequence 
 * 		present in its prefix. Now the Question is how to find the transition ?
 * 
 * -> 	We have to choices either we take the element or we skip the element
 * 		so the transition can be written as max(dp[i],dp[x-1]+a[i]), 
 * 		here x is the indices where the block starts.
 * 		
 */
void solve() {
	int n; cin>>n;
	
	vi a(n+1);
	rep(i,1,n+1) cin>>a[i];
	
	vi dp(n+2,0);// dp[i] stores the max possible ss in its prefix..
	map<pair<int,int>,int>mp;
	map<int,int>cnt;
	rep(i,1,n+1){
		cnt[a[i]]+=1;
		mp[{cnt[a[i]],a[i]}]=i;
		dp[i+1]=dp[i];
		if(mp[{cnt[a[i]]-a[i]+1,a[i]}]!=0){
			dp[i+1]=max(dp[i],dp[mp[{cnt[a[i]]-a[i]+1,a[i]}]]+a[i]);
		}
	}
	
	cout<<dp[n+1]<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

