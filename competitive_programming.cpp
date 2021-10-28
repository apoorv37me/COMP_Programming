#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ndl "\n"
#define MAX 10000001
#define pb push_back
#define mp make_pair
/*-------------------------------------------------------------------*/

// vector<int> Prime(MAX, 1);
// void sieve(){
//     Prime[0] = Prime[1] = 0;
//     for(int i=2;i<MAX;i++){
//         if(Prime[i]==1){
//             for(int j=i*i;j<MAX && j>0;j+=i){
//                 Prime[j] = 0;
//             }
//         }
//     }
// }
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

void solve(){
    int t;cin>>t;
    while(t--){
        
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