#ifndef _jogador_
#define _jogador_

#include <iostream>
#include <string>
using namespace std;

class ExcecaoDadosInvalidos {
    private:

    public:
};

class Jogador{
    private:
        double peso, altura;
        string nome;
        int codigoPosicao;
        

    public:
        Jogador(double p, double a, string n, int cp){
            peso = p;
            altura = a;
            nome = n;
            codigoPosicao = cp;
        }

        double getPeso() const {
            return peso;
        }

        double getAltura() const {
            return altura;
        }

        string getNome() const {
            return nome;
        }

        int getPosicao() const {
            return codigoPosicao;
        }
};

#endif