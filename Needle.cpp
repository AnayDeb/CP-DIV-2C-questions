/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!" 
 * -> Lets Fucking GOO!!
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
#define rep(i,a,b) for(int i = (a); i <=(b); ++i)
#define per(i,a,b) for(int i= (a); i>=(b); --i)
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
/* Observations:
 * babadab
 * abacabadabacaba
 * a-> 8,b-> 4,c-> 2,d-> 1
 * a-> 3,b-> 3,d-> 1
 * ->	One observation is that we can greedily make the string from 
 * the front.
 * 
 * Main Logic:
 * -> 	Simple looping from the front and seeing for the best possible
 * char at that point.
 */
void solve() {
	string s,t;
	cin>>s>>t;
	
	map<char,int>one,two;
	rep(i,0,s.size()-1) one[s[i]]+=1;
	rep(i,0,t.size()-1) two[t[i]]+=1;
	
	bool f=true;
	for(auto i:one){
		if(i.second>two[i.first]){
			f=false;
			break;
		}
	}
	
	if(!f){
		cout<<"Impossible"<<endl;
		return;
	}
	
	string ans="";
	int j=0;
	rep(i,0,t.size()-1){
		for(char c='a';c<='z';++c){
			if(two[c]==0) continue;
			
			if(one[c]<=two[c] and s[j]==c){
				ans+=c;
				one[c]-=1;
				two[c]-=1;
				j+=1;
				break;
			}
			
			if(two[c]>one[c]){
				ans+=c;
				two[c]-=1;
				break;
			}
		}
	}
	
	cout<<ans<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    cin >> t;
    while(t--) { 
		solve();
	}
	
    return 0;
}

