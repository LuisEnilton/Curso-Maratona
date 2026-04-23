#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    int m;
    cin >> m;
    bool caps = 0; // ta minusculo?
    string resposta;
    while (m--)
    {

        string tecla;
        cin >> tecla;

        if (tecla == "Backspace")
        {
            if (resposta.size() > 0)
                resposta.pop_back();

            continue;
        }

        if (tecla == "Space")
        {
            resposta += " ";

            continue;
        }

        if (tecla == "CapsLock")
        {

            caps = !caps;

            continue;
        }

        if (caps)
        {
            char aux = (tecla[0] - 'a') + 'A';
            resposta += aux;
        }
        else
        {
            resposta += tecla;
        }
    }
    cout << (s == resposta ? "Correct":"Incorrect") << endl;
    return 0;
}