#include <string>

using namespace std;


#ifndef DATA_H
#define DATA_H
class Data
{
	unsigned int d, m, a;
public:
	Data(int d, int m, int a);
	~Data();
	string toString() const;
	int getD() const;
	int getM() const;
	int getA() const;
	bool setD(unsigned int d);
	bool setM(unsigned int m);
	bool setA(unsigned int a);
};
#endif
