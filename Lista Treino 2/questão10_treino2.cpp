#include <iostream>
#include <string>
using namespace std;


bool verificar(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] != s[s.length() - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int quant;
    cin >> quant;
    for(int i = 0; i < quant; i++){
        string palavra;
        cin >> palavra;
        int letras = palavra.length();
        bool palindroma = true;
        for(char c: palavra){
            if(c != 'a'){
                palindroma = false;
                break;
            }
        }
        if(palindroma){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            string palavra_nova1, palavra_nova2;
            palavra_nova1 = palavra + 'a';
            palavra_nova2 = 'a' + palavra;
            if(verificar(palavra_nova1) == false){
                cout << palavra_nova1 << endl;
            }
            else{
                cout << palavra_nova2 << endl;
            }
        }
    }
}