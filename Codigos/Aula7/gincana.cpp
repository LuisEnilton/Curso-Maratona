#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
using namespace std;

const int MAXN = 1e6 + 5;
vi grafo[MAXN]; // um array em que cada posição, eu guarda pra um vertice quem ele se liga
bool visitado[MAXN];

void dfs(int u)
{
    visitado[u] = true;
    for (int v : grafo[u])
    {
        if (visitado[v])
            continue;
        dfs(v);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    // pra cada cara eu quero marcar todo mundo na componente dele
    int qtd_times = 0;
    // O(N + 2*M) = O(N + M)
    for (int vertice = 1; vertice <= n; vertice++)
    {
        // se um cara foi visitado, ele já tem um time
        if (visitado[vertice])
            continue;
        qtd_times++;
        dfs(vertice);
    }
    cout << qtd_times << endl;

    return 0;
}