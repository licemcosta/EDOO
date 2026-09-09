#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int main(){
    int quant;
    cin >> quant;
    for(int i = 0; i < quant; i++){
        string palavra1, palavra2;
        cin >> palavra1 >> palavra2;

        int letras1 = palavra1.length();
        int letras2 = palavra2.length();
        int mmc_palavras = lcm(letras1, letras2);
        string palavra_nova1 = "", palavra_nova2 = "";

        for(int j = 0; j < (mmc_palavras/letras1); j++){
            palavra_nova1 += palavra1;
        }
        for(int j = 0; j < (mmc_palavras/letras2); j++){
            palavra_nova2 += palavra2;
        }
        if(palavra_nova1 == palavra_nova2){
            cout << palavra_nova1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}