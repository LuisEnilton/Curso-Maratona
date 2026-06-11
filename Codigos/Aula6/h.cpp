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

    int n, t;
    cin >> n >> t;
    vi a(n);

    for (auto &x : a)
        cin >> x;

    int l = 0;
    // pra cada r, calcula o menor l que satisfaz a soma
    int soma = 0;
    int resposta = 0;
    for (int r = 0; r < n; r++)
    {
        soma += a[r];

        while (l < r && soma > t)
        {
            soma -= a[l++];
        }
        if (soma <= t)
            resposta = max(resposta, r - l + 1);
    }
    cout << resposta << endl;

    return 0;
}