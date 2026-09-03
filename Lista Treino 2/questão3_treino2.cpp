#include <iostream>
#include <string>
using namespace std;

int main(){
    int quant;
    cin >> quant;
    string palavra = "codeforces";
    for(int i = 0; i < quant; i++){
        string palavra_comparar;
        cin >> palavra_comparar;
        int contador = 0;
        for(int j = 0; j < palavra.length(); j++){
            if(palavra[j] != palavra_comparar[j]){
                contador++;
            }
        }
        cout << contador << endl;
    }
}