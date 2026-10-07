#ifndef _HOUSE_H_
#define _HOUSE_H_


#include <iostream>
#include <string>
#include <stdexcept>


#define MAX_HOUSES 3


class House {


    private:


        int id;
        std::string owner;
        double value;
        int age;
        bool broken;


        static int& getHouses() {
            static int houses = 0;
            return houses;
        }


        static House** getNeighbourhood() {
            static House *neighbourhood[MAX_HOUSES] = {nullptr};
            return neighbourhood;
        }


        static int& getYear() {
            static int year = 2026;
            return year;
        }


        void break_apart() {


            if (owner == "gustavo" || owner == "Gustavo") {
                std::cout << "A casa do professor ficou muito velha e desmoronou. "
                          << "Agora ele vai ter que morar no CIn D:\n";
            } else {
                std::cout << "A casa de " << owner << " ficou muito velha e desmoronou. "
                          << "Onde "<< owner << " vai morar agora? :(\n";
            }


            this->broken = true;


        }


    public:
   
        House(std::string owner, double value, int age) {


            if (++getHouses() > MAX_HOUSES) throw std::runtime_error("Voce atingiu o limite de casas.");
           
            for (int i = 0; i < MAX_HOUSES; ++i) {
                House *house = getNeighbourhood()[i];
                if (house == nullptr) {
                    getNeighbourhood()[i] = this;
                    this->id = i;
                    this->owner = owner;
                    this->value = value;
                    this->age = age;
                    this->broken = false;
                    break;
                };
            }


            std::cout << "A casa de " << owner << " foi adicionada a vizinhanca.\n";


        }


        const std::string& getOwner() const { return this->owner; }
        double getValue() const { return this->value; }
        int getAge() const { return this->age; }


        static void fastForward() {


            std::cout << "O tempo passa... " << ++getYear() << std::endl;


            for (int i = 0; i < MAX_HOUSES; ++i) {


                House *house = getNeighbourhood()[i];
                if (house == nullptr) continue;


                else if (house->broken)
                    throw std::runtime_error("Voce esqueceu de limpar os destrocos de uma casa e foi condenado a pagar todas as 4 cadeiras de calculo na Area II.");
               
                else if (++house->age > 20) {
                    house->break_apart();
                    house->value = 0;
                }


                else
                    house->value *= 0.9;
               
            }
           
        }


        void demolish() {


            if (owner == "gustavo" || owner == "Gustavo") {
                std::cout << "Voce destruiu a casa do professor?? "
                          << "Boa sorte nesse semestre...\n";
            } else {
                std::cout << "Voce destruiu a casa de " << owner
                          << ". Onde " << owner << " vai morar agora? :(\n";
            }
           
            this->broken = true;


        }


        ~House() {
            getNeighbourhood()[this->id] = nullptr;
            --getHouses();
        }


};


#endif
