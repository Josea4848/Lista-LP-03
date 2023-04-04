#include <iostream>
#include <string>

#define MAX_SIZE 10

using namespace std;

//Pedido
class Pedido{
    public:
        Pedido();
        Pedido(string descricao, int numero, float preco, int quantidade);

        //Gets
        string getDescricao();
        int getNumero();
        float getPreco();
        int getQuantidade();
        float getTotal();

        //Sets
        void setDescricao(string descricao);
        void setNumero(int numero);
        void setPreco(float preco);
        void setQuantidade(int quantidade);

    private:
        string descricao;
        int numero, quantidade;
        float preco;
};

Pedido::Pedido() : Pedido("vazio", -1, 0.0, 0.0) {

}
Pedido::Pedido(string descricao, int numero, float preco, int quantidade) {
    setDescricao(descricao);
    setNumero(numero);
    setPreco(preco);
    setQuantidade(quantidade);
}


string Pedido::getDescricao() {
    return descricao;
}
int Pedido::getNumero() {
    return numero;
}
float Pedido::getPreco() {
    return preco;
}
int Pedido::getQuantidade() {
    return quantidade;
}
float Pedido::getTotal() {
    return quantidade*preco;
}


void Pedido::setDescricao(string descricao) {
    this->descricao = descricao;
}
void Pedido::setNumero(int numero) {
    this->numero = numero;
}
void Pedido::setPreco(float preco) {
    this->preco = preco;
}
void Pedido::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}
//Pedido END


//Mesa De Restaurante
class MesaDeRestaurante {
    public:
        MesaDeRestaurante();

        void adicionarPedido(Pedido p);
        void zeraPedidos();
        float calculaTotal();
        void exibeConta();

    private:
        int index = 0;
        Pedido pedidos[MAX_SIZE];
        bool possui;
};

MesaDeRestaurante::MesaDeRestaurante() {

}

void MesaDeRestaurante::adicionarPedido(Pedido p) {
    possui = false;

    for(int i = 0; i < MAX_SIZE; i++) {
        if(pedidos[i].getDescricao() == p.getDescricao()) {
            pedidos[i].setQuantidade(pedidos[i].getQuantidade() + p.getQuantidade());
            possui = true;
        }
    }

    //Caso o pedido não tenha sido encontrado
    if(!possui) {
        pedidos[index].setDescricao(p.getDescricao());
        pedidos[index].setNumero(p.getNumero());
        pedidos[index].setPreco(p.getPreco());
        pedidos[index].setQuantidade(p.getQuantidade());
        index++;
    }
}

void MesaDeRestaurante::zeraPedidos() {
    for(int i = 0; pedidos[i].getDescricao() != "vazio"; i++) {
        pedidos[i].setQuantidade(0);
    }
}

float MesaDeRestaurante::calculaTotal() {
    float total = 0;

    for(int i = 0; pedidos[i].getDescricao() != "vazio"; i++) {
        total += pedidos[i].getTotal();
    }

    return total;
}

void MesaDeRestaurante::exibeConta() {
    for(int i = 0; pedidos[i].getDescricao() != "vazio"; i++) {
        cout << pedidos[i].getNumero() << " - " << pedidos[i].getDescricao() << " - " << pedidos[i].getQuantidade() << " - " << pedidos[i].getPreco() << " - R$ " << pedidos[i].getTotal() << endl;
    }
}

//Mesa De Restaurante END


//Restaurante
class Restaurante {
    public:
        Restaurante();

        void adicionarPedido(Pedido p, int indMesa);
        float calculaTotalRestaurante();
        MesaDeRestaurante getMesa(int indMesa);
    private:
        MesaDeRestaurante mesas[MAX_SIZE];
};

Restaurante::Restaurante() {

}

void Restaurante::adicionarPedido(Pedido p, int indMesa) {
    mesas[indMesa].adicionarPedido(p);
}

MesaDeRestaurante Restaurante::getMesa(int indMesa) {
  return mesas[indMesa];
}

float Restaurante::calculaTotalRestaurante() {
    float total = 0;

    for(int i = 0; i < MAX_SIZE; i++) {
        total += mesas[i].calculaTotal();
    }

    return total;
}
//Restaurante END

int main() {
    int indice = 0;
    string descricao;
    int quantidade, numero;
    float preco;
    Restaurante r;

    while(true) {
        cin >> numero;

        if(numero < 0) {
            break;
        }

        //Cleaning buffer
        cin.ignore();

        getline(cin, descricao);
        cin >> quantidade;
        cin >> preco;
        cin >> indice;

        r.adicionarPedido(Pedido(descricao, numero, preco, quantidade), indice);
    }

    for(int i = 0; i < MAX_SIZE; i++) {
      if(r.getMesa(i).calculaTotal()) {
        cout << "Mesa " << i << endl;
        r.getMesa(i).exibeConta();
        cout << "Total: R$ " << r.getMesa(i).calculaTotal() << endl << endl;
      }
    }

    cout << "\nTotal Restaurante: R$ " << r.calculaTotalRestaurante() << endl;

    return 0;
}
