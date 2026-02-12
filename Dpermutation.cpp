/*
 -> Anay Deb
 -> "Everything is EASY... just needs a little time!"
 -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;


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
    -> a permutation given 1...n.
    Have to process n query .
    For ith query replace pi with 0 .

    Each element is replaced with 0 exactly once.

    After each query i need to find the minimum number of ops 
    required to fix the array in to a permutation.
            One operation to perform is choose integer i from n,
            replace ith element with i.
    
    (1<=n<=1e5) , On or max Onlogn can be passed.

    Here basically the solution can be think as there are cycles
    dependency between the permutation we can see.

    so we can make them in DSU and keep them together.

    We need to find how many swaps needed so basically ,if we do one
    cycle then the whole numbers present in that cycle get the value.


*/
vi parent,sizep;
struct DSU{
    int findp(int u){
        if(parent[u]==u) return u;
        else return parent[u]=findp(parent[u]);
    }

    void unionp(int u,int v){
        int ul_v=findp(v);
        int ul_u=findp(u);

        if(ul_u==ul_v) return;

        if(sizep[ul_u]>sizep[ul_v]){
            parent[ul_v]=ul_u;
            sizep[ul_u]+=sizep[ul_v];
        }
        else if(sizep[ul_u]<sizep[ul_v]){
            parent[ul_u]=ul_v;
            sizep[ul_v]+=sizep[ul_u];
        }
        else{
            parent[ul_u]=ul_v;
            sizep[ul_v]+=sizep[ul_u];
        }
    }
};
void solve() {
    int n;
    cin>>n;

    vi a(n),b(n);
    rep(i,0,n-1) cin>>a[i];
    rep(i,0,n-1) cin>>b[i];

    parent.clear();
    sizep.clear();
    parent.resize(n+1);
    sizep.resize(n+1,1);

    rep(i,0,n){
        parent[i]=i;
    }

    DSU d;
    rep(i,0,n-1){
        d.unionp(a[i],i+1);
    }

    map<int,bool>vis;
    vi ans(n+1,0);
    rep(i,1,n){
        int curr=b[i-1];

        int par=d.findp(curr);
        if(!vis[par]){
            ans[i]+=sizep[par]+ans[i-1];
            vis[par]=true;
        }
        else{
            ans[i]+=ans[i-1];
        }
    }

    rep(i,1,n){
        cout<<ans[i]<<" ";
    }
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