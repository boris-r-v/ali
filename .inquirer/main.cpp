#include <iostream>
#include <string>

int main ()
{
    std::string str;
    char sym;
    while ((sym  = std::cin.get ()) != '\n')  str += (sym != '/') ? std::string (1, sym) : std::string ("\\/");
    std::cout << str << std::endl;

    return 0;
}
