#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


void print_arr(vector<int> & a){

    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x; cin >> n >> x;
    vector<int> a(n);

    for(auto & y : a) cin >> y;
    map<int,int> indice_da_soma; // pra cada valor em que indice ele apareceu
    pair<int,int> resposta = {-1,-1};
    for(int i = 0 ; i <n;i++){
        int atual = a[i];
        int complemento = x - atual; // atual + (x - atual) = x;
        if(indice_da_soma.count(complemento)){
            resposta = {indice_da_soma[complemento] + 1,i + 1};
            break;
        }
        indice_da_soma[atual] = i;
    }
    if(resposta.first == -1){
        cout << -1 << endl;
    }else{
        cout << resposta.first << " " << resposta.second << endl;
    }

    return 0;
}