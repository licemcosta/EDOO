// DayTime.h
// The class DayTime containing operators < and ++
//
#ifndef _DAYTIME_
#define _DAYTIME_

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class DayTime {
    private:
        short hour, minute, second;
        bool overflow;

    public:
        DayTime (int h = 0, int m = 0, int s = 0);
        
        bool setTime (int hour, int minute, int second = 0){ //para dizer se o tempo existe ou não
            if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59){ //se todos os tempos estiverem dentro do padrão pra o tempo ele entra e associa
                this->hour = hour; //usa ponteiro porque precisa associar o de dentro ao de fora
                this->minute = minute;
                this->second = second;
                return true; 
            }
            return false;
        }
        
        int getHour() const { 
            return hour; 
        }
        int getMinute() const { 
            return minute; 
        }
        int getSecond() const { 
            return second; 
        }
        
        int asSeconds() const { // Daytime in seconds
            return (60*60*hour + 60*minute + second); 
        }


        //Incrementar e Decrementar os segundos
        DayTime& operator++() { //função prefixo - retorna o valor já atualizado 
            ++second;
            if(second > 59){
                second = 0;
                ++minute;
                if(minute > 59){
                    minute = 0;
                    ++hour;
                    if(hour > 23){
                        hour = 0;
                        overflow = true;
                    }
                }
            }
            return *this;
        }

        DayTime operator++(int) { //função pósfixo - retorna o valor anterior, mas atualiza a variável
            DayTime antigo = *this;
            ++(*this);
            return antigo;
        }

        DayTime& operator--() { //função prefixo - retorna o valor já atualizado 
            --second;
            if(second < 0){
                second = 59;
                --minute;
                if(minute < 0){
                    minute = 59;
                    --hour;
                    if(hour < 0){
                        hour = 0;
                        minute = 0;
                        second = 0;
                    }
                }
            }
            return *this;
        }

        DayTime operator--(int) { //função pósfixo - retorna o valor anterior, mas atualiza a variável
            DayTime antigo = *this;
            --(*this);
            return antigo;
        }

        

    void print() const{
        cout << hour << ":" << minute << ":" << second;
    };
    };

//Comparações booleanas:

inline bool operator<(const DayTime& a, const DayTime& b) { 
    return a.asSeconds() < b.asSeconds(); //usa asSeconds para não gerar uma recursão infinita
}
inline bool operator>(const DayTime& a, const DayTime& b) { 
    return a.asSeconds() > b.asSeconds();
}
inline bool operator<=(const DayTime& a, const DayTime& b) { 
    return a.asSeconds() <= b.asSeconds();
}
inline bool operator>=(const DayTime& a, const DayTime& b) { 
    return a.asSeconds() >= b.asSeconds();
}
inline bool operator==(const DayTime& a, const DayTime& b) { 
    return a.asSeconds() == b.asSeconds();
}
inline bool operator!=(const DayTime& a, const DayTime& b) { 
    return a.asSeconds() != b.asSeconds();
}
inline std::ostream& operator<<(std::ostream& os, const DayTime& a){
    os << a.getHour() << ":" << a.getMinute() << ":" << a.getSecond();
    return os;
}
inline std::istream& operator>>(std::istream& is, DayTime& a){
    std::string linha;
    if (!std::getline(is, linha)) { //faz a entrada até o enter
        return is;                            
    }
    std::istringstream ss(linha); //transformar linha de string para algo que possa ser lido como fluxo
    int hour, minute, second;
    char c1 = 0, c2=0;
    if(!(ss >> hour >> c1 >> minute >> c2>> second) || c1 != ':' || c2 != ':' || a.setTime(hour, minute, second) == false){
        is.setstate(std::ios::failbit); 
        return is;
    }
    return is;
}

#endif //_DAYTIME_


//a = ++v --- se v fosse 6 antes de somar 1, v agora é 7 e a também
//a = v++ --- se v fosse 6 antes de somar 1, v agora é 7 e a continua sendo seis, porque ela armazena o valor anterior