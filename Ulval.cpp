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
 * ->	These is a 1500 rated question and the main observation in these question is
 * 	  	that the game will only continue max to max one round that also , the first
 * 	  	round of Alice and the most optimal situation for Bob is to just end the game.
 * 
 * -> 	So Alice will either finish the game in first round or will make the sum more.
 * 		But Bob will always end the game.
 * 
 * -> 	So , we need to find the 2 indices that alice will swap so that the sum eventually
 * 		increases more and gets more sum.
 * 
 * -> 	Now the question is how many ways alice can chose the indices 
 * 		-> There are basically 4 ways to choose :-
 * 			-> first he can chose + +
 * 			-> second he can chose - -
 * 			-> third he can chose - +
 * 			-> fourth he can chose + -
 * 
 * -> 	Same same cases can handled just by if( n is even ) then cost+ n-2;
 * 	  	else cost + n-1;
 * 
 * -> 	For the alternate sign cases we need to variable to keep the maxi and mini
 * 		and also the maximum sum that we can get.
 * 
 * 
 * -> 	Hence thats the code and thats the whole logic !
 
 */
void solve() {
	int n; cin>>n;
	
	vi a(n);
	per(i,0,n) cin>>a[i];
	reverse(all(a));
	
	int sum=0;
	rep(i,0,n){
		if(i & 1){
			sum-=a[i];
		}
		else sum+=a[i];
	}
	
	int maxi=-1e18,mini=1e18;
	int val=0;
	rep(i,0,n){
		if(i & 1){
			maxi=max(maxi,2*a[i]-i);
			val=max(val,2*a[i]+i-mini);
		}
		else{
			mini=min(mini,2*a[i]+i);
			val=max(val,maxi-(2*a[i]-i));
		}
	}
	
	int ans=max({sum,sum+val,sum+((n%2==0)? n-2: n-1)});
	cout<<ans<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}

