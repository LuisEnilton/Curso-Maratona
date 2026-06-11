#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(),x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x; cin >> n >> x; // x é o total de tempo pra gastar nos estudos

    vi a(n);
    for(auto & x : a) cin >> x;

    // queremos pegar sempre o menor algoritmo possivel
    sort(ALL(a));
    int resposta = 0;
    for(auto algo : a){

        if(algo <= x){
            resposta++;
            x -= algo;
        }
    }
    cout << resposta << endl;

    return 0;
}