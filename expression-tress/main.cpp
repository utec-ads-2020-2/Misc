#include <iostream>

using namespace std;

class Equation {
    protected:
        string equation;

    public:
        virtual void print() = 0;
        virtual double execute() = 0;
};

class Operador: public Equation {
    protected: 
        Equation* left;
        Equation* right;
};

class Plus : public Operador {
    
    public:
        void print() {
            cout << "+" << endl;
        }

        double execute() {
            auto resultLeft = left->execute();
            // Get answer of right
            // Return the result of both operations
        }
};

class Operando: public Equation {
    protected:
        string value;

    public:
        void print() {
            cout << value;
        }

        double execute() {
            // Transformar equation a double
            // Retornado transformada
        }
};

class Plus : public Equation {
    public:
        void print() {

        }
};

struct EquationFabric {
   static Equation* parse(string equation) {
        Plus* root;  // transform from postfix
        return root;
    }
};

Equation* parseFromString(string eq);

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Expression Trees" << endl;
    cout << "===========================================================" << endl << endl;

    auto test1 = Tester::initWithSequenceNumber("", 2);

    auto equation = Equation::init("3x((7+1)/4)+(17- 5)");

    Equation* eq1 = Equation::processEquation("3 x ((7 + 1) / 4) + (17 - 5)");
    auto result = eq1->execute();
    cout << result;

    Equation* eq2 = Equation::processEquation("1 + - 9 x (2 - 3 / b)");

    map<string, double> variables;
    variables["b"] = 5;

    auto result = eq2->execute(variables);
    cout << result;

    variables["b"] = 16;
    result = eq2->execute(variables);
    cout << result;

    Equation* eq = parseFromString("1 + - 9 x (2 - 3 / b)");

    auto eq1 = EquationFabric::parse("1 + - 9 x (2 - 3 / b)");
    eq1->execute();
    
    return EXIT_SUCCESS;
}