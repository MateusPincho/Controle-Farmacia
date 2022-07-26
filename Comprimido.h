#ifndef Comprimido_H	// para importacao futura do arquivo de cabecalho para um cpp
#define Comprimido_H

class Comprimido : public Remedio //Definicao da Classe comprimido herdando heranca da classe Remedio
{
	
private:
	//Atributos da clase Comprimido
	
	int peso;	//peso do comprimido
	int quant_comprimidos;	//quantidade de comprimidos
	int cartelas;	//quantidade de cartelas
	
public:
	//Construtor default dos atributos da heranca e da classe Comprimido
	Comprimido(string = "Nome Desconhecido" , string = "Codigo Desconhecido" , string = "Validade Desconhecida" , float = 0.0 , string = "Marca Desconhecida" , string = "Tarja desconhecida" , string = "Tipo Desconhecido" , int = 0 , int = 0 , int = 0 , int = 0);
	
	void set_peso(int);
	void set_quant_comprimidos(int);	
	void set_cartelas(int);	
	
	int get_peso() const;	
	int get_quant_comprimidos() const;	
	int get_cartelas() const;	
	
};

#endif	//fim da captacao 

