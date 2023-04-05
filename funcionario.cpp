#include <iostream>
#include <string>

using namespace std;

//Funcionario
class Funcionario{
  public:
    Funcionario();
    Funcionario(int matricula, string nome, float salario);

    //Gets
    int getMatricula();
    string getNome();
    float getSalario();
    //Sets
    void setMatricula(int matricula);
    void setNome(string nome);
    void setSalario(float salario);   

  protected:
    int matricula;
    float salario;
    string nome;
};

Funcionario::Funcionario() : Funcionario(0, "vazio", 0) {

}
Funcionario::Funcionario(int matricula, string nome, float salario) {
  setMatricula(matricula);
  setNome(nome);
  setSalario(salario);
}

//Gets implementation
int Funcionario::getMatricula() {
  return matricula;
}
string Funcionario::getNome() {
  return nome;
}
float Funcionario::getSalario() {
  return salario;
}


//Sets implementation
void Funcionario::setMatricula(int matricula) {
  this->matricula = matricula;
}
void Funcionario::setNome(string nome) {
  this->nome = nome;
}
void Funcionario::setSalario(float salario) {
  this->salario = salario;
}

//Funcionario END

//Consultor
class Consultor : public Funcionario {
  public:
    Consultor();
    Consultor(int matricula, string nome, float salario);

    //Gets reimplementation
    float getSalario();
    float getSalario(float percentual);

  private:
};

Consultor::Consultor() : Funcionario() {}

Consultor::Consultor(int matricula, string nome, float salario) : Funcionario(matricula, nome, salario) {}

float Consultor::getSalario() {
  return salario*1.1;
}
float Consultor::getSalario(float percentual) {
  return salario*(1 + percentual);
}
//Consultor END


int main() {
  Funcionario *f1;
  Consultor *c1;
  int matricula;
  float salario;
  string nome;

  //Matricula for funcionario
  cin >> matricula;
  //Cleaning buffer
  cin.ignore();
  getline(cin, nome);
  cin >> salario;

  f1 = new Funcionario(matricula, nome, salario);

  //Matricula for Consultor
  cin >> matricula;
  //Cleaning buffer
  cin.ignore();
  getline(cin, nome);
  cin >> salario;

  c1 = new Consultor(matricula, nome, salario);

  //Displays f1
  cout << f1->getMatricula() << " - " << f1->getNome() << " - R$ " << f1->getSalario() << endl;
  //Displays c1
  cout << c1->getMatricula() << " - " << c1->getNome() << " - R$ " << c1->getSalario() << endl;

  return 0;
}