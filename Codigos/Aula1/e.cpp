#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1,y1;
    int x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    int _x = (x2 - x1);
    int _y = (y2 - y1);
    double d = sqrt(_x * _x + _y * _y);
    cout <<  fixed << setprecision(20) << d << endl;
    return 0;
}