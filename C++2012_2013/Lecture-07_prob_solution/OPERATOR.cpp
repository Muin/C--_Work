/*      Lecture -07, Number-02
             NAMESPACE
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 07.12.2012

            PROPOSED TASK
Create the namespace Math.

Design and implement a class Rational in Math.

This class shall offer:
    standard-constructor.
    set- and get-methods for enumerator and denominator
    (division by zero?).

Implement in Math the following operators:
    + and * for addition and multiplication of two Rational
    objects.
    operator<< for displaying the value held by a Rational
    instance.
    Introduce an operator for assignment.
    Introduce also operators for += and *=.
Test the class.

*/

#include <iostream>
#include <rational.h>
#include <limits>

using namespace std;
float fInput();


int main()
    {
        using namespace Math;
        Rational Ratio1( 4 , 5 );
        Rational Ratio2( 6 , 7 );
        Rational Output;
        Output= Ratio1 + Ratio2;
        std::cout << "r1 = " << Output << std::endl;

        Output= Ratio1 * Ratio2;
        std::cout << "r2 = " << Output << std::endl;
        return 0;
    }


float iInput()
    {
        float fNumber;
        while(!(cin >> fNumber))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"\nplease give correct value: ";
            }
        cout<<"\nentered: "<<fNumber<<"\n";
        return (fNumber);
    }




//########## rational.h ##############

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace Math
    {
        class Rational
            {

                private:
                    float PlusEnumerator , MultEnumerator ; //Enumerator;
                    float PlusDenumerator , MultDenumerator ; //Denumerator;

                public:
                        Rational();
                        Rational(float g_enumerator1 , float g_denumerator);

                        float GetPlusEnumerator() const;
                        float GetPlusDenumerator() const;
                        float SetPlusEnumerator() const;
                        float SetPlusDenumerator() const;
                        float GetMultEnumerator() const;
                        float GetMultDenumerator() const;
                        Rational& operator+ (const Rational& rationalObj);
                        Rational& operator* (const Rational& rationalObj);
                        //Rational& operator= (const Rational& rationalObj);
            };
        std::ostream& operator<< (std::ostream& out, const Rational& rationalObj);
    }

#endif // RATIONAL_H




//@@@@@@@@@@@@@ rational.cpp @@@@@@@@@@@@@@

#include "rational.h"


Math::Rational::Rational()
    {

        PlusEnumerator = 0 ;
        PlusDenumerator = 0 ;
        MultEnumerator = 0 ;
        MultDenumerator = 0;

    }


Math::Rational::Rational(float g_enumerator , float g_denumerator)
    {

        PlusEnumerator = g_enumerator ;
        PlusDenumerator = g_denumerator;
        MultEnumerator = g_enumerator;
        MultDenumerator = g_denumerator;
    }


// "+" Operator

Math::Rational& Math::Rational::operator+ (const Rational& rationalObj)
    {

        PlusEnumerator = PlusEnumerator * rationalObj.PlusDenumerator + PlusDenumerator * rationalObj.PlusEnumerator;
        PlusDenumerator = PlusDenumerator * rationalObj.PlusDenumerator;
        return *this;
    }


// "*" Operator

Math::Rational& Math::Rational::operator* (const Rational& rationalObj1)
    {
        PlusEnumerator = PlusDenumerator = 0;
        MultEnumerator = MultEnumerator * rationalObj1.MultEnumerator;
        MultDenumerator = MultDenumerator * rationalObj1.MultDenumerator;
        return *this;
    }


float Math::Rational::GetPlusEnumerator() const
    {
        return PlusEnumerator;
    }


float Math::Rational::GetPlusDenumerator() const
    {
        return PlusDenumerator;
    }


float Math::Rational::GetMultEnumerator() const
    {
        return MultEnumerator;
    }


float Math::Rational::GetMultDenumerator() const
    {
        return MultDenumerator;
    }


std::ostream& Math::operator<< ( std::ostream& out, const Math::Rational& rationalObj )
    {

        if(rationalObj.GetPlusEnumerator()!=0 && rationalObj.GetPlusDenumerator()!=0)
            {
                out << rationalObj.GetPlusEnumerator() << "/" << rationalObj.GetPlusDenumerator();
            }

        else if(rationalObj.GetMultEnumerator()!= 0 && rationalObj.GetMultDenumerator()!=0)
            {
                out << rationalObj.GetMultEnumerator() << "/" << rationalObj.GetMultDenumerator();
            }
        return out;
    }
