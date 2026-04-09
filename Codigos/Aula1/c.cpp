#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    int n; cin >> n;

    bool divisivel_por_3 = n % 3 == 0; 
    bool divisivel_por_5 = n % 5 == 0;

    if(divisivel_por_3 && divisivel_por_5){
        cout << "FizzBuzz" << endl;
    }else if(divisivel_por_3){
        cout << "Fizz" << endl;
    }else if(divisivel_por_5){
        cout << "Buzz" << endl;
    }

    

    return 0;
}