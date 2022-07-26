#include "Farmacia.h"

Farmacia::Farmacia()
{
	string nome, gtin, validade, marca, tarja , tipo, sabor ;//Variaveis criadas para criar o objeto.
    int unidades, peso, quant_comprimidos, cartelas , pesoliquido;
    float preco;

    //Arquivo aberto para possibilitar a leitura.
    ifstream arquivo;
	arquivo.open("Comprimidos.txt", ios::in); 

    //se o arquivo estiver aberto, usar isso.
	if(arquivo.is_open()){
	    while(!arquivo.eof()){ // enquanto nao for o final do arquivo.
			
            //Salvando os valores lidos
	        getline(arquivo, nome);
			
			if (arquivo.eof())
				break;
			
			getline(arquivo,gtin);
            getline(arquivo,validade);
			arquivo >> preco;
            arquivo.ignore();
            getline(arquivo,marca);
            getline(arquivo,tarja);
            arquivo.ignore();
            getline(arquivo,tipo);
            arquivo >> unidades;
            arquivo >> peso;
            arquivo >> quant_comprimidos;
            arquivo >> cartelas ;
			
            //Criacao do objeto com uso das variaveis criadas.
            Comprimido comp(nome,gtin,validade,preco,marca,tarja,tipo, unidades,peso, quant_comprimidos, cartelas); 
			
            //Adicionando na lista 
            lista_comprimidos.push_back(comp); 
			
            arquivo.ignore();
        } 

        arquivo.close();//Fechando arquivo.
    }
    
    //Caso nao consiga abrir o arquivo.
    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ifstream arquivo2;
	arquivo2.open("Liquidos.txt", ios::in); 

	if(arquivo2.is_open()){
	    while(!arquivo2.eof()){
			
	        getline(arquivo2, nome);
			
			if (arquivo2.eof()) //Para evitar de ler alem do que é necessario.
				break;
			
			getline(arquivo2,gtin);
            getline(arquivo2,validade);
			arquivo2 >> preco;
            arquivo2.ignore();
            getline(arquivo2,marca);
            getline(arquivo2,tarja);
            arquivo2.ignore();
            getline(arquivo2,tipo);
            arquivo2 >> unidades;
            arquivo2 >> pesoliquido;
            getline(arquivo2, sabor);

            Liquidos liq(nome,gtin,validade,preco,marca,tarja,tipo, unidades, pesoliquido, sabor); 
			
            lista_liquidos.push_back(liq);  
			
            arquivo2.ignore();
        } 

        arquivo2.close();//Fechando arquivo.
    }
    
    //Caso o arquivo nao seja aberto.
    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;
}

void Farmacia::gravar_arquivo()
{
	//Cria arquivo e abre para ser gravado os atributos dos objetos da lista.
    ofstream arquivo;
    arquivo.open("Comprimidos.txt", ios::trunc);

    //Escrever todos os atributos no arquivo txt
    if (arquivo.is_open()){
		for (unsigned i=0; i < lista_comprimidos.size(); i++){
			arquivo<<lista_comprimidos[i].get_nome()<<endl;
			arquivo<<lista_comprimidos[i].get_gtin()<<endl;
			arquivo<<lista_comprimidos[i].get_validade()<<endl;
			arquivo<<lista_comprimidos[i].get_preco()<<endl;	
            arquivo<<lista_comprimidos[i].get_marca()<<endl;
            arquivo<<lista_comprimidos[i].get_tarja()<<endl;
            arquivo<<lista_comprimidos[i].get_tipo()<<endl;
            arquivo<<lista_comprimidos[i].get_unidades() <<endl;
            arquivo<<lista_comprimidos[i].get_peso() <<endl;
            arquivo<<lista_comprimidos[i].get_quant_comprimidos() << endl;
            arquivo<<lista_comprimidos[i].get_cartelas() <<endl;
		}

        //Fechando o arquivo.
        arquivo.close();
    }
    
    //Caso o arquivo nao seja aberto.
    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo2;
    arquivo2.open("Liquidos.txt", ios::trunc);

    if (arquivo2.is_open()){
		for (unsigned i=0; i < lista_liquidos.size(); i++){
			arquivo2<<lista_liquidos[i].get_nome()<<endl;
			arquivo2<<lista_liquidos[i].get_gtin()<<endl;
			arquivo2<<lista_liquidos[i].get_validade()<<endl;
			arquivo2<<lista_liquidos[i].get_preco()<<endl;	
            arquivo2<<lista_liquidos[i].get_marca()<<endl;
            arquivo2<<lista_liquidos[i].get_tarja()<<endl;
            arquivo2<<lista_liquidos[i].get_tipo()<<endl;
            arquivo2<<lista_liquidos[i].get_unidades() <<endl;
            arquivo2<<lista_liquidos[i].get_pesoliquido() <<endl;
            arquivo2<<lista_liquidos[i].get_sabor() << endl;
		}

        arquivo2.close();//Fecha arquivo.
	}
    
    //Caso nao seja possivel abrir o arquivo.
    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;
}

}


void Farmacia::adicionar_comprimido(Comprimido c)
{
	lista_comprimidos.push_back(c);
}

