#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#include "Remedio2.0.cpp"
#include "Comprimido2.0.cpp"
#include "Liquido2.0.cpp"
#include "Farmacia2.0.cpp"
#include "Pedido2.0.cpp"

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

    Farmacia NossaFarmacia;
    Pedido CaixaDaNossaFarmacia;

    while(1)
    	{
        	system("cls");
        	cout << "======================================================================================= " << endl;
        	cout << "==================== Bem Vindo a Farmacia Sua Saude  ==================== " << endl;
        	cout << "======================================================================================= " << endl;
        	cout << "1) Adicionar Comprimido " << endl;
        	cout << "2) Mostrar Comprimidos Disponiveis " << endl;
        	cout << "3) Adicionar Comprimido ao carrinho" << endl;
        	cout << "4) Remover Comprimidos do carrinho" <<endl;
        	cout << "5) Adicionar Liquidos " << endl;
        	cout << "6) Mostrar Liquidos " << endl;
        	cout << "7) Adicionar Liquidos ao carrinho" << endl;
        	cout << "8) Remover Liquidos do carrinho" << endl;
        	cout << "9) Mostrar Comprimidos do carrinho" << endl;
        	cout << "10) Mostrar Liquidos do carrinho" << endl;
        	cout << "11) Cancelar pedido" << endl;
        	cout << "12) Concluir pedido" << endl;
        	cout << "13) Sair do Sistema " <<endl << endl;
        	cout << "Digite uma opcao aqui : " ;
        	cin >> OP;

        	if (OP == 13) //Sair do Sistema
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

        			NossaFarmacia.adicionar_comprimido(c1);
        			quant++;
        			break;
            	}

            	case 2:
				{
            		NossaFarmacia.exibir_comprimido();
            		break;
				}

				case 3:
				{
                    cout << "Nome do Remedio : " ;
        			cin >> nome;

        			CaixaDaNossaFarmacia.adicionar_pedido_comprimido(nome,10,NossaFarmacia);
        			break;
				}

				case 4:
				{
                    cout << "Nome do Remedio : " ;
        			cin >> nome;
        			CaixaDaNossaFarmacia.remover_pedido_comprimido(nome);
        			break;
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

					NossaFarmacia.adicionar_liquido(l1);
					break;
				}

				case 6:
				{
					NossaFarmacia.exibir_liquido();
					break;
				}

				case 7:
                {
                    cout << "Nome do Remedio : " ;
        			cin >> nome;

        			CaixaDaNossaFarmacia.adicionar_pedido_liquido(nome,10,NossaFarmacia);
        			break;
                }

                case 8:
                {
                    cout << "Nome do Remedio : " ;
        			cin >> nome;

        			CaixaDaNossaFarmacia.remover_pedido_liquido(nome);
        			break;
                }

                case 9:
                {
                    if (CaixaDaNossaFarmacia.verificar_ocupacao_comprimido() == false)
                    {
                        cout << "Não ha pedidos no carrinho" ;
                        break;
                    }
        			else
                    {
                        CaixaDaNossaFarmacia.exibir_pedido_comprimido();
                        break;
                    }

                }

                case 10:
                {
                    if (CaixaDaNossaFarmacia.verificar_ocupacao_liquido() == false)
                    {
                        cout << "Nao ha pedidos no carrinho" ;
                        break;
                    }
        			else
                    {
                        CaixaDaNossaFarmacia.exibir_pedido_liquido();
                        break;
                    }
                }

                case 11: // cancelar pedido
                {
                    if (CaixaDaNossaFarmacia.verificar_ocupacao_liquido() == false && CaixaDaNossaFarmacia.verificar_ocupacao_comprimido() == false)
                    {
                        cout << "Nao ha pedidos no carrinho" ;
                        break;
                    }
                    else
                    {
                        CaixaDaNossaFarmacia.cancelar_pedido();
                        cout << "Pedido cancelado" << endl;
                        break;
                    }
                }
                case 12:
                {
                    if (CaixaDaNossaFarmacia.verificar_ocupacao_liquido() == false && CaixaDaNossaFarmacia.verificar_ocupacao_comprimido() == false)
                    {
                        cout << "Nao ha pedidos no carrinho" ;
                        break;
                    }
                    else
                    {
                        cout << "Pedido concluido, valor total da compra: RS" << CaixaDaNossaFarmacia.get_valor_total() << endl;
                        CaixaDaNossaFarmacia.concluir_pedido();
                        break;
                    }
                }

			}
			system("pause");
		}







    return 0;
}
