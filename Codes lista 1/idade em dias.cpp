#include <iostream>
using namespace std;
int main() {
  //codigo 1
  int numeroI, numeroDa, numeroM, idadeDias;
  int idadeDias;
  cout<< "\tadicione aqui a sua idade:";
  cin>> numeroI;
  cout<<"\tadicione aqui o mês em que nasceu:";
  cin>> numeroM;
  cout<< "\tadicione aqui o dia em que nasceu:";
  cin >> numeroDa;
  idadeDias=numeroI*365+numeroM*30+numeroDa;

  cout<< "\tsua idade em dias é:"<<idadeDias;
  
  
}  
