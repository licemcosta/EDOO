#include <string>
#include <iostream>
using namespace std;

int main(){
    int quant, soma;
    cin >> quant;
    soma = 0;
    string poliedro;
    for(int i = 0; i < quant; i++){
        cin >> poliedro;
        string poliedro_inicio;
        poliedro_inicio = poliedro[0];
        if(poliedro_inicio == "T"){
            soma += 4;
        }
        else if(poliedro_inicio == "C"){
            soma += 6;
        }
        else if(poliedro_inicio == "O"){
            soma += 8;
        }
        else if(poliedro_inicio == "D"){
            soma += 12;
        }
        else if(poliedro_inicio == "I"){
            soma += 20;
        }
    }
    cout << soma;
}