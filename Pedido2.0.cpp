#include "Pedido.h"

Pedido::Pedido()
{
    valor_total = 0;
}

void Pedido::adicionar_pedido_comprimido(string nome,int quantidade, Farmacia nossa_farmacia)
{

    //Como as classes agora são friends podemos tentar usar o método da pesquisa binaria
    //Estou estudando sobre friends
    int i=nossa_farmacia.pesquisar_comprimido(nome);
    pedidos_comprimidos.push_back(nossa_farmacia.lista_comprimidos[i]);
    int posicao=pedidos_comprimidos.size()-1;
    pedidos_comprimidos[posicao].set_unidades(quantidade);


}

void Pedido::adicionar_pedido_liquido(string nome,int quantidade, Farmacia nossa_farmacia)
{

    int i=nossa_farmacia.pesquisar_liquido(nome);
    pedidos_liquidos.push_back(nossa_farmacia.lista_liquidos[i]);
    int posicao=pedidos_liquidos.size()-1;
    pedidos_liquidos[posicao].set_unidades(quantidade);

}


void Pedido::remover_pedido_comprimido(string nome)
{
    for (unsigned i = 0; i < pedidos_comprimidos.size(); i++)
    {
        if (pedidos_comprimidos[i].get_nome() == nome)
        {
            pedidos_comprimidos.erase(pedidos_comprimidos.begin()+i);
        }
    }
}

void Pedido::remover_pedido_liquido(string nome)
{
    for (unsigned i = 0; i < pedidos_liquidos.size(); i++)
    {
        if (pedidos_liquidos[i].get_nome() == nome)
        {
            pedidos_liquidos.erase(pedidos_liquidos.begin()+i);
        }
    }
}

void Pedido::exibir_pedido_comprimido()
{
    sort(pedidos_comprimidos.begin(),pedidos_comprimidos.end(),ordenar_preco_comprimido);
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
    sort(pedidos_liquidos.begin(),pedidos_liquidos.end(),ordenar_preco_liquido);
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

void Pedido::cancelar_pedido()
{
    for(unsigned i=0;i<pedidos_comprimidos.size();i++)
    {
        pedidos_comprimidos.erase(pedidos_comprimidos.begin());
    }
    for(unsigned i=0;i<pedidos_liquidos.size();i++)
    {
        pedidos_liquidos.erase(pedidos_liquidos.begin());
    }

}

void Pedido::concluir_pedido()
{
    float preco_total;
    for(unsigned i=0;i<pedidos_comprimidos.size();i++)
    {
        preco_total=pedidos_comprimidos[i].get_preco()*pedidos_comprimidos[i].get_unidades();
        valor_total = valor_total+preco_total;
    }
    for(unsigned i=0;i<pedidos_liquidos.size();i++)
    {
        preco_total=pedidos_liquidos[i].get_preco()*pedidos_liquidos[i].get_unidades();
        valor_total = valor_total+preco_total;
    }
    verifica_desconto();
    cout<<"Pedido concluido, o valor total da compra foi de: "<<valor_total;
}
bool Pedido::verifica_tarja(string nome)
{
/*PRECISAMOS PESQUISAR MAIS SOBRE ESSAS CONDIÇÕES DE TARJA PARA APLICAR AO CODIGO
OU ENTÃO MODIFICAR PARA PREESSCRIÇÃO MEDICA, ISSO É APENAS UM DETALHE PODEMOS
RESOLVER FACILMENTE EM UMA REUNIÃO*/
    if(nome=="Preta")
        return true;
    if(nome=="Vermelha")
        return true;
    return false;
}
void Pedido::verifica_desconto()
{
    //Aplicando desconto de 10%
    if(valor_total>100)
    {

        valor_total=valor_total*0.1;
    }
    //Aplicando desconto de 15%
    if(valor_total>200)
    {
        valor_total=valor_total*0.15;
    }
}
bool Pedido::ordenar_preco_comprimido(Comprimido A, Comprimido B)
{
    if(A.get_preco()<B.get_preco())
    {
        return true;
    }
    return false;
}
bool Pedido::ordenar_preco_liquido(Liquido A, Liquido B)
{
    if(A.get_preco()<B.get_preco())
    {
        return true;
    }
    return false;
}
