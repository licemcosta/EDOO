#include <iostream>
using namespace std;

int main() {
    int quant, saida = 0; cin >> quant;
    for(int i=1;i<= quant;i++) {
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        int soma = a + b;
        int sub = a - b;
        if(soma == c){
            cout << "+\n";
        }
        else{
            cout << "-\n";
        }
    }
}