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
 * -> 	Case odd:
 * ->	One observation is if n is odd then the answer can always be l
 * 		because the AND and XOR value becomes same.
 * 		->	Lets take a example lets say l is 3 and r is 5.
 * 			and n is odd (3). so the array can be written as 
 * 			a=[3,3,3] , because AND of 3 & 3 & 3 is 3, whereas xor
 * 			of 3 ^ 3 ^ 3 is also 3 which makes it the lexicographically 
 * 			smallest.
 * 
 * ->	Case even:
 * ->	One observation here is if we have a l and r, if we take l as one number
 * 		and we can take another number as 2^some power that is less than equal to
 * 		r and greater than l, which will give a solution.
 * 		-> 	But if there is no 2^some power less than equal to r then there is no 
 * 			solution.
 * 		-> 	else we can construct the solution as lets say n is 6 then the array 
 * 			willbe lets take an example (n is 6 and l is 5 and r is 10), then the 
 * 			answer can be written as a=[5,5,5,5,8,8].
 * 		-> 	Lets see the proof-> 
 * 				->	if we take 5 & 5 & 5 & 5 & 8 & 8 , we will get 0.
 * 				-> 	if we take 5 ^ 5 ^ 5 ^ 5 ^ 8 ^ 8 , we will get 0.
 * 		-> 	And these is the most optimal lexical answer.
 * 			
 * Main Logic:
 * 		-> If n is odd simply cout l 
 * 		-> else:
 * 				-> if AND val is greater than zero then it is -1.
 * 				-> else solution is possible by the observations.
 */
void solve() {
	int n,l,r,k;
	cin>>n>>l>>r>>k;
	
	if(n & 1){
		cout<<l<<endl;
		return;
	}
	else{
		if(n==2){
			cout<<-1<<endl;
			return;
		}
		int ok=2;
		while(ok<=r/2){
			if(ok>l) break;
			ok*=2;
		}
		//cout<<"This is it->"<<ok<<endl;
		if(ok>l and ok<=r){
			if(k==n or k==n-1){
				cout<<ok<<endl;
				return;
			}
			else {
				cout<<l<<endl;
				return;
			}
		}
		else{
			cout<<-1<<endl;
			return;
		}
	}
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

