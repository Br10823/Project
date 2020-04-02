#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char cOperador(char cK, string codigos)
{
  string sOpera = "+-*/"; 
  char iResp;
  for(int iK = 10; iK < 14; iK++)
  {
    if(codigos[iK] == cK)
  {
    iResp=sOpera[iK - 10];
  }
  }
  return iResp; 
}

int IntToString(string sNumber, string sC)
  {
    int iN=1, iResp=0;
    for(int iK = sNumber.length()-1; iK >=0; iK--)
  {
    for(int iC = 0; iC < sC.length(); iC++)
  {
    if(sNumber[iK] == sC [iC])
    {
      iResp = iResp + (iC*iN);
      iN = iN * 10;
    }
  }
  }
  return iResp;
}

bool Val = false;
int resultado(char cOpera, int iN, int iNum)
{
  int iResp;
  if(cOpera == '+')
    {
      iResp= iN + iNum;
    } 
  if(cOpera == '-')
    {
      iResp= iN - iNum;
    } 
  if(cOpera == '*')
    {
      iResp= iN * iNum;
    }
  if(cOpera=='/')
      {
        iResp = iN / iNum;
      }
    return iResp;
}

int main() 
{
  int iN, iNum, iResp;
  string sArEntrada, sArSalida, espacio = "", sLinea;
  char cOpera, Operador;
  cout << "Nombre del archivo de entrada: " << endl;
  cin >> sArEntrada;
  cout << "Nombre para el archivo de salida " << endl;
  cin >> sArSalida;

  ifstream ArchivoEn;
  ofstream ArchivoSal;


  ArchivoEn.open(sArEntrada);
  ArchivoSal.open(sArSalida);

  for(int iK = 0; iK < 14; iK++)
    {
      ArchivoEn >> sLinea;
      espacio.append(sLinea);
    }
  
  while(!ArchivoEn.eof())
    {
      ArchivoEn >> sLinea;
      iN = IntToString(sLinea, espacio);
      ArchivoEn >> cOpera;
      Operador = cOperador(cOpera,espacio);
      ArchivoEn >> sLinea;
      iNum = IntToString(sLinea, espacio);
      iResp=resultado(Operador, iN, iNum);
    
      ArchivoSal << "(" << iN << ") " << Operador << " (" << iNum << ") = " << ((Val)? "Operacion no valida":to_string(iResp)) << endl;
      Val = false;
    }
  
  ArchivoEn.close();
  ArchivoSal.close();

    return 0;

}