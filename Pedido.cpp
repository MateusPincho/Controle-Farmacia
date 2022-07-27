#include "Pedido.h"

Pedido::Pedido()
{
    valor_total = 0;
}

void Pedido::adicionar_pedido_comprimido(string nome, Farmacia nossa_farmacia)
{
    /* É preciso, junto do nome do remedio, passar tb como parametro o nosso objeto farmacia criado na main
       Isto é preciso para q a função saiba de onde está vindo o atributo q ela vai acessar  */

    for (int i = 0; i < nossa_farmacia.lista_comprimidos.size(); i++)
    {
        if (nossa_farmacia.lista_comprimidos[i].get_nome() == nome)
        {
            pedidos_comprimidos.push_back(nossa_farmacia.lista_comprimidos[i]);
        }
    }
}

void Pedido::adicionar_pedido_liquido(string nome, Farmacia nossa_farmacia)
{
    /* É preciso, junto do nome do remedio, passar tb como parametro o nosso objeto farmacia criado na main
       Isto é preciso para q a função saiba de onde está vindo o atributo q ela vai acessar  */

    for (int i = 0; i < nossa_farmacia.lista_liquidos.size(); i++)
    {
        if (nossa_farmacia.lista_liquidos[i].get_nome() == nome)
        {
            pedidos_liquidos.push_back(nossa_farmacia.lista_liquidos[i]);
        }
    }
}

void Pedido::remover_pedido_comprimido(string nome)
{
    for (int i = 0; i < pedidos_comprimidos.size(); i++)
    {
        if (pedidos_comprimidos[i].get_nome() == nome)
        {
            pedidos_comprimidos.erase(pedidos_comprimidos.begin()+i);
        }
    }
}

void Pedido::remover_pedido_liquido(string nome)
{
    for (int i = 0; i < pedidos_liquidos.size(); i++)
    {
        if (pedidos_liquidos[i].get_nome() == nome)
        {
            pedidos_liquidos.erase(pedidos_liquidos.begin()+i);
        }
    }
}

void Pedido::exibir_pedido_comprimido()
{
    for (unsigned i = 0; i < pedidos_comprimidos.size(); i++)
   	   {
    		cout << "Nome do Remedio : " << pedidos_comprimidos[i].get_nome() << endl;
    		cout << "Codigo GTIN do Remedio � : " << pedidos_comprimidos[i].get_gtin() << endl;
    		cout << "Validade do Remedio : " << pedidos_comprimidos[i].get_validade()<< endl;
    	   	cout << "Preco do Remedio : RS " << pedidos_comprimidos[i].get_preco() << endl;
    	   	cout << "Marca do Remedio : " << pedidos_comprimidos[i].get_marca() << endl;
    		cout << "Tarja do Remedio : " << pedidos_comprimidos[i].get_tarja() << endl;
    	   	cout << "Tipo do Remedio : " << pedidos_comprimidos[i].get_tipo() <<endl;
    		cout << "Unidades : " << pedidos_comprimidos[i].get_unidades() << endl;
    		cout << "Peso : " << pedidos_comprimidos[i].get_peso() <<endl;
			cout << "Quantidade de comprimidos : " << pedidos_comprimidos[i].get_quant_comprimidos() << endl;
    		cout << "Numero de Cartelas: " << pedidos_comprimidos[i].get_cartelas() <<endl;
        }
}

void Pedido::exibir_pedido_liquido()
{
    for (unsigned i = 0; i < pedidos_liquidos.size(); i++)
   	   {
    		cout << "Nome do Remedio : " << pedidos_liquidos[i].get_nome() << endl;
    		cout << "Codigo GTIN do Remedio � : " << pedidos_liquidos[i].get_gtin() << endl;
    		cout << "Validade do Remedio : " << pedidos_liquidos[i].get_validade()<< endl;
    		cout << "Preco do Remedio : RS " << pedidos_liquidos[i].get_preco() << endl;
    		cout << "Marca do Remedio : " << pedidos_liquidos[i].get_marca() << endl;
    		cout << "Tarja do Remedio : " << pedidos_liquidos[i].get_tarja() << endl;
    		cout << "Tipo do Remedio : " << pedidos_liquidos[i].get_tipo() <<endl;
    		cout << "Unidades : " << pedidos_liquidos[i].get_unidades() << endl;
    		cout << "Peso Liquido : " << pedidos_liquidos[i].get_pesoliquido() <<endl;
    		cout << "Sabor : " << pedidos_liquidos[i].get_sabor() << endl;
        }
}
