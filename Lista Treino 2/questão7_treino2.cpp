#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra; 
    cin >> palavra;
    
    int letras[26] = {0};
    int quant = 0;

    for(int i = 0; i < palavra.length(); i++){
        int posiçao = palavra[i] - 'a';
        letras[posiçao]++;
        if(letras[posiçao] == 1){
            quant++;
        }
    }
    if(quant%2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }
    else{
        cout << "IGNORE HIM!" << endl;
    }
}