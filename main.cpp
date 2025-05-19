/*! @file main.cpp
	@brief file to test the program
	@author Basso/Odino

	Details.
*/ 
#include <iostream>
#include "CPolynomial.h"
#include "CPower.h"
#include "CLog.h"

int main() {
    ///@brief Definizione dei coefficienti per il polinomio p(x) = 2 + 3x - 4x^2
    double coeffs[] = {2.0, 3.0, -4.0};
    int degree = sizeof(coeffs) / sizeof(double) - 1;
    
    Polynomial poly(coeffs, degree + 1);

    /// @brief Definizione della funzione potenza f(x) = k * x^e con k = 5, e = 3
    Power powFunc(5.0, 3.0);

    /// @brief Definizione della funzione logaritmica f(x) = k * log_b(x), con k = 2, b = 10
    Log logFunc(2.0, 10.0);

    double x = 2.0;

    /// @brief Valutazione diretta delle tre funzioni
    std::cout << "p(" << x << ") = " << poly.GetValue(x) << std::endl;
    std::cout << "pow(" << x << ") = " << powFunc.GetValue(x) << std::endl;
    std::cout << "log(" << x << ") = " << logFunc.GetValue(x) << std::endl;

    /// @brief Dimostrazione di polimorfismo attraverso puntatori a Function
    Function* fptr = nullptr;

    fptr = &poly;
    std::cout << "(via Function*) p(" << x << ") = " << fptr->GetValue(x) << std::endl;

    fptr = &powFunc;
    std::cout << "(via Function*) pow(" << x << ") = " << fptr->GetValue(x) << std::endl;

    fptr = &logFunc;
    std::cout << "(via Function*) log(" << x << ") = " << fptr->GetValue(x) << std::endl;

    /// @brief Tabella di valori del polinomio per x da -2 a 2
    std::cout << "\nTabella valori del polinomio p(x):" << std::endl;
    for (double xi = -2.0; xi <= 2.0; xi += 1.0) {
        std::cout << "x = " << xi << "\tp(x) = " << poly.GetValue(xi) << std::endl;
    }

    /// @brief Tabella di valori per la funzione logaritmica per x da 0.1 a 2.0 (escludendo 0 e negativi)
    std::cout << "\nTabella valori della funzione log(x):" << std::endl;
    for (double xi = 0.1; xi <= 2.0; xi += 0.3) {
        std::cout << "x = " << xi << "\tlog(x) = " << logFunc.GetValue(xi) << std::endl;
    }

    return 0;
}