#include <iostream>

using namespace std;

typedef struct
{
	unsigned int id;
	string nome;
	int ano;
	string diretor;
	bool disponivel; // TODO: mudar pra char (s/n)
}Filme;
//PULLLL

void limpa_terminal(void)
{
	cout << "\033[2J\033[1;1H";
}

void menu(void)
{
	cout << endl;
	cout << "Sistema de controle e gerencimento de filmes" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Opções: " << endl;
	cout << "(1) Cadastrar filme" << endl;
	cout << "(2) Remover filme" << endl;
	cout << "(3) Vizualizar filmes" << endl;
	cout << "(4) Buscar filme" << endl;
	cout << "(5) Sair" << endl;
}

int create(Filme *filme, int id)
{	
	cout << endl;
	filme->id = id;
	cout << "Id: " << id << endl;

	cout << "Nome: ";
	cin.get();
	getline(cin, filme->nome);
	//cin >> filme->nome;

	cout << "Ano: ";
	cin >> filme->ano;

	cout << "Diretor: ";
	cin.get();
	//cin >> filme->diretor;
	getline(cin, filme->diretor);

	cout << "Disponivel? (1/0) ";
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
//KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK

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
				system("clear||cls");
				cout << "Cadastrar filme!" << endl;
				cout << "----------------" << endl;
				do
				{
					N += create(&filme[N], N);
					cout << endl <<  "Continua? S/N " << endl;
				} while (cin >> continua && continua == 'S' || continua == 's');
				limpa_terminal();
				break;

			case 2:
				int id;
				limpa_terminal();
				cout << "Remover filme!" << endl;
				cout << "--------------" << endl;
				cout << "ID do filme que deseja remover: ";
				cin >> id;
				for (int i = 0; i < N; i++)
				{
					if (filme[i].id == id) // Busca sequencial
						for (int j = i; j < N; j++)
							filme[j] = filme[j + 1];
				}
				N--;
				for (int i = 0; i < N; i++)
						filme[i].id = i;
				break;

			case 3:
				limpa_terminal();
				cout << endl <<  "Filmes em estoque: " << endl;
				for (int i = 0; i < N; i++)
				{
					read(&filme[i]);
					cout << endl;
				}
				break;

			case 4: 
				limpa_terminal();
				int n;
				cout << "Buscar filme" << endl;
				cout << "------------" << endl;
				cout << "Buscar por id: " << endl;
				cin >> n;

				for (int i = 0; i < N; i++)
					if (filme[i].id == n)
					{
						cout << "Filme econtrado!" << endl;
						cout << "----------------" << endl;
						cout << filme[i].id << endl;
						cout << filme[i].nome << endl;
						cout << filme[i].ano << endl;
						cout << filme[i].diretor << endl;
						cout << filme[i].disponivel << endl;
					}

		}
	}
	return 0;
}
