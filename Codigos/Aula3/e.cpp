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

    int n; cin >> n;
    string s; cin >> s;

    stack<char> pilha;
    bool resposta = true;
    for(char c : s){
        if(c == '('){
            pilha.push(c);
        }else{
            if(pilha.empty()){
                resposta = false;
                break;
            }
            pilha.pop();
        }
    }
    if(pilha.size() > 0) resposta = false;
    cout << (resposta ? "YES":"NO") << endl;

    return 0;
}