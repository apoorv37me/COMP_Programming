/*   coded by apoorv_me😎😎   */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pii pair<ll, ll>
#define vi vector < ll >
#define vpi vector <pair <ll , ll > >

#define ndl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define T third
#define all(a) (a).begin(), (a).end()
#define scan(arr, n)   for (ll INPUT = 0; INPUT < n; INPUT++) cin >> arr[INPUT];
#define sz(a) (ll)((a).size())

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " ";_print_(x);cerr << endl;
#else
#define dbg(x)
#endif

void _print_(ll t) {cerr << t;}
void _print_(int t) {cerr << t;}
void _print_(string t) {cerr << t;}
void _print_(char t) {cerr << t;}
void _print_(ld t) {cerr << t;}
void _print_(double t) {cerr << t;}
 
template <class T, class V> void _print_(pair <T, V> p);
template <class T> void _print_(vector <T> v);
template <class T> void _print_(set <T> v);
template <class T, class V> void _print_(map <T, V> v);
template <class T> void _print_(multiset <T> v);
template <class T, class V> void _print_(pair <T, V> p) {cerr << "{"; _print_(p.F); cerr << ","; _print_(p.S); cerr << "}";}
template <class T> void _print_(vector <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(set <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T> void _print_(multiset <T> v) {cerr << "[ "; for (T i : v) {_print_(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print_(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print_(i); cerr << " ";} cerr << "]";}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 1e18;
const ll mod = 998244353;
const ll MAX = 500005; // 100100
/*-------------------------------------------------------------------*/


void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tt = 1;
    cin >> tt;
    for(int t = 1; t <= tt ; t++){
        // cout << "Case #" << t << " : ";
        solve();
    }
    return 0;
}
