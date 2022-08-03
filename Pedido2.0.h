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
     void adicionar_pedido_comprimido(string,int, Farmacia );       // adiciona um pedido procurando por ele na lista de comprimidos
     void adicionar_pedido_liquido(string,int, Farmacia );           // adiciona um pedido procurando por ele na lista de liquidos
     void remover_pedido_comprimido(string);                     // remove um remedio da lista de comprimidos
     void remover_pedido_liquido(string);                        // remove um remedio da lista de liquidos
     void exibir_pedido_comprimido();
     void exibir_pedido_liquido();
     void concluir_pedido();
     float get_valor_total();
     void cancelar_pedido();
     bool verificar_ocupacao_comprimido();                               // verificar se a lista dos comprimidos está vazia
     bool verificar_ocupacao_liquido();                                  // verificar se a lista dosm liquidos está vazia
     bool verifica_tarja(string);
     void verifica_desconto();
     static bool ordenar_preco_comprimido(Comprimido, Comprimido);
     static bool ordenar_preco_liquido(Liquido, Liquido);
};


#endif // PEDIDO_H
