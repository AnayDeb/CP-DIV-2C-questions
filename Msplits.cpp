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
   -> The equation is given as med(med(a1...al),med(al+1...ar),med(ar+1...an))
   So,observing the equation we can say that the last med() will have
   3 values and out of that 3 vals two should be less than k then only
   it is "YES" else it is "NO".


*/
void solve() {
    int n,k;
    cin>>n>>k;

    vi a(n);
    rep(i,0,n-1) cin>>a[i];

    auto find=[&](int start,int dir)->int{
        int cnt=0;
        for(int i=start;i>=0 and i<n;i+=dir){
            cnt+=(a[i]<=k);
            cnt-=(a[i]>k);
            if(cnt>=0){
                return i;
            }
        }
        return (dir==1?n:-1);
    };

    auto first2=[&]()->bool{
        int l=find(0,1);
        if(l%2==0 and l+1<n and a[l+1]>k) l++;
        int r=find(l+1,1);
        return r<n-1;
    };

    auto last2=[&]()->bool{
        int r=find(n-1,-1);
        if((n-r)%2 and r-1>=0 and a[r-1]>k) r--;
        int l=find(r-1,-1);
        return l>0;
    };

    auto end2=[&]()->bool{
        int l=find(0,1);
        int r=find(n-1,-1);
        return r>l+1;
    };

    bool ans=first2() or last2() or end2();
    cout<<(ans?"YES":"NO")<<endl;
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