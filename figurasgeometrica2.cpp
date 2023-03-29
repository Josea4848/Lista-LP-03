#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

//Classe Abstrata
class FiguraGeometrica {
    public:
        FiguraGeometrica();
        FiguraGeometrica(int tipo);
        virtual float calcularArea() = 0;
        virtual void lerAtributosArea() = 0;
        string getNome();
    private:

    protected:
        string nome;
        int tipo;
};

FiguraGeometrica::FiguraGeometrica() : FiguraGeometrica(0) {

}

FiguraGeometrica::FiguraGeometrica(int tipo) {
    this->tipo = tipo;
}

string FiguraGeometrica::getNome() {
    return nome;
}

//Classe Abstrata END

//Quadrado
class Quadrado : public FiguraGeometrica {
    public:
        Quadrado();

        float calcularArea();
        void  lerAtributosArea();

    private:
        float lado;

};

Quadrado::Quadrado() : FiguraGeometrica(1) {
    nome  = "Quadrado";
}

float Quadrado::calcularArea() {
    return lado*lado;
}

void Quadrado::lerAtributosArea() {
    cin >> lado;
}



//Quadrado END

//Retângulo

class Retangulo : public FiguraGeometrica {
    public:
        Retangulo();

        float calcularArea();
        void  lerAtributosArea();

    private:
        float base, altura;
};

Retangulo::Retangulo() : FiguraGeometrica(2) {
    nome = "Retângulo";
}

float Retangulo::calcularArea() {
    return base * altura;
}

void Retangulo::lerAtributosArea() {
    cin >> base;
    cin >> altura;
}
//Retângulo END


//Triângulo

class Triangulo : public FiguraGeometrica {
    public:
        Triangulo();

        float calcularArea();
        void lerAtributosArea();
    private:
        float base, altura;
};

Triangulo::Triangulo() : FiguraGeometrica(3) {
    nome = "Triângulo";
}

float Triangulo::calcularArea() {
    return base*altura/2;
}

void Triangulo::lerAtributosArea() {
    //Base
    cin >> base;
    //Altura
    cin >> altura;
}

//Triângulo END

//Círculo

class Circulo : public FiguraGeometrica {
    public:
        Circulo();

        float calcularArea();
        void lerAtributosArea();

    private:
        float raio;
};

Circulo::Circulo() : FiguraGeometrica(4) {
    nome = "Círculo";
}

float Circulo::calcularArea() {
    return PI*raio*raio;
}

void Circulo::lerAtributosArea() {
    cin >> raio;
}

//Círculo END

int main() {
    FiguraGeometrica *f;
    int tipo;

    while(true) {
        //Lendo Tipo
        cin >> tipo;

        //Condição de parada do While
        if(!tipo) {
            break;
        }

        switch (tipo) {
            case 1:
                f = new Quadrado();
                break;
            case 2:
                f = new Retangulo();
                break;
            case 3:
                f = new Triangulo();
                break;
            case 4:
                f = new Circulo();
                break;
            default:
                continue;
        }

        //Lendo dados para o objeto
        f->lerAtributosArea();

        //Exibindo Informações
        cout << f->getNome() << " polimórfico de área " << f->calcularArea() << endl;

    }


    return 0;
}
