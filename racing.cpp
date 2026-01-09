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
   -> These is a overlapping segment problem , so we will try
   to keep the possible range the drone can go and then try to
   find the answer of d[i] through backtracking from last.

   -> In the implementation , we will basically we will store the 
   possible range the drone can go through overlapping of segment
   and then from the last segmment , we will check its earlier 
   element if the earlier elements r is greater than or equal to 
   the current then we will update d[i] as 0 and 1 otherwise.
*/
void solve() {
    int n; cin>>n;

    vi d(n+1);
    rep(i,1,n) cin>>d[i];

    vector<pi> v(n+1);
    rep(i,1,n) {
        int l,r;
        cin>>l>>r;
        v[i]={l,r};
    }

    int l=0,r=0;
    vector<pi> ran;
    ran.pb({0,0});
    rep(i,1,n){
        if(d[i]==-1) r+=1;
        else if(d[i]==1) {l+=1; r+=1;}

        int l1=v[i].first,r1=v[i].second;

        int newl=max(l,l1);
        int newr=min(r,r1);

        if(newl>newr){
            cout<<-1<<endl;
            return;
        }

        ran.pb({newl,newr});
        l=newl,r=newr;
    }
    debug(ran);

    int pos=ran.back().second;
    debug(pos);
    deque<int>ans;
    per(i,ran.size()-1,2){
        if(d[i]!=-1){
            ans.push_front(d[i]);
            if(d[i]) pos-=1;
            continue;
        }

        if(ran[i-1].second>=pos) ans.push_front(0);
        else {ans.push_front(1); pos-=1;}
    }

    if(d[1]==-1){
        if(pos<=0) ans.push_front(0);
        else ans.push_front(1);
    }
    else{
        ans.push_front(d[1]);
    } 
    
    for(auto i:ans) cout<<i<<" ";
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