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
	
	void adicionar_comprimido(Comprimido);
	void adicionar_liquido(Liquido);
	void remover_comprimido(string,int);
	void remover_liquido(string, int) 
	void pesquisar_comprimido(string) const;
	void pesquisar_liquido(string) const;
	void exibir_comprimido() const;
	void exibir_liquido() const ;
	void verificar_qtd();
	void verificar_remedio(Remedio);
	
	friend class Pedido;
		
};

#endif