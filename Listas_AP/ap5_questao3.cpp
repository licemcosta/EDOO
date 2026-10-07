#include <iostream>
using namespace std;

#define TAMANHO 5 // a questão pede para usar um macro para o tamanho

void ArrayTransversal(int* arr, void (*func)(int&)){ //vou passar um valor i e o ponteiro faz com que vire arr[i]
    for(int i = 0; i < TAMANHO; i++){ //aplica em cada posição
        func(arr[i]); //aplica a função na posição do array
    }
}

void inputItem(int& item) { // Recebe um input do usuário e transforma o item nesse input
    cin >> item;
}


void addFive(int& item){ // Adiciona 5 ao item
    item += 5;
}

void isEven(int& item) { // Imprime o item no terminal se ele for par com um espaço logo após (Ex.: “10 “)
    if(item % 2 == 0){
        cout << item << " ";
    }
}


void doubleItem(int& item) { // Multiplica o item por 2
    item = item * 2;
}
void accumulate(int& item) { // Adiciona o item a uma variável estática da própria função que é inicializada em 0 e imprime o valor acumulado com um espaço logo após (Ex.: “10 “)
    static int soma = 0;
    soma += item;
    cout << soma << " ";
}


void zeroItem(int& item) {// Transforma o item em 0
    item = 0;
}

void printItem(int& item) { // Imprime o item no terminal com um espaço logo após (Ex.: “10 “)
    cout << item << " ";
}

int main(){
    int array[TAMANHO] = {0, 0, 0, 0, 0};
    cout << "Insira os valores do array: ";
    ArrayTransversal(array, inputItem);

    cout << "\nArray inicial: ";
    ArrayTransversal(array, printItem);

    cout << "\nSomando 5 em cada posição: ";
    ArrayTransversal(array, addFive);
    ArrayTransversal(array, printItem);

    cout << "\nVerificando quais termos são pares: ";
    ArrayTransversal(array, isEven);

    cout << "\nDobrando todos os itens: ";
    ArrayTransversal(array, doubleItem);
    ArrayTransversal(array, printItem);

    cout << "\nCalculando a soma progressiva dos termos: ";
    ArrayTransversal(array, accumulate);

    cout << "\nZerando o array: ";
    ArrayTransversal(array, zeroItem);
    ArrayTransversal(array, printItem);
}
