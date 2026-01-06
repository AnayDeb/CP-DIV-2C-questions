/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!"
 * -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
   -> We can make every array gcd=1 , if the gcd is 1,fine good
   else we can find the gcd , divide every element by it to make the 
   all elements gcd 1.

   -> What will then we do?
   we will then run a bfs to find the min operations to reach 
   gcd==1. 

   -> If gcd 1 is present in the array we will need just n-cnt of ones.
*/
void solve() {
    int n; cin>>n;

    int g=0;
    vi a(n);
    rep(i,0,n-1) { cin>>a[i]; g=gcd(g,a[i]);}

    rep(i,0,n-1) a[i]/=g;

    int one=0;
    rep(i,0,n-1){
        if(a[i]==1) one+=1;
    }
    if(one>=1){
        cout<<n-one<<endl;
        return;
    }

    int maxi=*max_element(all(a));
    vi mini(maxi+1,1e9);
    queue<int>q;
    rep(i,0,n-1){ mini[a[i]]=0; q.push(a[i]);}

    while(!q.empty()){
        auto front=q.front();
        q.pop();

        for(auto i:a){
            int b=gcd(i,front);
            if(mini[b]==1e9){
                mini[b]=1+mini[front];
                q.push(b);
            }
        }
    }

    cout<<n-1+mini[1]<<endl;
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