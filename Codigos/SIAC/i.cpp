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
    string s;
    getline(cin,s);


    int n = s.size();
    // abcasdadsa
    for(int i = 2; i < n;i++){
        // (indice de inicio, tamanho)
        if(s.substr(i-2,3) == "ram"){
            s[i] = 'o';
        }
    }
    cout << s << endl;

    return 0;
}