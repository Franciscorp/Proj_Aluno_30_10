#include <iostream>
#include <sstream>
#include "Aluno_30_10.h"
using namespace std;

long Aluno::serie = 21270500;
Aluno::Aluno(const string & n, long ident) :cc(ident>0 ? ident : ERROR) , nascimento(1, 1, 1999){
	n_aluno = serie++;
	nome = n;
	cout << "A construir aluno ..\n";
}

string Aluno::toString() const {
	ostringstream os;
	//Falta data?
	os << "Aluno: " << nome << "(" << n_aluno << "," << cc << "," <<  nascimento.toString() << ")";
	os << "Disciplinas:";
	for (auto & x : disciplinas)
		os << x << ", ";
	os << endl;
	return os.str();
}

Aluno::~Aluno() { cout << "A destruir aluno...\n"; }

Aluno::Aluno(const string & n, long ident, string lista[], int n_disc) :cc(ident>0 ? ident : ERROR) 
, nascimento(1, 1, 1999){
	n_aluno = serie++;
	nome = n;
	if (n_disc > 0) {
		for (int i = 0; i < n_disc; i++)
			disciplinas.push_back(lista[i]);
	}
	cout << "A construit aluno ..\n";
}

Aluno::Aluno(const string & n, long ident, initializer_list<string> l) :cc(ident>0 ? ident : ERROR), 
disciplinas(l), nascimento(1,1, 1999) {
	n_aluno = serie++;
	nome = n;
	int i = 0;
	cout << "A construit aluno ..\n";
}

Aluno::Aluno(const string & n, long ident, initializer_list<string> l, int d, int m, int a)
	:cc(ident>0 ? ident : ERROR), disciplinas(l), nascimento(d,m,a) {
	n_aluno = serie++;
	nome = n;
	int i = 0;
	cout << "A construit aluno ..\n";
}



//Ainda podia ser mais eficiente, na passagem do argumento l
void Aluno::setDis(initializer_list<string> l)  {
	disciplinas.clear();
	for (auto x : l)
		disciplinas.push_back(x);
}
void Aluno::setDis(string * l, int c) {
	disciplinas.clear();
	for (int i = 0; i < c; i++)
		disciplinas.push_back(l[i]);
}
void Aluno::setNome(const string & n)  {
	if (n != "")
		nome = n;
}
//Ainda podia ser mais eficiente, no retorno da função
string Aluno::getNome() const {
	return nome;
}

long Aluno::getNAluno() const {
	return n_aluno;
}

//Ainda podia ser mais eficiente, no retorno da função
vector<string> Aluno::getDis() const{
	return disciplinas;
}

bool Aluno::e_igual(const Aluno & outro) const {
	bool resultado = false;
	if (this->nome == outro.nome && this->n_aluno == outro.n_aluno && this->cc == outro.cc)
		resultado = true;
	return resultado;
}

bool Aluno::desinscreve(const string & disciplina) { //só se já inscrito
	auto ptr = disciplinas.begin();
	bool result = false;
	while (ptr != disciplinas.end())
		if ((*ptr) == disciplina) {
			ptr = disciplinas.erase(ptr);
			result = true;
		}
		else
			ptr++;
	return true;
}

bool Aluno::inscreve(const string & disciplina) {
	bool result = true;
	for(auto d: disciplinas)
		if (d == disciplina) {
			result = false;
			break;
		}
	if (result)
		disciplinas.push_back(disciplina);
	return result;

}//só se ainda não inscrito