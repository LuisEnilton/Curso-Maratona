#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <=n;i++) cin >> a[i];
    queue<int> fila;
    // 1 2 3 4 5
    for(int i = 1; i <=n;i++){
        fila.push(i);
    }

    while(fila.size() > 1){

        int candidato1 = fila.front();
        fila.pop();
        int candidato2 = fila.front();
        fila.pop();

        if(a[candidato1] >= a[candidato2]){
            fila.push(candidato1);
            a[candidato1] = (a[candidato1] + a[candidato2]) % m;
        }else{
            fila.push(candidato2);
            a[candidato2] = (a[candidato1] + a[candidato2]) % m;
        }
    }

    int vencedor = fila.front();
    if(vencedor == n){
        cout << "Sim" << endl;
    }else{
        cout << "Nao" << endl;
        cout << vencedor << endl;
    }
    return 0;
}