#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
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
    vector<int> a(n);
    for(int & x : a) cin >> x;
    stack<int> pilha;
    vector<int> ans(n);
    for(int i = 0;i < n;i++){

        // remocao
        while(!pilha.empty() && a[pilha.top()] >= a[i]) pilha.pop();

        ans[i] = (pilha.empty() ? 0: pilha.top() + 1);
        pilha.push(i);
    }

    for(int i = 0 ; i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}