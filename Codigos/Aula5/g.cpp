#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
using namespace std;

const int MAXN = 2e5 + 5;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,q; cin >> n >> k >> q;

    vi cnt_temp(MAXN); // pra cada temperatura contar em quantas receitas aparece

    while(n--){
        int l,r; cin >> l >> r;
        cnt_temp[l]++;
        cnt_temp[r + 1]--;
    }

    for(int i = 1; i < MAXN;i++) cnt_temp[i] += cnt_temp[i - 1];
    
    vi admi(MAXN); // pra cada temperatura 1 - se for admissivel e 0 - cc
    for(int i = 1; i < MAXN;i++) {
        admi[i] = (cnt_temp[i] >= k);
    }

    vi ps(MAXN);
    for(int i = 1;i < MAXN;i++) ps[i] = ps[i - 1] + admi[i];

    while(q--){
        int a,b; cin >> a >> b;
        // dbg(ps[a]);
        // dbg(ps[b]);
        cout << ps[b] - ps[ a- 1] << endl;  
    }

    return 0;
}