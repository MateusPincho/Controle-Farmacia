#include <string>
#include <iostream>

using namespace std;

#include "Remedio2.0.cpp" ;
#include "Comprimido2.0.cpp" ;

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
        int peso;
        int quant_comprimidos;
        int cartelas;


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
        cout << "Peso : " ;
        cin >> peso;
        cout << "Quantidade de Comprimidos : " ;
        cin >> quant_comprimidos;
        cout << "Numero de Cartelas : " ;
        cin >> cartelas;
        cout << endl;

        Comprimido c1(nome, gtin, validade, preco, marca, tarja, tipo, unidades, peso, quant_comprimidos, cartelas);

        c1.set_nome(nome);
        c1.set_gtin(gtin);
        c1.set_validade(validade);
        c1.set_preco(preco);
        c1.set_marca(marca);
        c1.set_tarja(tarja);
        c1.set_tipo(tipo);
        c1.set_unidades(unidades);
        c1.set_peso(peso);
        c1.set_quant_comprimidos(quant_comprimidos);
        c1.set_cartelas(cartelas);

        cout << "Nome : " << c1.get_nome() << endl;
        cout << "Codigo GTIN : " << c1.get_gtin() <<endl;
        cout << "Validade : " << c1.get_validade() << endl;
        cout << "Preco : " << c1.get_preco() << endl;
        cout << "Marca : " << c1.get_marca() << endl;
        cout << "Tarja : " << c1.get_tarja() << endl;
        cout << "Tipo : " << c1.get_tipo() << endl;
        cout << "Unidades : " << c1.get_unidades() << endl;
        cout << "Peso : " << c1.get_peso() << endl;
        cout << "Quantidade de Comprimidos : " << c1.get_quant_comprimidos() << endl;
        cout << "Cartelas : " << c1.get_cartelas() ;


	return 0;
}
