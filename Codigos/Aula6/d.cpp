#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vii a(n);
    for(auto & x : a) cin >> x.first >> x.second;

    // (inicio,fim)
    // define quando x vem antes de y
    auto comparador = [&](pii & x , pii & y){
        return x.second < y.second;
    };
    sort(ALL(a),comparador);
    int prev = 0,resposta = 0; // ultima posição que um cara terminou
    for(auto [l,r] : a){
        if(l < prev) continue;
        resposta++;
        prev = r;
    }

    cout << resposta << endl;

    return 0;
}