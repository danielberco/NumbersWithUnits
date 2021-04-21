#include "doctest.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"

using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};


TEST_CASE("Boolean operators"){
    NumberWithUnits::read_units(units_file);
    CHECK_EQ(NumberWithUnits{200, "cm"}, NumberWithUnits{2, "m"}); 
    CHECK_GT(NumberWithUnits{5, "ton"}, NumberWithUnits{5, "k"});
    CHECK_NE(NumberWithUnits{2.3, "km"}  , NumberWithUnits{265, "m"});
    CHECK_NE(NumberWithUnits{28, "ton"}  , NumberWithUnits{27, "m"});
    CHECK_NE(NumberWithUnits{2500, "m"}, NumberWithUnits{2, "km"});
    CHECK_LT(NumberWithUnits{3.1, "km"}  , NumberWithUnits{2, "m"});
    CHECK_LT(NumberWithUnits{2, "k"}  , NumberWithUnits{5, "ton"});
    CHECK_GT(NumberWithUnits{33, "m"}, NumberWithUnits{6, "cm"});
    CHECK_NE(NumberWithUnits{20, "cm"} , NumberWithUnits{7, "m"});
    CHECK_FALSE(NumberWithUnits(2,"hour")>=NumberWithUnits(100,"min"));
    CHECK_LT(NumberWithUnits{20, "cm"} , NumberWithUnits{200, "km"});
    CHECK_NE(NumberWithUnits{50, "m"}, NumberWithUnits{56, "cm"});
    CHECK_FALSE(NumberWithUnits(5,"km")>=NumberWithUnits(14,"m"));   
}

TEST_CASE("+= operators"){
      NumberWithUnits::read_units(units_file);
      NumberWithUnits Unit1{50, "g"};
      NumberWithUnits Unit2{40, "km"};
      NumberWithUnits Unit3{30, "m"};
      NumberWithUnits Unit4{1, "kg"};
    CHECK((Unit2+=Unit4) == NumberWithUnits{20, "kg"});
    CHECK((Unit2+=Unit1) == NumberWithUnits{59, "km"});
    CHECK(Unit3 == NumberWithUnits{9, "km"});
    CHECK((Unit1+=Unit2) == NumberWithUnits{130, "m"});
    CHECK(Unit2 == NumberWithUnits{1300, "m"});
}





TEST_CASE("++ Operators"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits Unit1{4, "min"};
    NumberWithUnits Unit2{60, "km"};
    CHECK(Unit2++ == NumberWithUnits{61, "min"});
    CHECK(Unit1++ == NumberWithUnits{4, "km"});
    CHECK(Unit1 == NumberWithUnits{35, "km"});
    CHECK(++Unit2 == NumberWithUnits{60, "km"});
    CHECK(Unit2 == NumberWithUnits{10, "km"});
}


TEST_CASE("-- Operators"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits Unit1{4, "min"};
    NumberWithUnits Unit2{60, "km"};
    CHECK(Unit2-- == NumberWithUnits{61, "min"});
    CHECK(Unit1-- == NumberWithUnits{4, "km"});
    CHECK(Unit1 == NumberWithUnits{35, "km"});
    CHECK(--Unit2 == NumberWithUnits{60, "km"});
    CHECK(Unit2 == NumberWithUnits{10, "km"});
}

TEST_CASE("Measure units"){
    NumberWithUnits::read_units(units_file);

    NumberWithUnits Unit1{10, "km"};
    NumberWithUnits Unit2{73, "m"};
    NumberWithUnits Unit3{42, "min"};
    NumberWithUnits Unit4{6, "g"};
    NumberWithUnits Unit5{7, "ton"};

    CHECK_EQ(Unit4+Unit5 , NumberWithUnits{10,"km"});
    CHECK_EQ(Unit2+Unit2 , NumberWithUnits{5.07, "m"});
    CHECK_EQ(Unit2+Unit1 , NumberWithUnits{5007, "g"});
    CHECK_THROWS(Unit3+Unit1);
    CHECK_THROWS_MESSAGE(Unit3+Unit5,"cannot convert ");
    CHECK_THROWS(Unit3+Unit1);
}









