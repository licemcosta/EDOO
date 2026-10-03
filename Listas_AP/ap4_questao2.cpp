#include "DayTime.h"
#include <iostream>
using namespace std;

DayTime::DayTime(int h, int m, int s) { //construtor
    hour = minute = second = 0;
    overflow = false;
    setTime(h, m, s);
}


int main(){
    DayTime evento(17, 30, 00); 
    cout << "Meu evento começa às " << evento << "." << endl;

    
    cout << "Que horas vai ser o seu evento?" << endl;
    DayTime horario;
    cout << "Digite o horário do seu evento no formato hh:mm:ss: ";
    while(!(cin >> horario)){
        cout << "Horário inexistente. Digite outro horário: ";
        cin.clear();                 // limpa o estado de erro
    }
    if(horario < evento){
        cout << "Seu evento é antes do meu!" << endl;
    }
    else if(horario == evento){
        cout << "Uau, nossos compromissos são no mesmo horário" << endl;
    }
    else{
        cout << "Seu evento é depois do meu!" << endl;
    }
    return 0;
}