void Farmacia::adicionar_liquido(Liquido l)
{
	lista_liquidos.push_back(l);
}

void Farmacia::pesquisar_comprimido(string nzin) const
{
	for (unsigned i = 0; i < lista_comprimidos.size(); i++)
   	   {
            if (lista_comprimidos[i].get_nome() == nzin)
            	{
                	cout << "Nome do Remedio : " << lista_comprimidos[i].get_nome() << endl;
                	cout << "Codigo GTIN do Remedio é : " << lista_comprimidos[i].get_gtin() << endl;
                	cout << "Validade do Remedio : " << lista_comprimidos[i].get_validade()<< endl;
                	cout << "Preco do Remedio : RS " << lista_comprimidos[i].get_preco() << endl;
                	cout << "Marca do Remedio : " << lista_comprimidos[i].get_marca() << endl;
                	cout << "Tarja do Remedio : " << lista_comprimidos[i].get_tarja() << endl;
                	cout << "Tipo do Remedio : " << lista_comprimidos[i].get_tipo() <<endl;
                	cout << "Unidades : " << lista_comprimidos[i].get_unidades() << endl;
                	cout << "Peso : " << lista_comprimidos[i].get_peso() <<endl;
                	cout << "Quantidade de comprimidos : " << lista_comprimidos[i].get_quant_comprimidos() << endl;
                	cout << "Numero de Cartelas: " << lista_comprimidos[i].get_cartelas() <<endl;
            	}
        }
}

void Farmacia::pesquisa_liquido(string name) const
{
	for (unsigned i = 0; i < lista_liquidos.size(); i++)
   	   {
            if (lista_comprimidos[i].get_nome() == nzin)
            	{
                	cout << "Nome do Remedio : " << lista_liquidos[i].get_nome() << endl;
                	cout << "Codigo GTIN do Remedio é : " << lista_liquidos[i].get_gtin() << endl;
                	cout << "Validade do Remedio : " << lista_liquidos[i].get_validade()<< endl;
                	cout << "Preco do Remedio : RS " << lista_liquidos[i].get_preco() << endl;
                	cout << "Marca do Remedio : " << lista_liquidos[i].get_marca() << endl;
                	cout << "Tarja do Remedio : " << lista_liquidos[i].get_tarja() << endl;
                	cout << "Tipo do Remedio : " << lista_liquidos[i].get_tipo() <<endl;
                	cout << "Unidades : " << lista_liquidos[i].get_unidades() << endl;
                	cout << "Peso Liquido : " << lista_liquidos[i].get_pesoliquido() <<endl;
                	cout << "Sabor : " << lista_liquidos[i].get_sabor() << endl;
            	}
        }
}

void Farmacia::exibir_comprimido() const
{
	for (unsigned i = 0; i < lista_liquidos.size(); i++)
   	   {
    		cout << "Nome do Remedio : " << lista_liquidos[i].get_nome() << endl;
    		cout << "Codigo GTIN do Remedio é : " << lista_liquidos[i].get_gtin() << endl;
    		cout << "Validade do Remedio : " << lista_liquidos[i].get_validade()<< endl;
    	   	cout << "Preco do Remedio : RS " << lista_liquidos[i].get_preco() << endl;
    	   	cout << "Marca do Remedio : " << lista_liquidos[i].get_marca() << endl;
    		cout << "Tarja do Remedio : " << lista_liquidos[i].get_tarja() << endl;
    	   	cout << "Tipo do Remedio : " << lista_liquidos[i].get_tipo() <<endl;
    		cout << "Unidades : " << lista_liquidos[i].get_unidades() << endl;
    		cout << "Peso : " << lista_comprimidos[i].get_peso() <<endl;
			cout << "Quantidade de comprimidos : " << lista_comprimidos[i].get_quant_comprimidos() << endl;
    		cout << "Numero de Cartelas: " << lista_comprimidos[i].get_cartelas() <<endl;
        }
}

void Farmacia::exibir_liquido() const
{
	for (unsigned i = 0; i < lista_liquidos.size(); i++)
   	   {
    		cout << "Nome do Remedio : " << lista_liquidos[i].get_nome() << endl;
    		cout << "Codigo GTIN do Remedio é : " << lista_liquidos[i].get_gtin() << endl;
    		cout << "Validade do Remedio : " << lista_liquidos[i].get_validade()<< endl;
    		cout << "Preco do Remedio : RS " << lista_liquidos[i].get_preco() << endl;
    		cout << "Marca do Remedio : " << lista_liquidos[i].get_marca() << endl;
    		cout << "Tarja do Remedio : " << lista_liquidos[i].get_tarja() << endl;
    		cout << "Tipo do Remedio : " << lista_liquidos[i].get_tipo() <<endl;
    		cout << "Unidades : " << lista_liquidos[i].get_unidades() << endl;
    		cout << "Peso Liquido : " << lista_liquidos[i].get_pesoliquido() <<endl;
    		cout << "Sabor : " << lista_liquidos[i].get_sabor() << endl;
        }
}

Farmacia::~Farmacia()
{
	gravar_arquivo();
}