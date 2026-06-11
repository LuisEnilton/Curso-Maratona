#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
using namespace std;


// transformando b pra a
int solve_a(int n, int k, string s){


    int cnt = 0; // contador de b
    int l = 0;
    // pra cada r o menor l tal que cnt <= k
    int ans = 0;
    for(int r = 0; r < n;r++){
        if(s[r] == 'b') cnt++;

        // corrigir a condição
        while(l < r && cnt > k){
            if(s[l] == 'b') cnt--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}
// transformando a pra b
int solve_b(int n, int k, string s){
    int cnt = 0; // contador de a
    int l = 0;
    // pra cada r o menor l tal que cnt <= k
    int ans = 0;
    for(int r = 0; r < n;r++){
        if(s[r] == 'a') cnt++;

        // corrigir a condição
        while(l < r && cnt > k){
            if(s[l] == 'a') cnt--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k; cin >> n >> k;

    string s; cin >> s;
    cout << max(solve_a(n,k,s),solve_b(n,k,s)) << endl;
    return 0;
}