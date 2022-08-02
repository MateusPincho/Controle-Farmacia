#include "Liquido.h"	//include do arquivo de cabecalho Liquido.h

//Construtor default + inicializacao dos atributos da classe Liquido herdando Remedio
Liquido::Liquido(string nome, string gtin , string validade, float preco , string marca , string tarja , string tipo , int unidades,int pesoliquido, string sabor) : Remedio(nome,gtin,validade,preco,marca,tarja,tipo,unidades)
{
	this-> pesoliquido = pesoliquido ;
	this-> sabor = sabor;
	
}

//set do peso liquido
void Liquido::set_pesoliquido(int pesoliquido)
{
	this-> pesoliquido = pesoliquido;
}

//get do peso liquido
int Liquido::get_pesoliquido() const
{
	return pesoliquido;
}

//set do sabor
void Liquido::set_sabor(string sabor)
{
	this-> sabor = sabor;
}

//get do sabor
string Liquido::get_sabor() const
{
	return sabor;
}