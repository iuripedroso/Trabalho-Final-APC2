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

int create(Filme *filme, int count)
{
	
	cout << endl;
	filme->id = count;
	cout << "Id: " << count << endl;

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
	unsigned int count = 0;
	cout << filme->id; cout << endl;
	cout << filme->nome; cout << endl;
	cout << filme->ano; cout << endl;
	cout << filme-> diretor; cout << endl;
	cout << filme->disponivel; cout << endl;
}

int main()
{
	int count = 1;
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
				
				cout << "\033[2J\033[1;1H"; // Limpa terminal
				cout << "Cadastrar filme!" << endl;
				cout << "----------------" << endl;
				do
				{
					N += create(&filme[N], count);
					count++;
					cout << endl <<  "Continua? S/N " << endl;
				} while (cin >> continua && continua == 'S' || continua == 's');
				cout << "\033[2J\033[1;1H";				
				break;
				
			case 2:
				cout << "\033[2J\033[1;1H"; 
				cout << "Remover filme!" << endl;
				cout << "--------------" << endl;
				do
				{
								cout << "ID do filme que deseja remover: ";
				}
				while (cin >> filme->id);			
				break;

			case 3:
				cout << "\033[2J\033[1;1H";
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
