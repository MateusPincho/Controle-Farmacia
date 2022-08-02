#include <string>
#include <iostream>

using namespace std;

#include "Remedio.cpp";

int main()
{
		string nome;
        string gtin;
        string validade;
        float preco;
        string marca;
        string tarja;
        string tipo;
        int unidades;
        
        
        cout << "Nome do Remedio : " ;
        cin >> nome;
        cout << "Codigo GTIN : " ;
        cin >> gtin;
        cout << "Validade : " ;
        cin >> validade;
        cout << "Preco : " ;
        cin >> preco;
        cout << "Marca do Remedio : " ;
        cin >> marca;
        cout << "Tarja do Remedio : " ;
        cin >> tarja;
        cout << "Tipo do Remedio : " ;
        cin >> tipo;
        cout << "Unidades : " ;
        cin >> unidades;
        cout << endl;
        
        Remedio r1(nome, gtin, validade, preco, marca, tarja, tipo, unidades);
        
        r1.set_nome(nome);
        r1.set_gtin(gtin);
        r1.set_validade(validade);
        r1.set_preco(preco);
        r1.set_marca(marca);
        r1.set_tarja(tarja);
        r1.set_tipo(tipo);
        r1.set_unidades(unidades);
        
        cout << "Nome : " << r1.get_nome() << endl;
        cout << "Codigo GTIN : " << r1.get_gtin() <<endl;
        cout << "Validade : " << r1.get_validade() << endl;
        cout << "Preco : " << r1.get_preco() << endl;
        cout << "Marca : " << r1.get_marca() << endl;
        cout << "Tarja : " << r1.get_tarja() << endl;
        cout << "Tipo : " << r1.get_tipo() << endl;
        cout << "Unidades : " << r1.get_unidades() ;
	
	
	
	return 0;
}