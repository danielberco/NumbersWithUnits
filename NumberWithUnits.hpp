/**
 * CPP-Task 3 Part A
 * Author: Daniel Berkovich
 * http://github.com/danielberco
 */

#include <map>
#include<iostream>
#include <string>
using namespace std;
namespace ariel {
    class NumberWithUnits{

    private:
        double amountUnit;
        std::string unit;

     friend std::ostream& operator<<(std::ostream& out, const NumberWithUnits& n);
     friend std::istream& operator>>(std::istream& ini,  NumberWithUnits& n);



    public:
        NumberWithUnits(double amountUnit, string unit){
            this->amountUnit = amountUnit;
            this->unit = unit;
        }


           
            ~NumberWithUnits(){}
            static void read_units(ifstream& units_file);

            

             /**
              * Operator +
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator+(const NumberWithUnits& n1 , const NumberWithUnits& n2);
             friend NumberWithUnits operator+(const NumberWithUnits& n1 , const double n3);

             /**
              * Operator +=
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/

             friend NumberWithUnits operator+=( NumberWithUnits& n1 ,const NumberWithUnits& n2);
            

             /**
              * Operator -
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator-( const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator-( const NumberWithUnits& n1);
              /**
              * Operator -=
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend NumberWithUnits operator-=( NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend NumberWithUnits operator-=( NumberWithUnits& n1 ,const double n3);
            

              /**
              * Operator > & Operator < 
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend bool operator>( const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend bool operator>( NumberWithUnits& n1 ,const double n3);
             friend bool operator>(const double n3, const NumberWithUnits& n1);
             friend bool operator<( const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend bool operator<( const NumberWithUnits& n1 ,const double n3);
             friend bool operator<(const double n3, const NumberWithUnits& n1);
             /**
              * Operator >= & Operator <= 
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend bool operator>=(const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend bool operator>=(const NumberWithUnits& n1 ,const double n3);
             friend bool operator>=(const double n3, const NumberWithUnits& n1);
             friend bool operator<=( const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend bool operator<=( NumberWithUnits& n1 ,const double n3);
             friend bool operator<=(const double n3, const NumberWithUnits& n1);

             /**
              * Operator == < 
              * n1 - x
              * n2 - y
              * n3 - number (double)
              **/
             friend bool operator==( const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             friend bool operator==( NumberWithUnits& n1 ,const double n3);
             friend bool operator==(const double n3, const NumberWithUnits& n1);
             friend bool operator!=( const NumberWithUnits& n1 ,const NumberWithUnits& n2);
             /**
              * Operator ++
              * 
              * 
              **/
             friend NumberWithUnits operator++(NumberWithUnits& n1);
             friend NumberWithUnits operator++(NumberWithUnits&n1,int);

             /**
              * Operator --
              * 
              * 
              **/
             friend NumberWithUnits operator--(NumberWithUnits& n1);
             friend NumberWithUnits operator--(NumberWithUnits&n1,int);
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

