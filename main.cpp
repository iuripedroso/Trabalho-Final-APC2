#include <iostream>

using namespace std;

typedef struct
{
	unsigned int id;
	string nome;
	int ano;
	string diretor;
	bool disponivel;
}Filme;

void menu(void)
{
	cout << endl;
	cout << "Sistema de controle e gerencimento de filmes" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Opções: " << endl;
	cout << "(1) Cadastrar filme" << endl;
	cout << "(2) Remover filme" << endl;
	cout << "(3) Vizualizar filmes" << endl;
	cout << "(4) Atualizar dados do filme" << endl;
	cout << "(5) Sair" << endl;
}

int create(Filme *filme)
{
	cout << "Id: ";
	cin >> filme->id;

	cout << "Nome: ";
	cin >> filme->nome;

	cout << "Ano: ";
	cin >> filme->ano;

	cout << "Diretor: ";
	cin >> filme->diretor;

	cout << "Disponivel? ";
	cin >> filme->disponivel;

	return 1;	
}

void read(Filme *filme)
{
	cout << filme->id; cout << endl;
	cout << filme->nome; cout << endl;
	cout << filme->ano; cout << endl;
	cout << filme-> diretor; cout << endl;
	cout << filme->disponivel; cout << endl;
}

int main()
{

	int N = 0;
	char continua;
	Filme filme[1000];
	int op;

	while (op != 5)
	{
		menu();
		cin >> op;
	
		// TODO: colocar tudo que tem dentro dos cases em funções.
		switch(op)
		{
			case 1:
				cout << "Cadastrar filme!" << endl;
				do
				{
					N += create(&filme[N]);
					cout << "Continua? S/N ";
				} while (cin >> continua && continua == 'S' || continua == 's');
				break;
			case 2:
				cout << "Remover filme!" << endl;
				break;
			case 3:
				cout << endl <<  "Filmes em estoque: " << endl;
				for (int i = 0; i < N; i++)
				{
					read(&filme[i]);
					cout << endl;
				}
				break;
			case 4: 
				cout << "Atualizar dados do filme!" << endl;
				break;
		}
	}
	return 0;
}
