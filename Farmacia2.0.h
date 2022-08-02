#ifndef Farmacia_H
#define Farmacia_H

class Farmacia
{

private:
	vector <Comprimido> lista_comprimidos;
	vector <Liquido> lista_liquidos;

public:
	Farmacia();
	~Farmacia();
	void gravar_arquivo();
	//Bacana fazer o método de salvar arquivo separadamente tmb -Ygor
	void adicionar_comprimido(Comprimido);  //FEITO
	void adicionar_liquido(Liquido);  //FEITO

	void remover_comprimido(string,int);
	void remover_liquido(string, int);

	int pesquisar_comprimido(string);   //FEITO
	int pesquisar_liquido(string);  //FEITO

	void exibir_comprimido();  //FEITO
	void exibir_liquido();  //FEITO

	void verificar_qtd();
	void verificar_remedio(Remedio);

	void imprimir_comprimido(string);
	void imprimir_liquido(string);
	//Ordenamento
	static bool ordenar_comprimido(Comprimido,Comprimido);
    static bool ordenar_liquido(Liquido,Liquido);
	friend class Pedido;

};

#endif
