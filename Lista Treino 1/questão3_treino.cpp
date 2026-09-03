#include <iostream>
using namespace std;

int main() {
    int quant, saida = 0; cin >> quant;
    for(int i=1;i<= quant;i++) {
        string comando;
        cin >> comando;
        if(comando == "++X" || comando == "X++"){
            saida += 1;
        }
        else{
            saida -= 1;
        }
    }
    cout << saida;
}