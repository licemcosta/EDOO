#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra;
    cout << "Digite a palavra: ";
    cin >> palavra;
    int quant = palavra.length();
    int palindromo = 0;
    for(int i = 0; i < quant; i++){
        if(palavra[i] != palavra[quant - i - 1]){
            palindromo++;
        }
    }
    if(palindromo != 0){
        cout << "A palavra " << palavra << " não é palíndroma." << endl;
    }
    else{
        cout << "A palavra " << palavra << " é palíndroma." << endl;
    }
}