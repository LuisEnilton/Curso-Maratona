#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        string pos; cin >> pos;

        int lin = (pos[1] - '0');
        int col = (pos[0] - 'a') + 1;

        for(int i = 1; i <=8;i++){
            for(int j = 1; j <=8;j++){
                if(i == lin && j == col) continue;

                if(i == lin || j == col){
                    string ans;
                    ans += char('a' + j - 1);
                    ans += char('0' + i);
                    cout << ans << endl;
                }
            }
        }


    }

    return 0;
}