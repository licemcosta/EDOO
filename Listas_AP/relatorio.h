#ifndef _relatorio_
#define _relatorio_

#include <iostream>
#include <string>
#include <iomanip>
#include "jogador.h"
#include "derivadas.h"
using namespace std;

class Relatorio{
    public:
    static void gerarRelatorio(Jogador* titulares[6]){
    cout << "\nRELATÓRIO DO TIME:" << endl;
        for(int i = 0; i < 6; i++){
            switch(titulares[i]->getPosicao()){
                case 1: cout << *static_cast<Defesa*>(titulares[i]) << endl; break;
                case 2: cout << *static_cast<Atacante*>(titulares[i]) << endl; break;
                case 3: cout << *static_cast<Levantador*>(titulares[i]) << endl; break;
            }
        }
    }
};



#endif 