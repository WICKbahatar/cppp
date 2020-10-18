#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main()
{   
    string mes;
    cin >> mes;
    
    string rev_mes {mes};
    reverse(rev_mes.begin(), rev_mes.end());
    
    int i, j;
    for(i = 0; i < mes.length(); i++){
        for(j = 0; j < mes.length()-1-i; j++)
            cout << " ";
        cout << mes.substr(0,i+1) << rev_mes.substr(mes.length() - i, i) << endl;
    }

    return 0;
}
