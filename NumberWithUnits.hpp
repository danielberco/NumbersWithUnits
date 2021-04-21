/**
 * CPP-Task 3 Part A
 * Author: Daniel Berkovich
 * http://github.com/danielberco
 */
#include "NumberWithUnits.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include <map>
#include <fstream>


using namespace std;


namespace ariel {
    static map <string,map<string,double>> tab;



    double convertUnit (const string u1, const string u2, const double uNum) {
        if(u1 == u2) {
            return uNum;
        }
        try {
            return tab.at(u1).at(u2) * uNum;
        }
        catch (const std::exception& exception) {
            throw invalid_argument{"Error:  Cannot convert from "+ u1 +" to "+ u2};
        }
    }

    double checkUnit (const string u1, const string u2, double n) {
        if (u1 == u2) {
            return n;
        }

        try {
            return n * tab[u1][u2];
        }
        catch(const exception& exe) {
            throw invalid_argument("Cannot convet units");

        }
    }


    void addUnits(const string u1, const string u2) {
        for (const auto &at : tab[u1]) {
            if (at.first != u2) {
                double val = at.second*tab[u2][u1];
                tab[at.first][u2] = 1/val;
                tab[u2][at.first] = val;
            }
        }
    }

    void printTable(){
        for(const auto &i : tab) {
            for(const auto&j : tab[i.first]) {
                        std::cout <<"tab["<< i.first << "][" << j.first << "] => " << j.second << endl;
             }
        }
    }

     void NumberWithUnits::read_units(ifstream& units_file) {
        string u1,u2,op;
        double x,y;
        while(units_file >> x >> u1 >> op >> y >> u2){
            tab[u1][u2] = y;
            tab[u2][u1] = 1/y;
            addUnits(u1,u2);
            addUnits(u2,u1);
        }
        printTable();
    }

    /**
     * Overloading operator + 
     * 
     * 
     * */

    NumberWithUnits operator+(const NumberWithUnits& n1,const NumberWithUnits& n2) {
       double val = convertUnit(n2.unit,n1.unit,n2.amountUnit);
       return NumberWithUnits(n1.amountUnit+val,n1.unit); 
    }

    NumberWithUnits operator+(const NumberWithUnits& n1,const double n3) {
       return NumberWithUnits(n1.amountUnit+n3,n1.unit); 
    }

    /**
     * Overloading operator -
     * 
     * 
     * */

    NumberWithUnits operator-(const NumberWithUnits& n1,const NumberWithUnits& n2) {
        double x = convertUnit(n2.unit,n1.unit,n2.amountUnit);
        return NumberWithUnits(n1.amountUnit-x,n1.unit);
    }

    NumberWithUnits operator-(const NumberWithUnits& n1) {
        return NumberWithUnits(-n1.amountUnit,n1.unit);
    }

    NumberWithUnits operator+=(NumberWithUnits& n1,const NumberWithUnits& n2) {
        double x = convertUnit(n2.unit,n1.unit,n2.amountUnit);
        n1.amountUnit += x;
        return n1;
    }

    NumberWithUnits operator-=(NumberWithUnits& n1,const NumberWithUnits& n2) {
        double x = convertUnit(n2.unit,n1.unit,n2.amountUnit);
        n1.amountUnit -= x;
        return NumberWithUnits(n1.amountUnit, n1.unit);   
    }

    bool operator>(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1.amountUnit>checkUnit(n2.unit,n1.unit,n2.amountUnit);
    }

    bool operator<(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1.amountUnit<checkUnit(n2.unit,n1.unit,n2.amountUnit);
    }

    bool operator>=(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1.amountUnit>=checkUnit(n2.unit,n1.unit,n2.amountUnit);
    }

    bool operator<=(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1.amountUnit<=checkUnit(n2.unit,n1.unit,n2.amountUnit);
    }

    bool operator==(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1.amountUnit>=checkUnit(n2.unit,n1.unit,n2.amountUnit);
  }

  bool operator!=(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1.amountUnit != checkUnit(n2.unit,n1.unit,n2.amountUnit);
  }

  ostream& operator<<(ostream& out, const NumberWithUnits& unit){
      out << unit.amountUnit << "["<< unit.unit << "]";
      return out;
  }

  istream& operator>>(istream& ini, NumberWithUnits& s){
     string str;
      ini >> s.amountUnit >> str >> s.unit;
      return ini;
  }


}

