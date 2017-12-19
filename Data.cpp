#include "Data.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Data::Data(int d, int m, int a) {
	//Falta testar se são válidos
	if (!setD(d))
		this->d = 1;
	if(! setM(m))
		this->m = 1;
	if (!setA(a))
		this->a = 2000;
	cout << "A construir data\n";
}
Data::~Data() {
	cout << "A destruir data\n";
}
string Data::toString() const {
	ostringstream os;
	
	os << setw(2) << setfill('0') << d << "/" << setw(2) << setfill('0') << m << "/";
	os << setw(4) << a;
	return os.str();
}

int Data::getD() const {
	return d;
}
int Data::getM() const {
	return m;
}
int Data::getA() const {
	return a;
}
bool Data::setD(unsigned int d) {
	if (d <= 311 && d >= 1) {
		this->d = d;
		return true;
	}
	return false;
}
bool Data::setM(unsigned int m) {
	if (m <= 12 && m >= 1) {
		this->m = m;
		return true;
	}
	return false;
}
bool Data::setA(unsigned int a){
	this->a = a;
	return true;
}

