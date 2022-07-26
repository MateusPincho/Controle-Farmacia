#ifndef Remedio_H/*Titulo para o Remedio que será usado na .cpp*/
#define  Remedio_H

class Remedio{
    private:
        string nome;
        string gtin;
        string validade;
        float preco;
        string marca;
        string tarja;
        string tipo;
        int unidades;

    public:
        Remedio(string,
                string,
                string,
                float,
                string,
                string,
                string,
                int);
        Remedio();

        void set_nome(string);
        void set_gtin(string);
        void set_validade(string);
        void set_preco(float);
        void set_marca(string);
        void set_tarja(string);
        void set_tipo(string);
        void set_unidades(int);

        string get_nome();
        string get_gtin();
        string get_validade();
        float  get_preco();
        string get_marca();
        string get_tarja();
        string get_tipo();
        string get_unidades();
};

#endif
