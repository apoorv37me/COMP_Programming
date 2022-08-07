/*   coded by apoorv_me   */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using minheap = priority_queue<T,vector<T>,greater<T> >; 

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
#define pii pair<int, int>
#define vi vector < int >
#define vpi vector <pair <int , int > >
#define pll pair<ll, ll>
#define vl vector < ll >
#define vpl vector <pair <ll , ll > >
#define vb vector<bool>
#define vm vector<mi>
template<int T> using ai = array<int, T>;
template<int T> using al = array<ll, T>;
template<int T> using val = vector<array<ll, T>>;
template<int T> using vai = vector<array<int, T>>;

#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define setbit(x) __builtin_popcountll(x)
#define b_ctz(x)   __builtin_ctzll(x)
#define ln2(x)    63 - __builtin_clzll(x)
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)((a).size()))
#define bs binary_search

//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}

// Input Operatirons Pair, Vector
template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a){in >> a.F >> a.S;return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}

// Output Operations Pair Vector
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a){os << a.F << " " << a.S;return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){for(int i = 0 ; i < sz(a) ; i++){if(i != 0){os << ' ';}os << a[i];}return os;}

#ifdef APOORV
#include "../debug.h"
#else
#define dbg(...) "11-111"
#endif

const ll INF = 4e18;
// const ll mod = 1000000007;
// const ll mod = 998244353;
const int maxn = 1000005;
/*----------------------------------x---Code-Below---x--------------------------------*/
struct DSU {
    int n, cmps;
    vector<int> p, sub, cnt;
    DSU () {}
    DSU(int n_) : n(n_), cmps(n_) {
        p.resize(n+1);
        sub.resize(n+1, 1);
        cnt.resize(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int parent(int i) {
        assert(i <= n);
        return p[i] = (p[i] == i ? i : parent(p[i]));
    }
    bool check_edge(int i, int j) {
        return parent(i) == parent(j);
    }
    bool join(int x, int y) {
        assert(x <= n && y <= n);
        x = parent(x), y = parent(y);
        if(x == y) {
            return false;
        }
        --cmps;
        if(sub[x] > sub[y]) {
            swap(x, y);
        }
        sub[y] += sub[x];
        cnt[y] += cnt[x];
        cnt[x] = 0;
        p[x] = y;
        return true;
    }
};
void __solve_testcase(int test_case) {
    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    cin >> a;
    /*
        for A(i, j) > A(j, i) , join i - ~j and j - ~i 
        one of possible solutions exists
        for(A(i, j) < A(j, i)) join i - j , ~j - ~i
        ~j and ~i , represent swap with respest to ith and jth node is true
        j and i, represents swap with respest to ith and jth node is false 
    */
    DSU b(2 * n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            if(a[i][j] > a[j][i]) {
                dbg(i, j);
                if(b.check_edge(i + n, j + n) && b.check_edge(i, j))    continue;
                dbg(i, j);
                swap(a[i][j], a[j][i]);
                b.join(i + n, j);
                b.join(i, j + n);
            } else if(a[i][j] < a[j][i]){
                dbg(i, j);
                if(b.check_edge(i + n, j) && b.check_edge(i, j + n)) {
                    swap(a[i][j], a[j][i]);
                    continue;
                }
                dbg(i, j);
                b.join(i + n, j + n);
                b.join(i, j);
            }
        }
    }
    for(auto &i: a) {
        cout << i << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto precalc = [&]() {

    };    
    precalc();
    int no_of_testcase = 1;
    cin >> no_of_testcase;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        // cout << "Case #" << testcase << ": ";
        __solve_testcase(testcase);
    }
    return 0;
}