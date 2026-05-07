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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> pilha;
        for (char c : s)
        {

            if (pilha.empty() || pilha.top() != c)
            {
                pilha.push(c);
            }
            else
            {
                pilha.pop();
            }
        }

        cout << (pilha.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}