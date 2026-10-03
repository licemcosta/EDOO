#include <iostream>
using namespace std;

class Vetor{
    private:
    float listinha[10];
    public:
        Vetor() { //construtor precisa ter o exato mesmo nome da classe
            for(int i = 0; i < 10; i++){
                listinha[i] = 0.0f; //inicializo o array com todos os valores iguais a zero / o f depois do número serve para indicar que ele é float e não double
            }
        }
        float& operator[](int i){ //float& serve para referência, ou seja, se eu precisar alterar o valor de algum termo eu posso / a ssobrecarga de operador funciona para dar outra função aos caracteres especiais, dizendo o que eles tem que fazer em caso de uso.
            if(i < 0 || i > 9){ //se for fora do intervalo, modificará o índice 0
                cout << "Índice Inválido" << endl;
                return listinha[0];
            }
            else{
                return listinha[i];
            }
        }
};

int main(){
    Vetor v; //cria o vetor v
    v[3] = 5.5f;
    cout << v[3] << endl;
    v[20] = 7.7f;
    cout << v[0] << endl;

    return(0);
}
