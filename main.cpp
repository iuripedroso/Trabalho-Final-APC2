
#include <iostream>

using namespace std;
//4.0

typedef struct
{
    unsigned int id;
    string nome;
    int ano;
    string diretor;
    char disponivel;
} Filme;

void menu(void)
{
    cout << endl;
    cout << "Sistema de controle e gerenciamento de filmes" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Opções: " << endl;
    cout << "(1) Cadastrar filme" << endl;
    cout << "(2) Remover filme" << endl;
    cout << "(3) Visualizar filmes" << endl;
    cout << "(4) Buscar filme" << endl;
    cout << "(5) Sair" << endl;
}

int create(Filme *filme, int id)
{
    cout << endl;
    filme->id = id;
    cout << "Id: " << id << endl;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, filme->nome);

    cout << "Ano: ";
    cin >> filme->ano;

    cout << "Diretor: ";
    cin.ignore();
    getline(cin, filme->diretor);

    cout << "Disponivel? (S/N) ";
    cin >> filme->disponivel;

    return 1;
}

void read(Filme *filme)
{
    cout << "Filme id: " << filme->id << endl;
    cout << "Nome: " << filme->nome << endl;
    cout << "Ano: " << filme->ano << endl;
    cout << "Diretor: " << filme->diretor << endl;
    cout << "Disponivel: " << filme->disponivel << endl;
}

void Remover_Filme(Filme *filme, int *N)
{
	system("clear||cls");
    int id;
    cout << "Remover filme!" << endl;
    cout << "--------------" << endl;
    cout << "ID do filme que deseja remover: ";
    cin >> id;

    for (int i = 0; i < *N; i++)
    {
        if (filme[i].id == id)
        {
            for (int j = i; j < *N - 1; j++)
            {
                filme[j] = filme[j + 1];
            }
            (*N)--;
            break;
        }
    }

    for (int i = 0; i < *N; i++)
        filme[i].id = i;
        system("clear||cls");
    cout << "Filme removido do Estoque." << endl;
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

        switch (op)
        {
        case 1:
            system("clear||cls");
            cout << "Cadastrar filme!" << endl;
            cout << "----------------" << endl;
            do
            {
                N += create(&filme[N], N);
                cout << endl
                     << "Continua? S/N ";
                cin >> continua;
            } while (continua == 'S' || continua == 's');
            system("clear||cls");
            break;

        case 2:
            Remover_Filme(filme, &N);
            break;

        case 3:
            system("clear||cls");
            cout << endl
                 << "Filmes em estoque: " << endl;
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

            break;
        }
    }
    return 0;
}
