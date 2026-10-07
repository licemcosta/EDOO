#include <iostream>
using namespace std;

class Temperatura {
private:
    double celsius;
public:
    explicit Temperatura(double c = 0.0) : celsius(c) {}

    // função de conversão 1
    explicit operator double() const { //define o tipo da conversão antes da variável entre parênteses, e não antes do nome do operador
        return (double)celsius; 
    }

    // função de conversão 2
    operator float() const {
        return (float)celsius;
    }

    double getCelsius() const { return celsius; }
};

Temperatura operator+(const Temperatura& a, const Temperatura& b) { //corrigindo o return da função, que não chama ela mesma
    return Temperatura(a.getCelsius() + b.getCelsius()); //como eu bloqueei a conversão implícita ele travava, preciso chamar temperatura para converter para double
}

void exibirFahrenheit(const Temperatura& t) {
    double f = (t.getCelsius() * 9.0 / 5.0) + 32.0;
    cout << "Temperatura: " << f << " F" << endl;
}

int main() {
    Temperatura t1(20.0);

    // uso 1
    cout << "Celsius: " << t1.getCelsius() << endl; //precisa usar getCelsius, já que o compilador não converte mais sozinho

    // uso 2
    Temperatura t2 = t1 + Temperatura(15.5); //agora ele soma porque ele está usando o operador que eu criei, já qq ele soma duas temperaturas

    // uso 3
    exibirFahrenheit(Temperatura(100.0)); //preciso colocar dentro de temperatura para a conversão deixar de ser implícita

    return 0;
}

