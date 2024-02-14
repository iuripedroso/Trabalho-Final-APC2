#include <iostream>

using namespace std;

typedef struct
{
	unsigned int id;
	string nome;
	int ano;
	string diretor;
	char disponivel; 
}Filme;

void menu(void)
{
	cout << endl;
	cout << "Sistema de controle e gerencimento de filmes" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "OpÃ§Ãµes: " << endl;
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

	cout << "Disponivel? (S/N) ";
	cin >> filme->disponivel;

	return 1;	
}

void read(Filme *filme)
{
	cout <<"Filme id: "<< filme->id; cout << endl;
	cout <<"Nome: "<< filme->nome; cout << endl;
	cout <<"Ano: "<< filme->ano; cout << endl;
	cout <<"Diretor: "<< filme-> diretor; cout << endl;
	cout <<"Disponivel: "<< filme->disponivel; cout << endl;
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
	
		// TODO: colocar tudo que tem dentro dos cases em funÃ§Ãµes.
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
				system("clear||cls");
				break;

			case 2:
				int id;
				system("clear||cls");
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
				cout << "Filme removido do Estoque.";
				break;
				
				
				

			case 3:
				system("clear||cls");
				cout << endl <<  "Filmes em estoque: " << endl;
				cout << "------------" << endl;
				for (int i = 0; i < N; i++)
				{
					read(&filme[i]);
					cout << endl;
				}
				break;

			case 4: 
				system("clear||cls");
				int n;
				cout << "Buscar filme por id:" << endl;
				cout << "------------" << endl;
				cin >> n;

				for (int i = 0; i < N; i++)
					if (filme[i].id == n)
					{
						read(&filme[i]);
					}

		}
	}
	return 0;
}
