#include <iostream>
#include <string>

using namespace std;

//Imovel
class Imovel {
    public:
        //Construct
        Imovel();
        Imovel(int tipo, float preco, string disp);

        //Virtual methods
        virtual void exibeAtributos() = 0;
        virtual void lerAtributos() = 0;

        //Gets
        int getTipo();
        string getDisp();
        float getPreco();
        string getNome();

        //Sets
        void setTipo(int tipo);
        void setDisp(string disp);
        void setPreco(float preco);
        void setNome(string nome);

    protected:
        int tipo;
        string disp, nome;
        float preco;
};

Imovel::Imovel() : Imovel(0, 0,"Indefinido") {}
Imovel::Imovel(int tipo, float preco, string disp) {
    setTipo(tipo);
    setPreco(preco);
    setDisp(disp);
}

//Gets
int Imovel::getTipo() {
    return tipo;
}
string Imovel::getDisp() {
    return disp;
}
float Imovel::getPreco() {
    return preco;
}
string Imovel::getNome() {
    return nome;
}
//Sets
void Imovel::setTipo(int tipo) {
    this->tipo = tipo;
}
void Imovel::setDisp(string disp) {
    this->disp = disp;
}
void Imovel::setPreco(float preco) {
    this->preco = preco;
}
void Imovel::setNome(string nome) {
    this->nome = nome;
}
//Imovel END

//Casa
class Casa : public Imovel {
    public:
        //Construct
        Casa();
        /*
        ========================================
        int pavimentos -> número de pavimentos
        int quartos -> número de quartos
        float aTerr -> área do terreno
        float aCons -> área construída
        ========================================
        */
        Casa(float preco, string disp, int pavimentos, int quartos, float aTerr, float aCons);

        //Gets
        int getPavimentos();
        int getQuartos();
        float getATerr();
        float getACons();

        //Sets
        void setPavimentos(int pavimentos);
        void setQuartos(int quartos);
        void setATerr(float aTerr);
        void setACons(float aCons);

        //Virtual declaration
        void exibeAtributos();
        void lerAtributos();

    private:
        int pavimentos, quartos;
        float aTerr, aCons;
};
Casa::Casa() : Casa(0, "vazio", 0, 0, 0, 0) {}
Casa::Casa(float preco, string disp, int pavimentos, int quartos, float aTerr, float aCons) : Imovel(1, preco, disp) {
    setNome("Casa");
    setPavimentos(pavimentos);
    setQuartos(quartos);
    setATerr(aTerr);
    setACons(aCons);
}

//Gets implementation
int Casa::getPavimentos() {
    return pavimentos;
}
int Casa::getQuartos() {
    return quartos;
}
float Casa::getATerr() {
    return aTerr;
}
float Casa::getACons() {
    return aCons;
}

//Sets implementation
void Casa::setPavimentos(int pavimentos) {
    this->pavimentos = pavimentos;
}
void Casa::setQuartos(int quartos) {
    this->quartos = quartos;
}
void Casa::setATerr(float aTerr) {
    this->aTerr = aTerr;
}
void Casa::setACons(float aCons) {
    this->aCons = aCons;
}
//Virtual Implementation
void Casa::exibeAtributos() {
    cout << getNome() << " para " << disp << ". " << getPavimentos() << " pavimentos, " << getQuartos() << " quartos, " << getATerr() << "m2 de área de terreno e " << getACons() << "m2 de área construída. R$ " << getPreco() << ".\n";
}
void Casa::lerAtributos() {
    //PREÇO
    cin >> preco;
    //CLEANING BUFFER
    cin.ignore();
    //Disponibilidade
    getline(cin, disp);
    //PAVIMENTOS
    cin >> pavimentos;
    //QUARTOS
    cin >> quartos;
    //ÁREA DO TERRENO
    cin >> aTerr;
    //ÁREA CONSTRUÍDA
    cin >> aCons;
}
//Casa END

//Apartamento
class Apartamento : public Imovel {
    public:
        /*
        float area -> área do apartamento
        int quartos -> quantidade de quartos no apartamento
        int andar -> Andar do apartamento
        float condm -> Valor do condomínio
        int vagaG -> número de vagas ao apartamento correspondente
        */
        
        Apartamento();
        Apartamento(float preco, string disp, float area, int quartos, int andar, float condm, int vagaG);
        
