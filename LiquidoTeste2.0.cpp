#include <string>
#include <iostream>

using namespace std;

#include "Remedio2.0.cpp" ;
#include "Liquido2.0.cpp" ;

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
        int pesoliquido;
        string sabor;


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
        cout << "Peso Liquido : " ;
        cin >> pesoliquido;
        cout << "Sabor : " ;
        cin >> sabor;
        cout << endl;

        Liquido l1(nome, gtin, validade, preco, marca, tarja, tipo, unidades, pesoliquido, sabor);

        l1.set_nome(nome);
        l1.set_gtin(gtin);
        l1.set_validade(validade);
        l1.set_preco(preco);
        l1.set_marca(marca);
        l1.set_tarja(tarja);
        l1.set_tipo(tipo);
        l1.set_unidades(unidades);
        l1.set_pesoliquido(pesoliquido);
        l1.set_sabor(sabor);

        cout << "Nome : " << l1.get_nome() << endl;
        cout << "Codigo GTIN : " << l1.get_gtin() <<endl;
        cout << "Validade : " << l1.get_validade() << endl;
        cout << "Preco : " << l1.get_preco() << endl;
        cout << "Marca : " << l1.get_marca() << endl;
        cout << "Tarja : " << l1.get_tarja() << endl;
        cout << "Tipo : " << l1.get_tipo() << endl;
        cout << "Unidades : " << l1.get_unidades() << endl;
        cout << "Peso Liquido : " << l1.get_pesoliquido() << endl;
        cout << "Sabor : " << l1.get_sabor() ;



	return 0;
}
