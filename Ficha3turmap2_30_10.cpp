// Ficha3turmap2.cpp : Defines the entry point for the console application.
//

#include "Aluno_30_10.h"
#include <iostream>

using namespace std;

int main()
{
	const int valor = 2;
	//valor++;
	const Aluno ac("Aluno constante", 12345, {"POO"}, 2, 2, 2002);
	cout << ac.toString();
	cout << ac.getNome();
	//ac.setNome("Outro");
	cout << "olá mundo\n";
	Aluno a("Ana Alves", 123); cout << a.toString();

	cout << ac.e_igual(a);
	cout << a.e_igual(ac);
	cout << a.inscreve("SO");
	cout << a.inscreve("POO");
	cout << a.inscreve("POO");
	cout << a.desinscreve("SO");
	cout << a.toString();
		return 0;
	
}

