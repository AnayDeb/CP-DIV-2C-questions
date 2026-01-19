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
   -> One observation is we cannot take all the possible tables and go
   on processing for the closest distance table or seat.
    
   -> But one thing we can do is that we can process the tables after
   we get one table just like a bfs we will take the closest tables
   and insert them in a priority queue and try to find the result
   according to the condition.
*/
void solve() {
    int n; 
    cin>>n;

    vi a(n);
    rep(i,0,n-1) cin>>a[i];

    // We will use sets instead of priority queue doing the same thing.
    set<vi>tables,seats;
    set<pi>s;// These set is to check if the table is checked earlier.

    auto push=[&](int x,int y)->void{
        if(s.find({x,y})!=s.end()) return;

        tables.insert({3*x+3*y+2,x,y});

        seats.insert({3*x+3*y+2,3*x+1,3*y+1});
        seats.insert({3*x+3*y+3,3*x+1,3*y+2});
        seats.insert({3*x+3*y+3,3*x+2,3*y+1});
        seats.insert({3*x+3*y+6,3*x+2,3*y+2});

        s.insert({x,y});
    };

    push(0,1);
    push(1,0);
    push(0,0);

    rep(i,0,n-1){
        if(a[i]==0){
            auto top=*tables.begin();
            tables.erase(top);

            int x=top[1],y=top[2];
            seats.erase({3*x+3*y+2,3*x+1,3*y+1});
            cout<<3*x+1<<" "<<3*y+1<<endl;

            push(x+1,y+1);
            push(x+1,y);
            push(x+2,y);
            push(x,y+1);
            push(x,y+2);
        }
        else{
            auto top=*seats.begin();
            seats.erase(top);

            int x=top[1]/3,y=top[2]/3;
            tables.erase({3*x+3*y+2,x,y});

            cout<<top[1]<<" "<<top[2]<<endl;

            push(x+1,y+1);
            push(x+1,y);
            push(x+2,y);
            push(x,y+1);
            push(x,y+2);
        }
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