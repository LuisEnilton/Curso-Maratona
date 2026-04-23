    #include <bits/stdc++.h>
    #define endl '\n'
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin >> t;
        while (t--)
        {

            int n;
            cin >> n;
            int resposta = 180;

            int atualmente = 3;

            resposta += (n - atualmente) * 180;
            resposta += (n - atualmente) * 180;
            cout << resposta << endl;
        }
        return 0;
    }