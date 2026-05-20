#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int,int>> pessoas(n);

    for(auto &[l,r] : pessoas) cin >> l >> r;

    sort(pessoas.begin(),pessoas.end());
    int resposta = 0;
    int maior_tempo_de_saida = 0;
    for(auto [l,r] : pessoas){

        if(r < maior_tempo_de_saida) resposta++;

        // salvar ele pra poder comparar com os posteriores
        maior_tempo_de_saida = max(maior_tempo_de_saida,r);
    }
    cout << resposta << endl;


    return 0;
}