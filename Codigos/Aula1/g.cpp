#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    while(n--){
        string s; cin >> s;

        int tamanho = s.size();

        if(tamanho > 10){
            cout << s[0] << s.size() - 2 << s.back() << endl;
        }else{
            cout << s << endl;
        }

    }

    return 0;
}