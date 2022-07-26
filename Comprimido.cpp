#include "Comprimido.h"	//include do arquivo de cabecalho Comprimido.h

//Construtor default + inicializacao dos atributos da classe Comprimido herdando Remedio
Comprimido::Comprimido(string nome, string gtin , string validade, float preco , string marca , string tarja , string tipo , int unidades, int peso , int quant_comprimidos , int cartelas) : Remedio(nome,gtin,validade,preco,marca,tarja,tipo,unidades)
{
	this-> peso = peso;
	this-> quant_comprimidos = quant_comprimidos;
	this-> cartelas = cartelas;
	
}

//set do peso
void Comprimido::set_peso(int peso)
{
	this-> peso = peso;
}

//get do peso
int Comprimido::get_peso() const 
{
	return peso;
}

//set da quantidade de comprimidos
void Comprimido::set_quant_comprimidos(int quant_comprimidos)
{
	this-> quant_comprimidos = quant_comprimidos;
}

//get da quantidade de comprimidos
int Comprimido::get_quant_comprimidos() const
{
	return quant_comprimidos;
}

//set cartelas
void Comprimido::set_cartelas(int cartelas)
{
	this-> cartelas = cartelas;
}

//get cartelas
int Comprimidos::get_cartelas() const
{
	return cartelas;
}