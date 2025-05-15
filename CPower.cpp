/*! @file CPower.cpp
	@brief A virtual base class for functions of a single variable
	@author Basso/Odino

	Details.
*/ 


#include "CPower.h"

/// @brief  default Constructor
Power::Power() : Function() 
    {
        k_coeff=0;
        e_coeff=0;
    }
/// @brief constructor
Power::Power(double k, double e) : Function()
{
    k_coeff=0;
    e_coeff=0;
    SetPower(k,e);
}

/// @brief Destructor
Power::~Power()
{
    
}

/// @brief Set the power function
void Power::SetPower(double k, double e) 
{
    if ( isnan(k) || isnan(e)) 
        {
            ErrorMessage("I parametri non sono validi");  
        } 
    else 
        {
            k_coeff = k;
            e_coeff = e;
        }
}
/// @brief Get the power function
/// @param in the input 
double Power::GetPower(double in)
{
    return pow(in, e_coeff)*k_coeff;
}
