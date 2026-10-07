 #include <iostream>
using namespace std;

class VetorDinamico {
private:
    int* dados;
    int tamanho;
public:
    VetorDinamico(int t) : tamanho(t) {
        dados = new int[tamanho];
    }
    
    // Destrutor
    ~VetorDinamico() {
        delete[] dados; //correção do uso incorreto do operador de desalocação, já que foi criado com new[]
    }

    void redimensionar(int novoTamanho) {
        delete[] dados; //correção de memory leak, já que dados já ecxistia, logo precisa desalocar da memória
        dados = new int[novoTamanho];
        tamanho = novoTamanho;
    }

    int* getDados() { return dados; }
};

int* criarValorPadrao() { //retorno de referência ou ponteiro inválido corrigido, já que o valor deixava de existir fora da função
    int* valor = new int(100);
    return valor;
}

int main() {
    VetorDinamico v(5);
    v.redimensionar(10);

    int* ptrLocal = criarValorPadrao();
    cout << "Valor: " << *ptrLocal << endl;
    delete ptrLocal;
    ptrLocal = nullptr;

    int* arr = new int[3]{10, 20, 30};
    cout << "Primeiro elemento: " << arr[0] << endl;
    delete[] arr; //dangling pointer corrigido, já que tava deletando o array antes de chamar

    return 0;
    }

