#include <string>
#include <vector>
#include <initializer_list>
#include "Data.h"
using namespace std;
#ifndef ALUNO_H
#define ALUNO_H
class Aluno {
public:
	const static int ERROR = 9999999;
private:
	vector<string> disciplinas;
	string nome;
	static long serie;
	long n_aluno;
	const long cc;
	Data nascimento;

public:
	Aluno(const string & n, long ident);
	string toString() const; //Esta fun��o n�o mudar� o conte�do do objecto sobre o qual � chamada
	~Aluno();
	Aluno(const string & n, long ident, string lista[], int n_disc);
	Aluno(const string & n, long ident, initializer_list<string> l);
	Aluno(const string & n, long ident, initializer_list<string> l, int d, int m, int a);
	void setDis(initializer_list<string> l) ;
	void setDis(string * l, int c);
	void setNome(const string & n);
	string getNome() const;
	long getNAluno() const;
	vector<string> getDis() const;
	bool e_igual(const Aluno & outro) const;
	bool desinscreve(const string & disciplina); //s� se j� inscrito
	bool inscreve(const string & disciplina); //s� se ainda n�o inscrito
};
#endif
