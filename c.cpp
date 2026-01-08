/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!"
 * -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
   -> The test case 4 3 3.
   lets say mid is 3 then lets frame the answer accordingly.
   k is 3 then, l=k-2/2.. which is 1, then 1,2(l),3,4.
   and r by formula is 1, so r goes up to 4, which means 1,2(l),3,4(r);
   
   -> so the cost according the formula is l-1+max(l,r)+r,which is
   0+1+1=2 which is less than equal to m(cost<=m). returns true;
   
   -> Lets see for mid = 4, then l=1 and r=2 according to formula.
   r cannot go k+r because k+r>n then r=1, and l+=1; so r=1 and l=2,
   then 1(l),2,3(k),r(l). The cost will be 1+2+1=4 greater than m(4>m),
   returns false, Hence the answer is 3.
*/
void solve() {
    int n,m,k;
    cin>>n>>m>>k;

    auto check=[&](int mid)->bool{
        int cost=INT_MAX;
        for(int l=1,r=mid;r<=n;r+=1,l+=1){
            if(l>k) break;
            if(r<k) continue;

            int left=k-l;
            int right=r-k;
            cost=min(cost,left-1+max(left,right)+right);
        }

        return cost<=m;
    };

    int start=1,end=n,ans=-1;
    while(start<=end){
        int mid=(start+end)/2;

        if(check(mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
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