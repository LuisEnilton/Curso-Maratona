#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi a (n);

    for(auto & x : a) cin >> x;

    int l = 0 ,r = n - 1;
    int sum1 = 0, sum3 = 0;
    int resposta = 0;

    while(l <= r){
        // se a soma no prefixo é menor que no sufixo eu adiciono no prefixo
        if(sum1 <= sum3){
            sum1 += a[l++];
        }else{
            sum3 += a[r--];
        }
        if(sum1 == sum3) resposta = max(resposta,sum1);
    }

    cout << resposta << endl;
    return 0;
}