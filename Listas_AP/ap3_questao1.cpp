#include <iostream>
#include <string>
using namespace std;

int main(){
    int valores[10] = {231, 784, 657, 912, 332, 444, 86, 119, 579, 864}; //criação de um array no modelo tipo nome[quantidade de itens] = {lista de itens}
    int n, m, soma = 0; //tem que inializar soma com 0, senão ele vira qualquer valor
    cin >> n; 
    cin >> m;
    if(n == m){
        cout << valores[n] % 1000;
    }
    else{
        while(n <= m){
            soma += valores[n];
            n++;
        }
        cout << soma % 1000;
    }
}