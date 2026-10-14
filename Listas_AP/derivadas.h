#ifndef _derivadas_
#define _derivadas_

#include <iostream>
#include <string>
#include <iomanip>
#include "jogador.h"
using namespace std;

class Defesa : public Jogador{
    private:
    int defesas;

    public:
    Defesa(double peso = 0, double altura = 0, string nome = "", int d = 0) : Jogador(peso, altura, nome, 1){ //cp passa direto
        defesas = d;
    };
    int getDefesas() const {
        return defesas;
    }
    void setDefesas(int d){
        defesas = d;
    }
    friend ostream& operator<<(ostream& os, const Defesa& j) { //precisa do friend para deixar de ser método
    os << "DEFESA | " << static_cast<const Jogador&>(j) //precisa do static cast para não entrar em recursão infinita
       << " | Defesas: " << j.defesas;
    return os;
    }

    friend istream& operator>>(istream& is, Defesa& j) {
        while (true) {
            is >> static_cast<Jogador&>(j);   // lê nome, peso e altura
            int d;
            cout << "Insira a quantidade de defesas: ";
            is >> d;
            try {
                if (d < 0) throw ExcecaoDadosInvalidos("Defesas Inválidas");
                j.defesas = d;
                return is;
            } 
            catch (ExcecaoDadosInvalidos& e) {
                cout << e.mensagem() << endl;
            }
        }
    }
};

class Atacante : public Jogador{
    private:
    double velocidadeAtaque;

    public:
    Atacante(double peso = 0, double altura = 0, string nome = "", int v = 0) : Jogador(peso, altura, nome, 2){ //cp passa direto
        velocidadeAtaque = v;
    };
    int getVelocidade() const {
        return velocidadeAtaque;
    }
    void setVelocidade(double v){
        velocidadeAtaque = v;
    }
    friend ostream& operator<<(ostream& os, const Atacante& j) { //precisa do friend para deixar de ser método
    os << "ATACANTE |  " << static_cast<const Jogador&>(j) //precisa do static cast para não entrar em recursão infinita
       << " | Velocidade do ataque: " << fixed << setprecision(1) << j.velocidadeAtaque << "km/h";
    return os;
    }

    friend istream& operator>>(istream& is, Atacante& j) {
        while (true) {
            is >> static_cast<Jogador&>(j);   // lê nome, peso e altura
            double v;
            cout << "Insira a velocidade do ataque: ";
            is >> v;
            try {
                if (v < 0) throw ExcecaoDadosInvalidos("Velocidade Inválida");
                j.velocidadeAtaque = v;
                return is;
            } 
            catch (ExcecaoDadosInvalidos& e) {
                cout << e.mensagem() << endl;
            }
        }
    }
};

class Levantador : public Jogador{
    private:
    int assistencias;

    public:
    Levantador(double peso = 0, double altura = 0, string nome = "", int assist = 0) : Jogador(peso, altura, nome, 3){ //cp passa direto
        assistencias = assist;
    };
    int getAssistencias() const {
        return assistencias;
    }
    void setAssistencias(int assist){
        assistencias = assist;
    }
    friend ostream& operator<<(ostream& os, const Levantador& j) { //precisa do friend para deixar de ser método
    os << "LEVANTADOR | " << static_cast<const Jogador&>(j) //precisa do static cast para não entrar em recursão infinita
       << " | Quantidade de Assistências:" << j.assistencias;
    return os;
    }

    friend istream& operator>>(istream& is, Levantador& j) {
        while (true) {
            is >> static_cast<Jogador&>(j);   // lê nome, peso e altura
            int assist;
            cout << "Insira o número de assistências: ";
            is >> assist;
            try {
                if (assist < 0) throw ExcecaoDadosInvalidos("Assistências Inválidas");
                j.assistencias = assist;
                return is;
            } 
            catch (ExcecaoDadosInvalidos& e) {
                cout << e.mensagem() << endl;
            }
        }
    }
};


#endif