#include <iostream>
using namespace std;

void swap(float *p1, float *p2) { //apenas p1 e p2 são ponteiros, pois se temp for ponteiro tbm ele não vai funcionar, já que não vai trocar os valores de x e y
  float temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main() {
  float x = 2.1;
  float y = 3.2;

  swap(&x, &y); //como são ponteiros eu não posso mexer no &
  cout << "x = " << x << ", y = " << y << endl;

  return 0;
}
