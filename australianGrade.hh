#include <iostream>

using namespace std;

string australianGrade(float grade){
	if(grade >= 83.00 && grade <= 100)
		return "HD";
	else if(grade >= 73.00 && grade < 83)
		return "D";
	else if(grade >= 63.00 && grade < 73)
		return "C";
	else if(grade >= 50.00 && grade < 63)
		return "P";
	else if(grade >= 00.00 && grade < 50)
		return "N";
	else
		return "Nel shavo, esa no es una calificación válida, que estas haciendo con tu vida?";
}