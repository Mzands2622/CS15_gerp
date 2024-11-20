
#include <iostream>
#include <string>
#include "processing.h"

int main(int argc, char *argv[]) {
    std::string prac_directory = "/h/mzandi03/cs15/proj2";
    traverseDirectory(prac_directory);

    std::string prac_string = "comp";
    std::string prac_string_two = "comp.";
    std::string prac_string_three = "Comp";
    std::string prac_string_four = "-comp";
    std::string prac_string_five = "&&comp";
    std::string prac_string_six = "comp?!";
    std::string prac_string_seven = "@#comp?@!";
    std::string prac_string_eight = "@##!!#!@!#COMP-15!!!!!!!";


    std::cout << stripNonAlphaNum(prac_string) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_two) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_three) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_four) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_five) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_six) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_seven) << std::endl;
    std::cout << stripNonAlphaNum(prac_string_eight) << std::endl;


    return 0;
}