        //Gets
        float getArea();
        int getQuartos();
        int getAndar();
        float getCondm();
        int getVagaG();
        
        //Sets
        void setArea(float area);
        void setQuartos(int quartos);
        void setAndar(int andar);
        void setCondm(float condm);
        void setVagaG(int vagaG);

        //Virtual Methods
        void exibeAtributos();
        void lerAtributos();

    private:
        float area, condm;
        int quartos, andar, vagaG;
};

Apartamento::Apartamento() : Apartamento(0, "vazio", 0, 0, 0, 0, 0) {
}
Apartamento::Apartamento(float preco, string disp, float area, int quartos, int andar, float condm, int vagaG) : Imovel(2, preco, disp) {
  //Setting nome
  setNome("Apartamento");
  //Area
  setArea(area);
  //Quartos
  setQuartos(quartos);
  //Andar
  setAndar(andar);
  //Condomínio
  setCondm(condm);
  //Números de vagas
  setVagaG(vagaG);
}

//Gets implementation
float Apartamento::getArea() {
    return area;
}
int Apartamento::getQuartos() {
    return quartos;
}
int Apartamento::getAndar() {
    return andar;
}
float Apartamento::getCondm() {
    return condm;
}
int Apartamento::getVagaG() {
    return vagaG;
}

//Sets Implementation
void Apartamento::setArea(float area) {
  this->area = area;
}
void Apartamento::setQuartos(int quartos) {
  this->quartos = quartos;
}
void Apartamento::setAndar(int andar) {
  this->andar = andar;
}
void Apartamento::setCondm(float condm) {
  this->condm = condm;
}
void Apartamento::setVagaG(int vagaG) {
  this->vagaG = vagaG;
}

//Virtual Implementation
void Apartamento::exibeAtributos() {
 cout << getNome() << " para " + getDisp() << ". " << getArea() << "m2 de área, " << getQuartos() << " quartos, " << getAndar() << " andar(es), " << getCondm() << " de condomínio, " << getVagaG() << " vaga(s) de garagem. R$ " << getPreco() << ".\n";
}
void Apartamento::lerAtributos() {
  //PREÇO
  cin >> preco;
  //CLEANING BUFFER
  cin.ignore();
  //Disponibilidade
  getline(cin, disp);
  //Área
  cin >> area;
  //Quartos
  cin >> quartos;
  //Andar
  cin >> andar;
  //Valor de condomínio
  cin >> condm;
  //Vagas de estacionamento
  cin >> vagaG;
}
//Apartamento END


//Terreno
class Terreno: public Imovel {
  public:
    Terreno();
    Terreno(float preco, string disp, float area);

    //Gets
    float getArea();
    //Sets 
    void setArea(float area);

    //Virtual declaration
    void exibeAtributos();
    void lerAtributos();
  private:
    float area;
};

Terreno::Terreno() : Terreno(0, "vazio", 0) {}
Terreno::Terreno(float preco, string disp, float area) : Imovel(3, preco, disp) {
  //Setting name
  setNome("Terreno");
  //Setting area
  setArea(area);
}

//Gets implementation
float Terreno::getArea() {
  return area;
}
//Sets implementation
void Terreno::setArea(float area) {
  this->area = area;
}
//Virtual methods implementation
void Terreno::exibeAtributos() {
  cout << getNome() << " para " << getDisp() << ". " << getArea() << "m2 de área de terreno. R$ " << getPreco() << ".\n";
}
void Terreno::lerAtributos() {
  //PREÇO
  cin >> preco;
  //CLEANING BUFFER
  cin.ignore();
  //Disponibilidade
  getline(cin, disp);
  //Área
  cin >> area;
}
//Terreno END

int main() {
    int N = 0, tipo = 0;

    //Quantidade de móveis a ser lida
    cin >> N;

    Imovel *imoveis[N];

    for(int i = 0; i < N; i++) 
    {
      cin >> tipo;

      if(tipo == 1) {
        imoveis[i] = new Casa();
      }
      else if(tipo == 2) {
        imoveis[i] = new Apartamento();
      }
      else if(tipo) {
        imoveis[i] = new Terreno();
      }
      else {
        continue;
      }  
      
      imoveis[i]->lerAtributos();
    }

    for (int i = 0; i < N; i++) 
    {
      imoveis[i]->exibeAtributos();
    }
    

    return 0;
}
