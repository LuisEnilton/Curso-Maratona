#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ALL(x) x.begin(), x.end()
#define dbg(x) cout << #x << " " << x << endl;
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int l = 0, r = n - 1;
    bool vez = 0;
    vector<int> resposta(2);
    while(l <= r){
        if(a[l] > a[r]){
            // pego o item
            resposta[vez] += a[l++];
            // n posso mais pegar esse item
        }else{
            resposta[vez] += a[r--];
        }
        vez = !vez;
    }
    for(auto x : resposta){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}