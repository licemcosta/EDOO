#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define TRIPLO(x) (x * 3) //precisa colocar os parênteses no que vai ser feito na função

int chamadas = 0; //chamadas estava sendo definida dentro da função, o que a zerava todas as vezes
void registrarChamada() { 
    chamadas++;
    cout << "Presenca registrada. Chamada numero " << chamadas << endl;
}

double calcularMediaFinal(int p1, int p2, int p3) {
    return (double)(p1 + p2 + p3) / (double)3; //para o resultado ter casas decimais ao menos um termo da divisão precisa ser double
}

int aplicarBonus(int nota) {
    nota++;
    nota = TRIPLO(nota); //a soma aqui dentro não estava funcionando
    return(nota);
} //essa função estava como void, porém void não retorna um valor, logo não estava voltando o valor

int main() {
    string nomeCompleto;
    int p1, p2, p3;
    int totalAlunos;

    cout << "Quantos alunos serao cadastrados? ";
    cin >> totalAlunos;

    for (int i = 0; i < totalAlunos; i++) {
        registrarChamada();

        cout << "Nome do aluno: ";
        cin.ignore(); //limpa o último enter para poder entrar no get line
        getline(cin, nomeCompleto); //serve para guardar em uma string toda a linha, e não só até o primeiro espaço

        cout << "Digite as tres notas: ";
        cin >> p1 >> p2 >> p3;

        p1 = aplicarBonus(p1); //atribuir p1 ao triplo dele

        double media = calcularMediaFinal(p1, p2, p3);
        cout << fixed << setprecision(2);
        cout << "Media de " << nomeCompleto << ": " << media << endl;

        if(nomeCompleto.find(' ') != string::npos){ // != indica diferença (sempre a exclamação antes do símbolo de igual)
            int pos = nomeCompleto.find(" ");
            string sobrenome = nomeCompleto.substr(pos + 1); //para pegar sem o espaço entre as palavras
            cout << "Sobrenome: " << sobrenome << endl;
        }

        int bonusParticipacao = 5;
        cout << "Bonus por participacao (dobrado): " << (bonusParticipacao * 2) + 1 << endl; //dava errado incrementar e multiplicar

        if (media >= 7.0) {
            cout << nomeCompleto << " foi aprovado!" << endl << endl;
        } else {
            cout << nomeCompleto << " foi reprovado." << endl << endl;
        }
    }
    return 0;
}