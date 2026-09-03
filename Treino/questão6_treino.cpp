#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra; cin >> palavra;
    for (int i = 0; i < palavra.length(); i++){
        palavra[i] = tolower(palavra[i]);
    }
    for (int i = 0; i < palavra.length(); i++){
        string c; c = palavra[i];
        if(c == "a" || c == "e" || c == "i" || c == "o" || c == "u" || c == "y"){
            palavra.erase(i, 1);
            i--;
        }
        else{
            palavra.insert(i, ".");
            i++;
        }
    }
    cout << palavra;
}