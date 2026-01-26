/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!"
 * -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;


// ---------- DEBUG TEMPLATE ----------
#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long x) {cerr << x;}
void _print(int x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(string x) {cerr << '"' << x << '"';}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template<class T, class V> void _print(const pair<T, V> &p);
template<class T> void _print(const vector<T> &v);
template<class T> void _print(const set<T> &v);
template<class T, class V> void _print(const map<T, V> &v);
template<class T, class V> void _print(const unordered_map<T, V> &v);
template<class T> void _print(stack<T> s);
template<class T> void _print(queue<T> q);

template<class T, class V> void _print(const pair<T, V> &p) {
    cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}";
}
template<class T> void _print(const vector<T> &v) {
    cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(const set<T> &v) {
    cerr << "{ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "}";
}
template<class T, class V> void _print(const map<T, V> &v) {
    cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T, class V> void _print(const unordered_map<T, V> &v) {
    cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(stack<T> s) {
    vector<T> res; while (!s.empty()) { res.push_back(s.top()); s.pop(); }
    reverse(res.begin(), res.end()); cerr << "top->"; _print(res);
}
template<class T> void _print(queue<T> q) {
    vector<T> res; while (!q.empty()) { res.push_back(q.front()); q.pop(); }
    cerr << "front->"; _print(res);
}
// ---------- END DEBUG TEMPLATE ----------


using ll=long long;
using pi=pair<int,int>;
using vi=vector<int>;
using vii=vector<pair<int,int>>;
using vil=vector<ll>;
using pil=pair<ll,ll>;
using viil=vector<pair<ll,ll>>;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define Ceil(a,b) ((a+b-1)/b)
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
    -> Given two number n and k, we need to find the number of good 
    sequences between 1 to n.
        -> a good sequence means an (i+1 th number) % (i th number) is 0.

    -> And the length of the  sequence have to be k. And we need to find
    the total number of good sequence.

    -> N and K is up to 1e3 so n^2 can be passed and even n^2logn willbe
    passed.

    -> So according the constraints and the question we can use a tabular
    method to find the number of good sequence.
            -> Like we can create a 2d dp that stores like ex - we can say
            dp[i][j] , where i is the length of the sequence and j is the 
            last val that is appended .
            
            -> dp[i][j] tells us that how many good sequence are there that
            with length i and ends with val j.

            -> Then we can find the numbers that is factors of j and add the 
            contribution of that number to the length.

    -> The time complexity is n*k sqrt(n).
*/
void solve() {
    int n,k;
    cin>>n>>k;

    const int mod=1e9+7;
    vector<vi> dp(k+1,vi (n+1,0));  
    rep(i,1,n){
        dp[1][i]=1;
    }

    rep(i,1,k){
        rep(j,1,n){
            rep(p,1,sqrt(j)){
                if(j % p==0){
                    dp[i][j]=(dp[i][j]+dp[i-1][p]) % mod;

                    if(p * p!=j){
                        dp[i][j]=(dp[i][j]+dp[i-1][j/p]) % mod;
                    }
                }
            }
        }
    }

    int ans=0;
    rep(i,1,n){
        ans=(ans+dp[k][i]) % mod;
    }

    cout<<ans<<endl;
}

int32_t main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}