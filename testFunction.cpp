#include <iostream>
#include <cstdlib>
#include <fstream>
#include "australianGrade.hh"
using namespace std;

ofstream test ("test.txt");

float ep[7];
string epExpected[7] = {"Nel shavo, esa no es una calificación válida, que estas haciendo con tu vida?","N","P","C","D","HD","Nel shavo, esa no es una calificación válida, que estas haciendo con tu vida?"};
string epResult[7];

float bva[12] = {-0.01,0,49.99,50,62.99,63,72.99,73,82.99,83,100,100.01};
string bvaExpected[12] = {"Nel shavo, esa no es una calificación válida, que estas haciendo con tu vida?","N","N","P","P","C","C","D","D","HD","HD","Nel shavo, esa no es una calificación válida, que estas haciendo con tu vida?"};
string bvaResult[12];

void initEP(){
	cout<<"Primero lo primero, para EP ingresa lo que se te pide..."<<endl;
	for(int x = 0; x <= 6; x++){
		cout<<"Ingresa el valor correspondiente al rango "<<x + 1<<": ";
		cin>>ep[x];
	}
}

void evaluateEP(){
	for(int x = 0; x <= 6; x++){
		if(australianGrade(ep[x])==epExpected[x])
			epResult[x] = "Pass";
		else
			epResult[x] = "Fail";
	}
}

void evaluateBVA(){
	for(int x = 0; x <= 11;x++){
		if(australianGrade(bva[x])==bvaExpected[x])
			bvaResult[x] = "Pass";
		else
			bvaResult[x] = "Fail";
	}
}

int main(){
	initEP();
	evaluateEP();
	evaluateBVA();
	string res="";

	test << "Equivalence Partitioning...\n" << endl;
    test << "Test data\tExpected\tActual\tPass/Fail" << endl;
    test << "________________________________________________________________"<<endl;
    for(int x = 0; x <= 6; x++)
    	test<<ep[x]<<"\t"<<epExpected[x]<<"\t"<<australianGrade(ep[x])<<"\t"<<epResult[x]<<endl;
  
    test <<endl<< "________________________________________________________________"<<endl;   
    test << "Boundary Values Analisis...\n" << endl;
    for(int y = 0; y <= 11; y++)
    	test <<bva[y]<<"\t"<<bvaExpected[y]<<"\t"<<australianGrade(bva[y])<<"\t"<<bvaResult[y]<<endl;

    cout<<"Reporte creado en el archivo test.txt";
    test.close();
}
