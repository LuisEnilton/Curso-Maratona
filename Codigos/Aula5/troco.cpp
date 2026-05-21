#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> frente(n), verso(n);
    for (auto &x : frente)
        cin >> x;
    for (auto &x : verso)
        cin >> x;

    vector<int> ps(n + 1); // array de diferencas

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        ps[l]++;
        ps[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        ps[i] += ps[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << (ps[i] % 2 == 0 ? frente[i] : verso[i]) << " ";
    }
    cout << endl;

    return 0;
}