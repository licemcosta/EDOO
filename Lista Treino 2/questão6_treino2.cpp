#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int quant;
    cin >> quant;
    string numero;
    for(int i = 0; i < quant; i++){
        cin >> numero;
        if(numero.length() == 2){
            cout << numero[1] << endl;
        }
        else{
            char menor = numero[0];
            for(int i = 0; i < numero.length(); i++){
                if(menor > numero[i]){
                    menor = numero[i];
                }
            }
            cout << menor << endl;
        }
    }
}