//
// Created by Luis on 06/09/2023.
//
// Template By eduardocesb
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) x.begin(), x.end()
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define INF 1000000010
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define vii vector<pii>
#define PB push_back
#define EB emplace_back
#define INF 1000000010
#define INFLL 1000000000000000010LL
#define MAXN 200010
#define endl '\n'
#define int long long
using namespace std;

bool isBarramento(vi &grau, int n)
{

    int cnt2 = 0;
    int cnt1 = 0;
    for (auto x : grau)
    {
        if (x == 2)
            cnt2++;
        if (x == 1)
            cnt1++;
    }

    if (cnt1 == 2 && cnt2 + cnt1 == n)
        return true;

    return false;
}

bool isAnel(vi &grau, int n)
{
    int cnt2 = 0;
    for (auto x : grau)
    {
        if (x == 2)
            cnt2++;
    }

    if (cnt2 == n)
        return true;

    return false;
}

bool isEstrela(vi &grau, int n)
{
    int cnt1 = 0;
    int val = -1;
    for (auto x : grau)
    {
        if (x == 1)
            cnt1++;
        else
            val = x;
    }

    if (cnt1 == n - 1 && val == n - 1)
        return true;

    return false;
}

signed main()
{
    optimize;
    int n, m;
    cin >> n >> m;
    vi grau(n + 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        grau[u]++;
        grau[v]++;
    }
    if (isBarramento(grau, n))
    {
        cout << "bus topology" << endl;
        return 0;
    }

    if (isAnel(grau, n))
    {
        cout << "ring topology" << endl;
        return 0;
    }

    if (isEstrela(grau, n))
    {
        cout << "star topology" << endl;
        return 0;
    }

    cout << "unknown topology" << endl;

    return 0;
}