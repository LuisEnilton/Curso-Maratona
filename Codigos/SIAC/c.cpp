#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m; cin >> n >> m;

    vector<int> a(n), b(m);
    for(auto & x : a) cin >> x;
    queue<int> fila_de_reels;
    while(m--){
        int x; cin >> x;
        fila_de_reels.push(x);    
    }
    int B = 0; // dopamina atual
    double nota_atual = 0.0;
    // pra cada prova
    vector<double> resposta(n);
    for(int i = 0; i < n;i++){

        // B/a[i] * 10

        while(!fila_de_reels.empty() && nota_atual < 7.0){
            B += fila_de_reels.front();
            fila_de_reels.pop();
            nota_atual =  ((double) B/ a[i] ) * 10.0;
        }
        
        resposta[i] = min(10.0,nota_atual);

        nota_atual = 0;
        B =0;
    }

    for(auto x : resposta){
        cout << fixed << setprecision(6) << x << " ";
    }
    cout << endl;
    return 0;
}