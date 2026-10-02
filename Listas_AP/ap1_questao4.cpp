// A program containing errors!
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
  string message = "Learn from your mistakes!\n";
  cout << message << endl;
  int len = message.length();
  cout << "Length of the string: " << len << endl;
  
  // And a random number in addition:
  int b; 
  srand(12.5); b = rand();
  cout << "\nRandom number: " << b << endl;
  return 0;
}
