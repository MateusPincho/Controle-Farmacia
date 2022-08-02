#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#include "Remedio.cpp" ;
#include "Comprimido.cpp" ;
#include "Liquido.cpp" ;
#include "Farmacia.cpp" ;

int main()
{
		string nome;
        string gtin;
        string validade;
        float preco;
        string marca;
        string tarja;
        string tipo;
        int unidades;
        int peso;
        int quant_comprimidos;
        int cartelas;
        int quant;
        int OP;
        int pesoliquido;
        string sabor;
        
        Farmacia f1;
        
        
       while(1)
    	{
        	system("cls");
        	cout << "======================================================================================= " << endl;
        	cout << "==================== Bem Vindo a Farmacia Sua Saude  ==================== " << endl;
        	cout << "======================================================================================= " << endl;
        	cout << "1) Adicionar Comprimido " << endl;
        	cout << "2) Mostrar Comprimidos Disponiveis " << endl;
        	cout << "3) Pesquisar Comprimido " << endl;
        	cout << "4) Remover Comprimidos " <<endl;
        	cout << "5) Adicionar Liquidos " << endl;
        	cout << "6) Mostrar Liquidos " << endl;
        	cout << "7) Pesquisar Liquidos " << endl;
        	cout << "8) Remover Liquidos" << endl;
        	cout << "9) Sair do Sistema " <<endl << endl;
        	cout << "Digite uma opcao aqui : " ;
        	cin >> OP;

        	if (OP == 9) //Sair do Sistema
            	break;

        	system("cls");

        	switch(OP)
        	{
            	case 1: //Adicionar comprimido
            	{
                	cout << "Nome do Remedio : " ;
        			cin >> nome;
        			cout << "Codigo GTIN : " ;
        			cin >> gtin;
        			cout << "Validade : " ;
        			cin >> validade;
					cout << "Preco : " ;
        			cin >> preco;
        			cout << "Marca do Remedio : " ;
        			cin >> marca;
        			cout << "Tarja do Remedio : " ;
        			cin >> tarja;
        			cout << "Tipo do Remedio : " ;
        			cin >> tipo;
        			cout << "Unidades : " ;
        			cin >> unidades;
        			cout << "Peso : " ;
        			cin >> peso;
        			cout << "Quantidade de Comprimidos : " ;
        			cin >> quant_comprimidos;
        			cout << "Numero de Cartelas : " ;
        			cin >> cartelas;
        			cout << endl;
        			
        			Comprimido c1(nome, gtin, validade, preco, marca, tarja, tipo, unidades, peso, quant_comprimidos, cartelas);
        			
        			f1.adicionar_comprimido(c1);
        			quant++;
        			break;
            	}
            	case 2:
				{
            		f1.exibir_comprimido();
            		break;
				}
				case 3:
				{
					
				}
				case 4:
				{
					
				}
				case 5:
				{
					cout << "Nome do Remedio : " ;
        			cin >> nome;
        			cout << "Codigo GTIN : " ;
        			cin >> gtin;
        			cout << "Validade : " ;
        			cin >> validade;
        			cout << "Preco : " ;
        			cin >> preco;
        			cout << "Marca do Remedio : " ;
        			cin >> marca;
        			cout << "Tarja do Remedio : " ;
        			cin >> tarja;
        			cout << "Tipo do Remedio : " ;
        			cin >> tipo;
        			cout << "Unidades : " ;
        			cin >> unidades;
        			cout << "Peso Liquido : " ;
        			cin >> pesoliquido;
        			cout << "Sabor : " ;
        			cin >> sabor;
        			cout << endl;
        
					Liquido l1(nome, gtin, validade, preco, marca, tarja, tipo, unidades, pesoliquido, sabor);
					
					f1.adicionar_liquido(l1);
					break;
				}
				case 6:
				{
					f1.exibir_liquido();
					break;
				}
			}
			system("pause");
		}
	
	
	return 0;
}