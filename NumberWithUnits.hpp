/**
 * CPP-Task 3 Part A
 * Author: Daniel Berkovich
 * http://github.com/danielberco
 */

#include <map>
#include<iostream>
#include <string>
#include <stdexcept>

using namespace std;
namespace ariel {
    class NumberWithUnits {

        private:
        string unit;
        double amountUnit;

        public:
           NumberWithUnits( double amountUnit,string unit) {
               this->amountUnit=amountUnit;
               this->unit = unit;
           }
            ~NumberWithUnits(){}
            static void read_units(ifstream& units_file);

            //ostream & istream
             friend ostream& operator<<(ostream& ostream , const NumberWithUnits& n1);
             friend istream& operator>>(istream& istream , NumberWithUnits& n1);

             /**
              * Operator +
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator+(const NumberWithUnits& n1 , const NumberWithUnits& n2);
             friend NumberWithUnits operator+(const NumberWithUnits& n1 , const double n3);
             friend NumberWithUnits operator+(const double n3, const NumberWithUnits& n1);
             friend NumberWithUnits operator+(const NumberWithUnits&n1);

             /**
              * Operator +=
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator+=( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator+=( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator+=(const double n3, const NumberWithUnits& n1);

             /**
              * Operator -
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator-( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator-( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator-(const double n3, const NumberWithUnits& n1);
             friend NumberWithUnits operator-(const NumberWithUnits&n1);

              /**
              * Operator -=
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator-=( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator-=( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator-=(const double n3, const NumberWithUnits& n1);

              /**
              * Operator > & Operator < 
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator>( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator>( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator>(const double n3, const NumberWithUnits& n1);
             friend NumberWithUnits operator<( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator<( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator<(const double n3, const NumberWithUnits& n1);

             /**
              * Operator >= & Operator <= 
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator>=( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator>=( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator>=(const double n3, const NumberWithUnits& n1);
             friend NumberWithUnits operator<=( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator<=( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator<=(const double n3, const NumberWithUnits& n1);

             /**
              * Operator == < 
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator==( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator==( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator==(const double n3, const NumberWithUnits& n1);

             /**
              * Operator *
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator*( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator*( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator*(const double n3, const NumberWithUnits& n1);

             /**
              * Operator /
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator/( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator/( NumberWithUnits& n1 ,const double n3);
             friend NumberWithUnits operator/(const double n3, const NumberWithUnits& n1);
    };
}