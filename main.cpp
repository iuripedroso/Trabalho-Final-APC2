#include <iostream>

using namespace std;

typedef struct
{
	unsigned int id;
	string nome;
	string ano;
	string diretor;
	char disponivel;
}Filme;

// Variaveis globais
int N = 0;         
char continua;     
Filme filme[1000]; 

void imprimirMenu(void)
{
	cout << endl;
	cout << "Sistema de controle e gerencimento de filmes" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Opções: " << endl;
	cout << "(1) Cadastrar filme" << endl;
	cout << "(2) Remover filme" << endl;
	cout << "(3) Vizualizar filmes" << endl;
	cout << "(4) Buscar filme" << endl;
	cout << "(5) Ordenar por ano" << endl;
  cout << "(6) Sair" << endl;
}

int criarEntidade(Filme *filme, int id)
{
	cout << endl;
	filme->id = id;
	cout << "Id: " << id << endl;

	cout << "Nome: ";
	cin.get();
	getline(cin, filme->nome);

	cout << "Ano: ";
	cin >> filme->ano;

	cout << "Diretor: ";
	cin.get();
	getline(cin, filme->diretor);

	cout << "Disponivel? S/N ";
	cin >> filme->disponivel;

	return 1;
}

void imprimirFilme(Filme *filme)
{
	cout << "Id: " << filme->id; cout << endl;
	cout << "Nome: " << filme->nome; cout << endl;
	cout << "Ano: " << filme->ano; cout << endl;
	cout << "Diretor: " << filme-> diretor; cout << endl;
	cout << "Disponivel? " << filme->disponivel; cout << endl;
}

void cadastrarFilme(void)
{
  system("clear||cls");
	cout << "Cadastrar filme!" << endl;
	cout << "----------------" << endl;
	do
	{
		N += criarEntidade(&filme[N], N);
		cout << endl <<  "Continua? S/N " << endl;
	} while (cin >> continua && continua == 'S' || continua == 's');
	system("clear||cls");
}

void removerFilme(void)
{
	system("clear||cls");
  int id;
  cout << "Remover filme!" << endl;
  cout << "--------------" << endl;
  cout << "ID do filme que deseja remover: ";
  cin >> id;

  cout << filme[id].nome << " removido com sucesso!" << endl;

  for (int i = 0; i < N; i++)
  {
    if (filme[i].id == id)
    {
        for (int j = i; j < N - 1; j++)
        {
            filme[j] = filme[j + 1];
        }
        N--;
    }

  }
  for (int i = 0; i < N; i++)
  {
    filme[i].id = i;
  }
}

void filmesEmEstoque(void)
{
	system("clear||cls");
	cout << endl <<  "Filmes em estoque: " << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < N; i++)
	{
	  imprimirFilme(&filme[i]);
		cout << endl;
	}
}

void buscarFilme(void)
{
	system("clear||cls");
	int n;
	cout << "Buscar filme" << endl;
	cout << "------------" << endl;
	cout << "Buscar por id: " << endl;
	cin >> n;
  
  // Busca iterativa
	for (int i = 0; i < N; i++)
	{
		if (filme[i].id == n)
		{
			system("clear||cls");
			cout << "Filme econtrado!" << endl;
			cout << "----------------" << endl;
      imprimirFilme(&filme[i]);
      return;
		}
	}
  cout << "Id nao existe" << endl;
  return;
}

void carregarFilmes(void)
{
  filme[0].id = 0;
  filme[0].nome = "Arrival";
  filme[0].ano = "2016";
  filme[0].diretor = "Denis Villeneuve";
  filme[0].disponivel = 'S';
  N++;

  filme[1].id = 1;
  filme[1].nome = "The Mirror";
  filme[1].ano = "1975";
  filme[1].diretor = "Andrei Tarkovski";
  filme[1].disponivel = 'N';
  N++;

  filme[2].id = 2;
  filme[2].nome = "As Branquelas";
  filme[2].ano = "2004";
  filme[2].diretor = "Keene Ivory Wayans";
  filme[2].disponivel = 'S';
  N++;

  filme[3].id = 3;
  filme[3].nome = "Interstellar";
  filme[3].ano = "2014";
  filme[3].diretor = "Christopher Nolan";
  filme[3].disponivel = 'S';
  N++;
  

}

void troca(Filme *a, Filme *b)
{
  Filme aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void ordenarPorANo(Filme *v, int n)
{
  system("clear||cls");
  if (n > 1)
  {
    for (int i = 0; i < n - 1; i++)
    {
      if (v[i].ano > v[i + 1].ano)
      {
        troca(&v[i], &v[i + 1]);
      }
    }
    ordenarPorANo(v, n - 1);
  }
}

int main()
{
  carregarFilmes();
	int op;

 	while (op != 6)
	{
		imprimirMenu();
    cin >> op;
	
		switch(op)
		{
			case 1:
        cadastrarFilme();
				break;

			case 2:
        removerFilme();
				break;

			case 3:
        filmesEmEstoque();
				break;

			case 4:
        buscarFilme();
				break;
      case 5:
        ordenarPorANo(filme, N);
        break;
		}
	}
	return 0;
}
