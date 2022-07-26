#ifndef Liquido_H	// para importacao futura do arquivo de cabecalho para um cpp
#define Liquido_H

class Liquido : public Remedio	//Definicao da Classe comprimido herdando heranca da classe Remedio
{
	
private:
	//Atributos da classe Liquido
	
	int pesoliquido;	//peso liquido do xarope	
	string sabor;	//sabor do xarope
	
public:
	//Construtor default dos atributos da heranca e da classe Liquido
	Liquido(string = "Nome Desconhecido" , string = "Codigo Desconhecido" , string = "Validade Desconhecida" , float = 0.0 , string = "Marca Desconhecida" , string = "Tarja desconhecida" , string = "Tipo Desconhecido" , int = 0, int = 0 , string = "Sabor Desconhecido");
	
	void set_pesoliquido(int);
	void set_sabor(string);
	
	int get_pesoliquido() const;
	string get_sabor() const;
};

#endif //Fim da captacao