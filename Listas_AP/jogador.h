#ifndef _jogador_
#define _jogador_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ExcecaoDadosInvalidos {
    private:
        string msg;

    public:
    ExcecaoDadosInvalidos(string m){
        msg = m;
    }
    string mensagem() const {
        return msg;
    }
};

class Jogador{
    private:
        double peso, altura;
        string nome;
        int codigoPosicao;


    public:
        Jogador(double p = 0, double a = 0, string n = "", int cp = 0){
            peso = p;
            altura = a;
            nome = n;
            codigoPosicao = cp;
        }

        double getPeso() const {
            return peso;
        }

        void setPeso(double p){
            if(p <= 0){
                throw ExcecaoDadosInvalidos("Peso Inválido");
            }
            peso = p;
        } 

        double getAltura() const {
            return altura;
        }

        void setAltura(double a){
            if(a <= 0){
                throw ExcecaoDadosInvalidos("Altura Inválida");
            }
            altura = a;
        } 

        string getNome() const {
            return nome;
        }

        void setNome(string n) {
            nome = n;
        }

        int getPosicao() const {
            return codigoPosicao;
        }

        void setPosicao(int cp) {
            codigoPosicao = cp;
        }
};

inline ostream& operator<<(ostream& os, const Jogador& j) {
    os << "Nome: " << j.getNome();
    os << " | Peso: " << fixed << setprecision(1) << j.getPeso() << "kg"; //setprecision para defninir o número de casas decimais
    os << " | Altura: " << setprecision(2) << j.getAltura() << "m";
    return os;
}

inline istream& operator>>(istream& is, Jogador& j){
    string nome;
    double peso, altura;
    while(true){
        cout << "Insira o nome do jogador: ";
        is >> nome;
        cout << "Insira o peso do jogador: ";
        is >> peso;
        cout << "Insira a altura do jogador: ";
        is >> altura;
        
        try {
            j.setNome(nome);
            j.setPeso(peso);
            j.setAltura(altura);
            break;                          // deu certo: sai do laço
        } catch (ExcecaoDadosInvalidos& e) {
            cout << "\n" << e.mensagem() << endl;   // deu erro: mostra e repete
        }
    }
    return is;
}

#endif