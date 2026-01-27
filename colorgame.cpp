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
    -> One observation is that when alice chooses three balls Bob has
    two choices that he can do 
            -> One choice is that he can choose the largest element in
            the array for that condition alice have pick balls such that
            ai + aj + ak> an. For alice to win.

            -> Other choice for Bob is that he can choose the largest 
            number from the alice red balls , for these condition
            alice have pick balls in such a way that ai + aj > ak, for
            alice to win.

    -> Here is n is upto 5000 which means we can go n^2 easily but we cannot
    check for all the i, j, k because that will cause us n^3 which is not
    feasable here so we can try bs on the array to find the index k.
*/
void solve() {
    ll n;
    cin>>n;

    vil a(n);
    rep(i,0,n-1) cin>>a[i];

    ll ans=0;
    rep(i,0,n-1){
        rep(j,i+1,n-1){
            auto it=lower_bound(a.begin()+j+1,a.end(),a[i]+a[j]);
            it--;
            ll ind1=it-a.begin();

            auto it1=upper_bound(a.begin()+j+1,a.begin()+ind1+1,a[n-1]-a[i]-a[j]);
            if(it1==a.begin() or it1==a.end()) continue;
            ll ind2=it1-a.begin();

            ans+=(abs(ind1-ind2+1));
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