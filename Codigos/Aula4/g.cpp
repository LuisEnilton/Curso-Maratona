#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void print_arr(vector<int> &a)
{

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    map<int, pair<int, int>> falta; // (id,quanto falta)
    int id = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (falta.count(x))
        {
            auto &[id_atual, qtd] = falta[x];
            ans[i] = id_atual;
            qtd--;
            if (qtd == 0)
                falta.erase(x);
        }
        else
        {
            ans[i] = id;
            if (x > 1)
                falta[x] = {id, x - 1};
            id++;
        }
    }
    // se tem alguem no mapa
    if(!falta.empty()){
        cout << -1 << endl;
        return;
    }
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}