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
   -> One main observation is we can think these as a diagram where
   two days are connected with the bets true or false, if two days has
   four edges of true, false with each other that means we can always
   gurantee the solution of one of the bet.

   -> Another observation is that we can get another way to get the 
   bet prediction right , If we have two days where there are more than
   equal to 2 days edges we can connect them to make the answer 
   predictable.

   -> These is the main idea rest implementation is easy and simple.
*/
void solve() {
    ll n; cin>>n;

    vil a(n);
    rep(i,0,n-1) cin>>a[i];

    vil v;
    rep(i,0,n-1){
        ll one=a[i]+1,two=a[i]+2;

        v.pb(one),v.pb(two);
    }

    sort(all(v));

    vil edges;
    ll cnt=1;
    rep(i,1,v.size()-1){
        if(v[i]==v[i-1]){
            cnt+=1;
        }
        else{
            edges.pb(cnt);
            cnt=1;
        }
    }
    edges.pb(cnt);

    vector<vi>e;
    vi temp;
    rep(i,1,edges.size()-1){
        if(edges[i-1]==0){
            e.pb(temp);
            temp.clear();
            continue;
        }

        if(edges[i]<=edges[i-1]){
            temp.pb(edges[i-1]);
            edges[i]-=edges[i-1];
        }
        else{
            temp.pb(edges[i-1]);
            edges[i]-=edges[i-1];   
        }
    }
    e.pb(temp);
    debug(e);

    for(auto i:e){
        map<int,int>freq;
        for(auto j:i){
            freq[j]++;
        }

        bool f=false;
        int c=0;
        for(auto j:freq){
            if(j.first>=2) c+=1;
            if(j.first>=4) {f=true; break;}
            if(j.first>=2 and j.second>=2) {f=true; break;}
        }

        if(f or c>=2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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