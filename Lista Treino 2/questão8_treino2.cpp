#include <iostream>
#include <string>
using namespace std;

int main(){
    int quant_letras;
    cin >> quant_letras;
    string palavra; 
    cin >> palavra;
    if(quant_letras < 26){
        cout << "NO" << endl;
    }
    else{
        for(int i = 0; i < palavra.length(); i++){
            palavra[i] = tolower(palavra[i]);
        }
        
        int letras[26] = {0};
        int repetiçoes = 0;

        for(int i = 0; i < palavra.length(); i++){
            int posiçao = palavra[i] - 'a';
            letras[posiçao]++;
            if(letras[posiçao] == 1){
                repetiçoes++;
            }
        }
        if(repetiçoes == 26){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}