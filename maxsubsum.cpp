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
   -> We can divide the array in to blocks of elements and if the blocks
   has more subarray sum than k ,then it is not possible to make the
   subarray sum equal to k.

   -> We will use only one zero to make our subarray sum equal to k,
   we will also make the other zeros -INF so that it does not contribute
   to another subarray and make it larger.

   -> For the one zero we will simply put the value of (k-pres-suffs),
   which means that at the zero we will find the max presum and max suff
   sum then we will replace that with that zero .
*/
void solve() {
    ll n,k;
    cin>>n>>k;
    const ll INF=-1e13;

    string s; cin>>s;

    vil a(n);
    rep(i,0,n-1) cin>>a[i];

    ll maxi=0,sum=0;
    rep(i,0,n-1){
        if(s[i]=='0') sum=0;
        else{
            sum=max(sum+a[i],a[i]);
            maxi=max(maxi,sum); 
        }
    }

    if(maxi>k){
        cout<<"NO"<<endl;
    }
    else if(maxi==k){
        cout<<"YES"<<endl;
        rep(i,0,n-1){
            if(s[i]=='0'){
                a[i]=INF;
            }
        }

        rep(i,0,n-1) cout<<a[i]<<" ";
        cout<<endl;
    }
    else{
        int zero=-1;
        rep(i,0,n-1){
            if(s[i]=='0'){
                zero=i;
                break;
            }
        }

        if(zero==-1) {
            cout<<"NO"<<endl;
            return;
        }
        
        int pres=0,sum=0,suffs=0;

        per(i,zero-1,0){
            if(s[i]=='0') break;
            else{
                sum+=a[i];
                pres=max(sum,pres);
            }
        }

        sum=0;
        rep(i,zero+1,n-1){
            if(s[i]=='0') break;
            else{
                sum+=a[i];
                suffs=max(suffs,sum);
            }
        }

        a[zero]=k-pres-suffs;

        rep(i,0,n-1){
            if(s[i]=='0' and i!=zero){
                a[i]=INF;
            }
        }

        cout<<"YES"<<endl;
        rep(i,0,n-1) cout<<a[i]<<" ";
        cout<<endl;
    }
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