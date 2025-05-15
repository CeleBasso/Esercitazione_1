/*! @file CPower.h
	@brief A virtual base class for functions of a single variable
	@author Basso/Odino

	Details.
*/ 
#ifndef CPOWER_H
#define CPOWER_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Power : public Function  
{
    private:

    double k_coeff;
    double e_coeff;

    /// @name CONSTRUCTOR e DESTRUCTOR
    /// @{
    public:
    Power();
    Power(double k_coeff, double e_coeff);
    Power(const Power& p);
    ~Power();
    /// @}
    
    /// @name GETTER E SETTER
    /// @{
    double GetValue(double in) override;
    void SetPower(double k, double e);
    ///}@

    /// @name DEBUG
    /// @{
    void ErrorMessage(const char *string);
    void Dump() override;
    /// @}
};

#endif



