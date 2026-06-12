#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
using namespace std;

const int MAXN = 1e6 + 5;
vector<pair<int, int>> grafo[MAXN]; // um array em que cada posição, eu guarda pra um vertice quem ele se liga

// custo de andar nesse sentido
int dfs(int u, int anterior)
{
    if(u == 1) return 0;
    for (auto [v, w] : grafo[u])
    {
        if (v == anterior)
            continue;
        return w + dfs(v, u);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m = n;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        grafo[u].emplace_back(v, 0);
        grafo[v].emplace_back(u, w); // custo de inverter a aresta
    }

    // definir um vertice de inicio
    int ans = INT_MAX;
    for (auto [v, w] : grafo[1])
    {
        ans = min(ans, w + dfs(v, 1));
    }

    cout << ans << endl;
    return 0;
}