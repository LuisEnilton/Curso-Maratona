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

    vector<int> a = {1,2,2,3,3,5};

    int l = 0, r = a.size() - 1;
    int x = 2;
    int resposta = -1;
    while(l <=r){

        int meio = (l + r)/2;

        if(a[meio] >= x){
            resposta = meio;
            r = meio - 1;
        }else{
            l = meio + 1;
        }

    }


    return 0;
}