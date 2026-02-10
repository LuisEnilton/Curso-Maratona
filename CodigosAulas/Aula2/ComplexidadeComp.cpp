#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string op; //linear,quadr, exp, log,fact, linearitm

    cin >> n >> op;
    int cnt = 0;
    auto inicio = chrono::high_resolution_clock::now();
    if(op == "fact"){
        vector<int> a(n);
        for(int i = 0; i < n;i++) a[i] = i;
        
        while(next_permutation(a.begin(),a.end())){
            cnt++;
        };
    }else if(op == "quadr"){

        n = n * n;
        
    }else if(op == "exp"){
        n = (2LL << n);
    }else if(op == "log"){
        n = log2(n);
    }else if(op == "linearitm"){
        n = n * log2(n);
    }

    for(int i = 0; i < n;i++){
            cnt++;
    }
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> tempo = fim - inicio;
    cout << "Valor de N: " << n << endl;
    cout << "Contador: " << cnt << endl;
    cout << "Tempo de Execução: " << tempo.count() << " ms"<< endl;

    return 0;
}