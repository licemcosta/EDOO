#include <iostream>
#include <string>
using namespace std;

int recursiva(int x){ //quando eu for passar um parâmetro de uma função eu preciso declarar o seu tipo
    if(x == 0){
        return 0;
    }
    if(x == 1){
        return 1;
    }
    return x * recursiva((x - 1));
}

int em_loop(int x){
    int fatorial = 1;
    if(x == 0){
        fatorial = 0;
    }
    else{
        for(int i = 1; i <= x; i++){
            fatorial = fatorial * i;
        }
    }
    return fatorial; //return sempre fora de if e else (no final da função)
}

int main(){
    int n;
    cout << "Fatorial Loop:" << endl;
    for(int i = 0; i <= 20; i++){
        n = em_loop(i);
        cout << "O fatorial de " << i << " equivale a " << n << endl;
    }
    cout << "Fatorial Recursivo:" << endl;
    for(int i = 0; i <= 20; i++){
        n = recursiva(i);
        cout << "O fatorial de " << i << " equivale a " << n << endl;
    }
}