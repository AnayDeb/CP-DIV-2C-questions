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
    -> n coins - a1,a2,a3..an.
    natural number - k

    -> we can perform exactly k operations.
            In one operation, pick one coin from that i have and
            put them in bag.

            After the coin is in bag i cannot use that coin.
    
    -> When the sum of coins in bag becomes even it becomes empty.

    -> Score is defined as the maximum sum of coins in the bag
            -> I need to maximise the sum without making it even
            for all indices.

    -> Ex- <1,2,3>
    here n is 3 so, for k=1, we can choose the max odd that is 3

                    for k=2, we can choose max odd and max even making
                    the sum odd. ans is 3+2=5.

                    for k=3, we have to put the whole array 
                    which will be even in every case so ans is 0.
    
    

*/
void solve() {
    int n; 
    cin>>n;

    vil a(n),odd,even;
    rep(i,0,n-1) {
        cin>>a[i];

        if(a[i] & 1) odd.pb(a[i]);
        else even.pb(a[i]);
    }

    ll os=odd.size(),es=even.size();
    if(os==n){
        int maxi=*max_element(all(odd));
        rep(i,1,n){
            if(i & 1) cout<<maxi<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
        return;
    }

    if(es==n){
        rep(i,1,n){
            cout<<0<<" ";
        }
        cout<<endl;
        return;
    }

    sort(all(odd));
    sort(all(even));
    ll score=*max_element(all(odd));
    vil ans(n+1);
    ans[1]=score;

    rep(i,2,n){
        if(even.size()==0){
            ans[i]=ans[i-2];
        }
        else{
            ans[i]=ans[i-1]+even.back();
            even.pop_back();
        }
    }

    if(accumulate(all(a),0LL) & 1 ^ 1){
        ans[n]=0;
    }

    rep(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;
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