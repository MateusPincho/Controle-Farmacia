#include "Remedio.h"

Remedio::Remedio(string nome,string gtin,string validade, float preco, string marca, string tarja, string tipo, int unidades){
    this-> nome = nome;
    this-> gtin = gtin;
    this-> validade = validade;
    this-> preco = preco;
    this-> marca = marca;
    this-> tarja = tarja;
    this-> tipo = tipo;
    this-> unidades = unidades;
}

Remedio::Remedio(){
    this-> nome = " " ;
    this-> gtin = " " ;
    this-> validade = " " ;
    this-> preco = 0.0 ;
    this-> marca = " ";
    this-> tarja = " " ;
    this-> tipo = " " ;
    this-> unidades = 0 ;

}

void Remedio::set_nome(string nome){
    this-> nome = nome;
}

string Remedio::get_nome(){
    return nome;
}

void Remedio::set_gtin(string gtin){
    this-> gtin = gtin;
}

string Remedio::get_gtin(){
    return gtin;
}

void Remedio::set_validade(string validade){
    this-> validade = validade;
}

string Remedio::get_validade(){
    return validade;
}

void Remedio::set_preco(float preco){
    this-> preco = preco;
}

float Remedio::get_preco(){
    return preco;
}

void Remedio::set_marca(string marca){
    this-> marca = marca;
}

string Remedio::get_marca(){
    return marca;
}

void Remedio::set_tarja(string tarja){
    this-> tarja = tarja;
}

string Remedio::get_tarja(){
    return tarja;
}

void Remedio::set_tipo(string tipo){
    this-> tipo = tipo;
}

string Remedio::get_tipo(){
    return tipo;
}

void Remedio::set_unidades(int unidades){
    this-> unidades = unidades;
}

int Remedio::get_unidades(){
    return unidades;
}




