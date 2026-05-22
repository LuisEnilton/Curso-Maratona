#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ALL(x) x.begin(),x.end()
#define dbg(x) cout << #x << " " << x << endl;
using namespace std;


void print_arr(vector<int> & a){

    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}

double f(double x){
    return x * x + sqrt(x);
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    double C; cin >> C;

    // quer x tal que x*x + raiz(x) = C

    // chuta um valor pra x, se f(x) for < C , a gente chutou x muito baixo tenta maior


    const double eps = 1e-6; // eps é a margem de erro
    double l = 0, r = 1e10;
    while(abs(l - r) >= eps){
        double x = (l + r)/2;

        if(f(x) > C){
            r = x;
        }else{
            l = x;
        }
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}