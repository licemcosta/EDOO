#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra;
    cin >> palavra;
    int maiusculas = 0, minusculas = 0;
    for(int i = 0; i < palavra.length(); i++){
        if(isupper(palavra[i])){
            maiusculas++;
        }
        else{
            minusculas++;
        }
    }
    if(maiusculas > minusculas){
        for(int i = 0; i < palavra.length(); i++){
            palavra[i] = toupper(palavra[i]);
        } 
    }
    else{
        for(int i = 0; i < palavra.length(); i++){
            palavra[i] = tolower(palavra[i]);
        } 
    }
    cout << palavra << endl;
}