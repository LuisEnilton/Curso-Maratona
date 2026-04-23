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
        string a, b;
        cin >> a >> b;
        vector<char> quem_ela_tem_que_virar(26, '*');
        vector<char> quem_ta_virando_ela(26, '*');
        int n = a.size();
        bool resposta = true;
        for (int i = 0; i < n; i++)
        {

            if (quem_ela_tem_que_virar[a[i] - 'a'] != '*' && quem_ela_tem_que_virar[a[i] - 'a'] != b[i])
            {
                resposta = 0;
                break;
            }

            if (quem_ta_virando_ela[b[i] - 'a'] != '*' && quem_ta_virando_ela[b[i] - 'a'] != a[i])
            {
                resposta = 0;
                break;
            }

            quem_ela_tem_que_virar[a[i] - 'a'] = b[i];
            quem_ta_virando_ela[b[i] - 'a'] = a[i];
        }
        cout << (resposta ? "YES" : "NO") << endl;
    }

    return 0;
}