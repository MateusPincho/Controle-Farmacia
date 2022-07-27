#ifndef PEDIDO_H
#define PEDIDO_H
class Pedido
{


private:
    vector <Comprimido> pedidos_comprimidos;
	vector <Liquido> pedidos_liquidos;
	float valor_total;

public:
     Pedido();
     void adicionar_pedido_comprimido(string , Farmacia );       // adiciona um pedido procurando por ele na lista de comprimidos
     void adicionar_pedido_liquido(string, Farmacia );           // adiciona um pedido procurando por ele na lista de liquidos
     void remover_pedido_comprimido(string);                     // remove um remedio da lista de comprimidos
     void remover_pedido_liquido(string);                        // remove um remedio da lista de liquidos
     void exibir_pedido_comprimido();
     void exibir_pedido_liquido();
     void concluir_pedido();
     void cancelar_pedido();
     void verifica_tarja(string );
     void verifica_desconto();
     bool ordenar_preco();

};


#endif // PEDIDO_H
