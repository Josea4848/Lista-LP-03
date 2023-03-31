#include <iostream>
#include <string>

#define MAX_SIZE 10

using namespace std;

//Pagamento
class Pagamento {
    public:
        Pagamento();
        Pagamento(float valor, string nome);
        
        //Sets
        void setValorPagamento(float valor);
        void setNomeDoFuncionario(string nome);
        
        //Gets
        float getValorPagamento();
        string getNomeDoFuncionario();
        
    private:
        float valorPagamento;
        string nomeDoFuncionario;
};

Pagamento::Pagamento() : Pagamento(-1, "Vazio") {

}

Pagamento::Pagamento(float valor, string nome) {
    setValorPagamento(valor);
    setNomeDoFuncionario(nome);
}

void Pagamento::setValorPagamento(float valor) {
    valorPagamento = valor;
}

void Pagamento::setNomeDoFuncionario(string nome) {
    nomeDoFuncionario = nome;
}

float Pagamento::getValorPagamento() {
    return valorPagamento;
}

string Pagamento::getNomeDoFuncionario() {
    return nomeDoFuncionario;
}

//Pagamento END


//Controle de Pagamentos
class ControleDePagamentos {
    public:
      //Standard Construct
      ControleDePagamentos();
      
      //Sets
      void setPagamento(Pagamento p, int index);

      //Gets
      Pagamento getPagamento(int pos);
      float calculaTotalDePagamentos();
      int getIndexFuncionario(string nomeFuncionario);

    private:
      Pagamento *pagamentos[10];
};

ControleDePagamentos::ControleDePagamentos() {
    for(int i = 0; i < 10; i++) {
      pagamentos[i] = new Pagamento();
    }
}

void ControleDePagamentos::setPagamento(Pagamento p, int index) {
  pagamentos[index] = new Pagamento(p.getValorPagamento(), p.getNomeDoFuncionario());
}

Pagamento ControleDePagamentos::getPagamento(int pos) {
  return *pagamentos[pos];
}

float ControleDePagamentos::calculaTotalDePagamentos() {
  float total = 0;

  for(int i = 0; i < 10; i++) {    
    if(pagamentos[i]->getValorPagamento() == -1) {
      break;
    }
       
    total += pagamentos[i]->getValorPagamento();
  }

  return total;
}

int ControleDePagamentos::getIndexFuncionario(string nomeFuncionario) {
  for(int i = 0; i < 10; i++) {
    if(pagamentos[i]->getValorPagamento() == -1) {
      break;
    }
    
    if(pagamentos[i]->getNomeDoFuncionario().find(nomeFuncionario) != string::npos) {
      return i;
    }
  }
  
  return -1;
}


//Controle de pagamentos END



int main() {
  //Número de funcionários
  int n = 0, index = 0;
  float valor = 0;
  string nomeFuncionario = "";
  ControleDePagamentos p1;

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> valor;
    //Cleaning BUFFER
    cin.ignore();
    getline(cin, nomeFuncionario);

    p1.setPagamento(Pagamento(valor, nomeFuncionario), i);
  }

  //Qual nome de funcionário que deseja encontrar       
  getline(cin, nomeFuncionario);
  index = p1.getIndexFuncionario(nomeFuncionario);

  if(index != -1) {
    cout << p1.getPagamento(index).getNomeDoFuncionario() << ": R$ " << p1.getPagamento(index).getValorPagamento() << endl;
  }
  else {
    cout << nomeFuncionario << " não encontrado(a).\n";
  }

  //Mostrando total
  cout << "Total: R$ " << p1.calculaTotalDePagamentos() << endl;

  return 0;
}