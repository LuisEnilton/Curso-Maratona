#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int d; cin >> d;
    double resposta = 0.0;
    for(int i = 0; i < d;i++){
        int a,b; cin >> a >> b ;
        double curr = ( a- b) * (a - b);
        resposta += curr;
    }
    resposta = sqrt(resposta);

    cout << fixed << setprecision(15) << resposta << endl;

    return 0;
}