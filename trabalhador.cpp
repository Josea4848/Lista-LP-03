#include <iostream>
#include <string>

using namespace std;

//Trabalhador
class Trabalhador {
  public:
    Trabalhador();

    Trabalhador(string nome);

    //Gets
    string getNome();
    float getSalario();
    //Sets
    void setNome(string nome);
    void setSalario(float salario);

    //Other
    virtual void exibirInfo() = 0;

  protected:
    string nome;
    float salario;
};

Trabalhador::Trabalhador() : Trabalhador("vazio"){}
Trabalhador::Trabalhador(string nome) {
  setNome(nome);
  setSalario(0);
}

string Trabalhador::getNome() {
  return nome;
}
float Trabalhador::getSalario() {
  return salario;
}

void Trabalhador::setNome(string nome) {
  this->nome = nome;
}
void Trabalhador::setSalario(float salario) {
  this->salario = salario;
}
//Trabalhador END

//Assalariado 
class TrabalhadorAssalariado : public Trabalhador {
  public:
    TrabalhadorAssalariado();
    TrabalhadorAssalariado(string nome, float salario);

    //Other methods
    float calcularSalarioSemanal();

    //Virtual methos
    void exibirInfo();

  private:
};

TrabalhadorAssalariado::TrabalhadorAssalariado() : Trabalhador() {}
TrabalhadorAssalariado::TrabalhadorAssalariado(string nome, float salario) : Trabalhador(nome) {
  setSalario(salario);
}

float TrabalhadorAssalariado::calcularSalarioSemanal() {
  return salario/4;
}

void TrabalhadorAssalariado::exibirInfo() {
  cout << getNome() + " - Semanal: R$ " << calcularSalarioSemanal() << " - Mensal: R$ " << getSalario() << endl; 
}
//Assalariado END

//Por Hora
class TrabalhadorPorHora : public Trabalhador {
  public:
    TrabalhadorPorHora();
    TrabalhadorPorHora(string nome, float valorDaHora, float horasTrabalhadas);

    //Gets
    float getValorDaHora();
    float getHorasTrabalhadas();
    //Sets
    void setValorDaHora(float valorDaHora);
    void setHorasTrabalhadas(float horasTrabalhadas);
    //Other methods
    float calcularPagamentoSemanal(float horasTrabalhadas);
    void exibirInfo();

  private:
    float valorDaHora, horasTrabalhadas;
};
TrabalhadorPorHora::TrabalhadorPorHora() : TrabalhadorPorHora("vazio", 0, 0) {}
TrabalhadorPorHora::TrabalhadorPorHora(string nome, float valorDaHora, float horasTrabalhadas) : Trabalhador(nome){
  setValorDaHora(valorDaHora);
  setHorasTrabalhadas(horasTrabalhadas);
}
//Gets
float TrabalhadorPorHora::getValorDaHora() {
  return valorDaHora;
}
float TrabalhadorPorHora::getHorasTrabalhadas() {
  return horasTrabalhadas;
}
//Sets
void TrabalhadorPorHora::setValorDaHora(float valorDaHora) {
  this->valorDaHora = valorDaHora;
}
void TrabalhadorPorHora::setHorasTrabalhadas(float horasTrabalhadas) {
  this->horasTrabalhadas = horasTrabalhadas;
}
//Other methods implementation
float TrabalhadorPorHora::calcularPagamentoSemanal(float horasTrabalhadas) {
  if(horasTrabalhadas <= 40) {
    return valorDaHora*horasTrabalhadas;
  }
  else {
    return valorDaHora*40 + (horasTrabalhadas - 40)*(valorDaHora*1.5);
  }
}
void TrabalhadorPorHora::exibirInfo() {
  cout << getNome() + " - Semanal: R$ " << calcularPagamentoSemanal(horasTrabalhadas) << " - Mensal: R$ " << calcularPagamentoSemanal(horasTrabalhadas)*4 << endl; 
}

//Por Hora END
int main() {
  int N = 0, tipo;

  //Número de trabalhadores
  cin >> N;

  Trabalhador *trabalhadores[N];

  for(int i = 0; i < N; i++) {
    string nome;
    float salario, valorHora, horasTrabalhadas;

    cin >> tipo;
    //Cleaning Buffer
    cin.ignore();

    //Nome
    getline(cin, nome);

    //Trabalhador assalariado
    if(tipo == 1) {
      cin >> salario;

      trabalhadores[i] = new TrabalhadorAssalariado(nome, salario);
    } 
    //Trabalhador por Hora
    else {
      cin >> valorHora;
      cin >> horasTrabalhadas;

      trabalhadores[i] = new TrabalhadorPorHora(nome, valorHora, horasTrabalhadas);
    }
  }

  for(int i = 0; i < N; i++) {
    trabalhadores[i]->exibirInfo();
  }

  return 0;
}