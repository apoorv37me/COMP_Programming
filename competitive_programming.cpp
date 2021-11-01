#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ndl "\n"
#define MAX 1000001
#define pb push_back
#define mp make_pair
const int MOD = 998244353;
void addedge_undirected(vector<int> adj[], int i, int j){
    adj[i].pb(j);
    adj[j].pb(i);
}
vector<int> Prime(MAX, 1);
void sieve(){
    Prime[0] = Prime[1] = 0;
    for(int i=2;i<MAX;i++){
        if(Prime[i]){
            for(int j=i*i;j<MAX && j>0;j+=i){
                Prime[j] = 0;
            }
        }
    }
}
string decimaltobinary(ll n){
    string s;
    while(n>0){
        char c = '0' + n%2;
        s.push_back(c);
        n = n / 2;
    }
    return s;
}

bool checkpallindrome(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i]!=s[s.size()-i-1])
            return false;
    }
    return true;
}

ll power(ll a, ll b){
    if(b==0)    return 1;
    if(b==1)    return a;
    ll x = power(a, b/2);
    if(b%2==0){
        return x*x;
    }
    
    return a*x*x;
}

ll powermod(ll a,ll b){
    ll res = 1;
    while(b > 0){
        if(b&1)
            res = res*a;
        b = b / 2;
        a = a*a;
        a = a%MOD;
        res = res%MOD;
    }
    return res;
}
/*-------------------------------------------------------------------*/

void bfs(vector<vector<char>> &board, int i, int j, char a, char b){
    int n = board.size();
    int m = board[0].size();
    queue<pii> q;
    q.push(mp(i, j));
    board[i][j] = b;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p.first-1>=0 && board[p.first-1][p.second]==a){
            q.push(mp(p.first-1,p.second));
            board[p.first-1][p.second] = b;
        }
        if(p.first+1<n && board[p.first+1][p.second]==a){
            q.push(mp(p.first+1,p.second));
            board[p.first+1][p.second] = b;
        }
        if(p.second-1>=0 && board[p.first][p.second-1]==a){
            q.push(mp(p.first,p.second-1));
            board[p.first][p.second-1] = b;
        }
        if(p.second+1<m && board[p.first][p.second+1]==a){
            q.push(mp(p.first,p.second+1));
            board[p.first][p.second+1] = b;
        }
    }
}

void bfs_adjmat(vector<int> adj[], int i,int v, bool visited[])
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &it: adj[u]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0; i < m ; i++){
        int a, b;
        cin>>a>>b;
        addedge_undirected(adj, a-1, b-1);
    }
    vector<int> sol;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            sol.pb(i+1);
            bfs_adjmat(adj, i, n, visited);
        }
    }
    cout<<sol.size()-1<<ndl;
    for(int i = 1; i < sol.size(); i++){
        cout<<sol[0]<<" "<<sol[i]<<ndl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}