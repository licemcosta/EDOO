#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra1, palavra2;
    cin >> palavra1;
    cin >> palavra2;
    if(palavra1.length() != palavra2.length()){
        cout << "NO" << endl;
    }
    else{
        int j = palavra1.length() - 1;
        int contador = 0;
        for(int i = 0; i < palavra1.length(); i++, j--){
            if(palavra1[i] != palavra2[j]){
                contador++;
            }
        }
        if(contador == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
