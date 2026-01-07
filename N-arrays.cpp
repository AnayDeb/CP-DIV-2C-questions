/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!"
 * -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
using pi=pair<int,int>;
using vi=vector<int>;
using vii=vector<pair<int,int>>;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back
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
   Observations:-
   -> In these question one main observation is one solution always exits
   which means we can find the first solution in the way that if keep
   the min elements in one array and the max elements in another array
   Hence we find the one solution but if we swap the elements again ,
   we get another solution, Hence it is proved that there are atleast 
   two solution.

   -> Now whether there are other solution present or not we can simply
   compare the maxi element with the next mini element if it is less
   than equal then we can multiply the ans with 2.

   !! simple Implementation.
*/
void solve() {
    const int mod=998244353;
    int n; cin>>n;

    vi a(n),b(n);
    rep(i,0,n-1) cin>>a[i];
    rep(i,0,n-1) cin>>b[i];

    rep(i,0,n-1){
        if(a[i]>b[i]) swap(a[i],b[i]);
    }

    int ans=2;
    rep(i,1,n-1){
        int maxi=max(a[i-1],b[i-1]);
        int mini=min(a[i],b[i]);

        if(maxi<=mini) ans=(ans*2)%mod;
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