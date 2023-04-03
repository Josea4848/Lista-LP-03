#include <iostream>
#include <string>

using namespace std;

//Endereco
class Endereco {
  public:
    Endereco();
    Endereco(string rua, string bairro, string cidade, string estado, string cep, string numero);

    string toString();

    //Sets
    void setRua(string rua);
    void setBairro(string bairro);
    void setCidade(string cidade);
    void setEstado(string estado);
    void setCep(string cep);
    void setNumero(string numero);

    //Gets
    string getRua();
    string getBairro();
    string getCidade();
    string getEstado();
    string getCep();
    string getNumero();


  private:
    string rua, bairro, cidade, estado, numero, cep;
};

Endereco::Endereco() : Endereco("Vazio", "Vazio", "Vazio", "Vazio", "Vazio", "Vazio") {

}

Endereco::Endereco(string rua, string bairro, string cidade, string estado, string cep, string numero) {
  setRua(rua);
  setBairro(bairro);
  setCidade(cidade);
  setEstado(estado);
  setCep(cep);
  setNumero(numero);
}

string Endereco::toString() {
  return getRua() + ", " + getNumero() + ", " + getBairro() + ". " + getCidade() + " - " + getEstado() + ". CEP: " + getCep();
}

//Sets Implementation
void Endereco::setRua(string rua) {
  this->rua = rua;
}
void Endereco::setBairro(string bairro) {
  this->bairro = bairro;
}
void Endereco::setCidade(string cidade) {
  this->cidade = cidade;
}
void Endereco::setEstado(string estado) {
  this->estado = estado;
}
void Endereco::setCep(string cep) {
  this->cep = cep;
}
void Endereco::setNumero(string numero) {
  this->numero = numero;
}

//Gets Implementation
string Endereco::getRua() {
  return rua;
}
string Endereco::getBairro() {
  return bairro;
}
string Endereco::getCidade() {
  return cidade;
}
string Endereco::getEstado() {
  return estado;
}
string Endereco::getCep() {
  return cep;
}
string Endereco::getNumero() {
  return numero;
}

//Endereco END

//Pessoa
class Pessoa {
  public:
    Pessoa();
    Pessoa(string nome);
    Pessoa(string nome, string telefone, Endereco endereco);

    //Sets
    void setNome(string nome);
    void setTelefone(string telefone);
    void setEndereco(Endereco endereco);

    //Gets
    string getNome();
    string getTelefone();
    Endereco getEndereco();

    //Other methods
    string toString();

  private:
    string nome, telefone;
    Endereco endereco;
};

Pessoa::Pessoa() : Pessoa("vazio", "vazio", Endereco()) {

}

Pessoa::Pessoa(string nome) : Pessoa(nome, "vazio", Endereco()) {

}

Pessoa::Pessoa(string nome, string telefone, Endereco endereco) {
  setNome(nome);
  setTelefone(telefone);
  setEndereco(endereco);
}

//Sets Implementation
void Pessoa::setNome(string nome) {
  this->nome = nome;
}
void Pessoa::setTelefone(string telefone) {
  this->telefone = telefone;
}
void Pessoa::setEndereco(Endereco endereco) {
  this->endereco.setRua(endereco.getRua());
  this->endereco.setBairro(endereco.getBairro());
  this->endereco.setCidade(endereco.getCidade());
  this->endereco.setEstado(endereco.getEstado());
  this->endereco.setCep(endereco.getCep());
  this->endereco.setNumero(endereco.getNumero());
}

//Gets Implementation
string Pessoa::getNome() {
  return nome;
}
string Pessoa::getTelefone() {
  return telefone;
}
Endereco Pessoa::getEndereco() {
  return endereco;
}

//Other methods implementation
string Pessoa::toString() {
  return getNome() + ", " + getTelefone() + "\n" + endereco.toString() + "\n";
}

//Pessoa END

int main() {
  int n = 0;
  string nome, telefone, rua, numero, bairro, cidade, estado, cep;

  //How many people the user wants to register
  cin >> n;

  Pessoa *pessoas[n];

  //Cleaning buffer
  cin.ignore();

  for(int i = 0; i < n; i++) {
    //Name
    getline(cin, nome);
    //Telephone
    getline(cin, telefone);
    //Street
    getline(cin, rua);
    //Number
    getline(cin, numero);
    //Neighborhood
    getline(cin, bairro);
    //City
    getline(cin, cidade);
    //State
    getline(cin, estado);
    //CEP
    getline(cin, cep);

    pessoas[i] = new Pessoa(nome, telefone, Endereco(rua, bairro, cidade, estado, cep, numero));
  }

  //Displaying info
  for(int j = 0; j < n; j++) {
    cout << pessoas[j]->toString() << endl;
  }

  return 0;
}