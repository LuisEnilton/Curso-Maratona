#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int> freq; // contar a frequencia de cada cara
    int n; cin >> n;
    /*
        Em c++ qualquer valor diferente de 0 é true

        if(0)

    */
   // 3 2 1 0
    while(n--){
        int q; cin >> q;
        while(q--){
            string s; cin >> s;
            freq[s]++;
        }
    }

    for(auto &[nome,qtd] : freq){
        cout << nome << " " << qtd << endl;
    }

    return 0;
}