#include "house.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    House* casa_prof = new House("Gustavo", 20000, 4); //usa o new para as casas não ficarem alocadas como pilha, mas de modo dinâmico
    House* casa_alice = new House("Alice", 7500, 17);
    House* casa_belian = new House("Belian", 7000, 2);

    for(int i = 0; i < 4; i++){ House::fastForward();} //usa House:: por ser método estático

    cout << "A casa de " << casa_prof -> getOwner() << " tem " << casa_prof -> getAge() << " anos e vale R$ " << casa_prof -> getValue() << endl; // usa ponteiro para acessar os métodos get porque os objetos foram criados com new, logo, só acessa com ->
    cout << "A casa de " << casa_belian -> getOwner() << " tem " << casa_belian -> getAge() << " anos e vale R$ " << casa_belian -> getValue() << endl;

    delete casa_alice; //precisa desalocar da memória, já que ela foi demolida
    casa_alice =  nullptr;

    House* casa_helena = new House("Helena", 20000, 0);

    for(int i = 0; i < 8; i++){ House::fastForward();} //usa House:: por ser método estático
    cout << "A casa de " << casa_prof -> getOwner() << " tem " << casa_prof -> getAge() << " anos e vale R$ " << casa_prof -> getValue() << endl; 
    cout << "A casa de " << casa_belian -> getOwner() << " tem " << casa_belian -> getAge() << " anos e vale R$ " << casa_belian -> getValue() << endl;
    cout << "A casa de " << casa_helena -> getOwner() << " tem " << casa_helena -> getAge() << " anos e vale R$ " << casa_helena -> getValue() << endl;

    casa_belian -> demolish();
    delete casa_belian;
    casa_helena -> demolish();
    delete casa_helena;

    House::fastForward();

}