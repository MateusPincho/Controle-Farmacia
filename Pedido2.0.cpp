#include "Pedido2.0.h"

Pedido::Pedido()
{
    valor_total = 0;
}

void Pedido::adicionar_pedido_comprimido(string nome,int quantidade, Farmacia nossa_farmacia)
{
    // Está função irá adicionar um pedido a lista
    // Seus parametros são o nome do remedio, a quantidade desejada e o estoque dos remedios

    //Como as classes agora são friends podemos tentar usar o método da pesquisa binaria
    //Estou estudando sobre friends

    // Pesquisar no estoque o nome do remedio, caso encontre adicionar na lista de pedidos
    for (unsigned i = 0; i < nossa_farmacia.lista_comprimidos.size(); i++)
    {
        if (nossa_farmacia.lista_comprimidos[i].get_nome() == nome)
        {
            pedidos_comprimidos.push_back(nossa_farmacia.lista_comprimidos[i]);
        }
    }

    // Para setar a quantidade do remedio, precisamos saber a posicao do remedio
    int posicao=pedidos_comprimidos.size()-1;
    pedidos_comprimidos[posicao].set_unidades(quantidade);


}

void Pedido::adicionar_pedido_liquido(string nome,int quantidade, Farmacia nossa_farmacia)
{
    // Está função irá adicionar um pedido a lista
    // Seus parametros são o nome do remedio, a quantidade desejada e o estoque dos remedios

    // Pesquisar no estoque o nome do remedio, caso encontre adicionar na lista de pedidos


    int i=nossa_farmacia.pesquisar_liquido(nome);

    pedidos_liquidos.push_back(nossa_farmacia.lista_liquidos[i]);

    // Para setar a quantidade do remedio, precisamos saber a posicao do remedio
    int posicao=pedidos_liquidos.size()-1;
    pedidos_liquidos[posicao].set_unidades(quantidade);

}


void Pedido::remover_pedido_comprimido(string nome)
{
    // Falta verificar se existe o comprimido -> criar metodo de pesquisa binaria para esta lista
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
    // Falta verificar se existe o liquido -> criar metodo de pesquisa binaria para esta lista
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
    // Lembre de usar o metodo verificar_ocupacao para verificar se há remedios para serem exibidos no pedido
    if(pedidos_comprimidos.empty())
        cout << "A lista está vazia" ;
    else
    {
        sort(pedidos_comprimidos.begin(),pedidos_comprimidos.end(),ordenar_preco_comprimido);
        for (unsigned i = 0; i < pedidos_comprimidos.size(); i++)
        {
            cout << "PEDIDO " << i + 1 << " ========================" << endl;
            cout << "Nome do Remedio : " << pedidos_comprimidos[i].get_nome() << endl;
            cout << "Codigo GTIN do Remedio e : " << pedidos_comprimidos[i].get_gtin() << endl;
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

}



void Pedido::exibir_pedido_liquido()
{
    // Lembre de usar o metodo verificar_ocupacao para verificar se há remedios para serem exibidos no pedido

    sort(pedidos_liquidos.begin(),pedidos_liquidos.end(),ordenar_preco_liquido);
    for (unsigned i = 0; i < pedidos_liquidos.size(); i++)
    {
        cout << "PEDIDO " << i + 1 << " ========================" << endl;
        cout << "Nome do Remedio : " << pedidos_liquidos[i].get_nome() << endl;
        cout << "Codigo GTIN do Remedio e : " << pedidos_liquidos[i].get_gtin() << endl;
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
    // Antes de chamar esta função na main, verificar se existem remedios na lista pelo metodo verificar_ocupacao()
    pedidos_comprimidos.clear();
    pedidos_liquidos.clear();

}

void Pedido::concluir_pedido()
{
    float preco_total;
    float total_comprimidos;
    float total_liquido;
    for(unsigned i=0;i<pedidos_comprimidos.size();i++)
    {
        preco_total=pedidos_comprimidos[i].get_preco()*pedidos_comprimidos[i].get_unidades();
        total_comprimidos = total_comprimidos+preco_total;
    }
    for(unsigned i=0;i<pedidos_liquidos.size();i++)
    {
        preco_total=pedidos_liquidos[i].get_preco()*pedidos_liquidos[i].get_unidades();
        total_liquido = total_liquido+preco_total;
    }

    valor_total = total_comprimidos+total_liquido;

    verifica_desconto();
    //cout<<"Pedido concluido, o valor total da compra foi de: "<<valor_total;
    pedidos_comprimidos.clear();
    pedidos_liquidos.clear();
}

float Pedido::get_valor_total()
{
    return valor_total;
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

bool Pedido::verificar_ocupacao_comprimido()
{
    // Este metodo só irá retornar true quando houver elementos na lista de pedidos

    if (pedidos_comprimidos.empty())
        return false;
    else
        return true;
}

bool Pedido::verificar_ocupacao_liquido()
{
    // Este metodo só irá retornar true quando houver elementos na lista de pedidos

    if (pedidos_liquidos.empty())
        return false;
    else
        return true;
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
