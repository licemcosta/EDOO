#include <iostream>
#include <string>
#include <iomanip>
#include "jogador.h"
#include "derivadas.h"
#include "relatorio.h"
using namespace std;

int main(){
    Jogador* time[6];
    for(int i = 0; i < 6; i++){
        int codigo;
        cout << "JOGADOR " << i + 1 << endl;
        cout << "Qual a posição do atleta (1 = Defesa; 2 = Atacante; 3 = Levantador)? ";
        cin >> codigo;
        switch (codigo){
            case 1: {
                Defesa* d = new Defesa();
                cin >> *d;
                time[i] = d;
                break; //tem que usar para ele não continuar o código
            }
            case 2: {
                Atacante* a = new Atacante();
                cin >> *a;
                time[i] = a;
                break; //tem que usar para ele não continuar o código
            }
            case 3: {
                Levantador* l = new Levantador();
                cin >> *l;
                time[i] = l;
                break; //tem que usar para ele não continuar o código
            }
        }
    }

    Relatorio::gerarRelatorio(time);

    return 0;
}