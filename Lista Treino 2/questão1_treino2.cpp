#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra;
    cin >> palavra;
    if(isupper(palavra[0])){
        cout << palavra;
    }
    else{
        palavra[0] = toupper(palavra[0]);
        cout << palavra;
    }

}