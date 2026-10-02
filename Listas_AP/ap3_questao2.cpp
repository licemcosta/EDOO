#include <iostream>
#include <string>
using namespace std;

class Atleta{
    private:
        string nome, esporte;
        int idade;
        double salario, dinheiro = 0.0;
        static int contador, numero; 
    public:
        Atleta(string n, string e, int i,double s){ //construtor que recebe os dados dos atletas e inicializa cada variável 
            nome = n;
            esporte = e;
            idade = i;
            salario = s;
            contador++;
        }

        ~Atleta() { //destruidor: quando um objeto é apagado, ele execula esta parte do código
            contador--;
        }
        string getNome(){
            return nome;
        }

        string getEsporte(){
            return esporte;
        }

        int getIdade(){
            return idade;
        }

        static int get_contador(){
            return contador;
        }

        double custos_anuais(int impostos){
            if(0 < impostos && impostos < 100) {
                dinheiro = (salario * 12) * (1.0 + impostos*0.01);
            }
            else {
                dinheiro = 0;
            }
            return dinheiro;
        }
};

int Atleta::contador = 0; //sinaliza que o contador de aleta sempre começará em 0
int Atleta::numero = 1;

int main(){
    Atleta atleta1("Alice", "Tecido", 18, 10000);
    Atleta atleta2("Eduardo", "Academia", 23, 20000);

    cout << "Dados do Atleta 1:" << endl;
    cout << atleta1.getNome() << endl;
    cout << atleta1.getEsporte() << endl;
    cout << atleta1.getIdade() << endl;
    cout << atleta1.custos_anuais(67) << endl;

    cout << "Dados do Atleta 2:" << endl;
    cout << atleta2.getNome() << endl;
    cout << atleta2.getEsporte() << endl;
    cout << atleta2.getIdade() << endl;
    cout << atleta2.custos_anuais(0) << endl;
    return 0;
}