/*   coded by apoorv_me😎😎   */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pii pair<int, int>
#define vi vector < int >
#define vpi vector <pair <int , int > >
#define pll pair<ll, ll>
#define vl vector < ll >
#define vpl vector <pair <ll , ll > >
#define vb vector<bool>

#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define T third
#define setbit(x) __builtin_popcountll((ll)x)
#define b_ctz(x)   __builtin_ctzll(ll(x))
#define log_2(x)    63 - __builtin_clzll(ll(x))
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)((a).size()))

//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}

// Input Operatirons Pair, Vector
template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a){in >> a.F >> a.S;return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}

// Output Operations Pair, Vector
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a){os << a.F << " " << a.S;return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){for(int i = 0 ; i < sz(a) ; i++){if(i != 0){os << ' ';}os << a[i];}return os;}

#ifdef APOORV
#include "debug.h"
#else
#define dbg(x) "11-111"
#endif

const ll INF = 4e18;
// const ll mod = 1000000007;
// const ll mod = 998244353;
const ll MAX = 200005;
/*----------------------------------👁👁👁👁👁👁👁---------------------------------*/

void solve(int tt) {
    // ${0}
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef APOORV
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tt = 1;
    cin >> tt; // ${1}
    for(int t = 1; t <= tt ; t++){
        // cout << "Case #" << t << ": ";
        solve(t);
    }
    return 0;
}
