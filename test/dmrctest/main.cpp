


#include "dmrc.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    CDMRC oRC;
    oRC.SetKey("dmrc");

    std::string strData = "hello world";

    std::string strOut = oRC.Encrypt((char*)strData.c_str(), strData.size());

    oRC.Decrypt(strOut);

    std::cout << strOut << std::endl;

    return 0;
}
