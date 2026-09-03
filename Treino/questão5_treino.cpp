#include <iostream>
#include <string>
using namespace std;

int main() {
    string palavra1; cin >> palavra1;
    string palavra2; cin >> palavra2;
    for( char &c : palavra1){
        c = toupper(c);
    }
    for( char &c : palavra2){
        c = toupper(c);
    }
    if(palavra1 > palavra2){
        cout << 1;
    }
    else if(palavra1 == palavra2){
        cout << 0;
    }
    else{
        cout << -1;
    }
}

// a parte de deixar tudo maiúsculo pode fazer com um for(int i = 0; i < palavra.length(); i++) e aí palavra[i] = toupper(palavra[i])