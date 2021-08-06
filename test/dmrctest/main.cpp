


#include "dmrc.hpp"
#include <iostream>
#include "dmstrtk.hpp"

int main(int argc, char *argv[])
{
    CDMRC oRC;
    oRC.SetKey("1234");

    std::string strData;
    strData.assign("data1234");

    std::string strOut = oRC.Encrypt((char*)strData.c_str(), strData.size());

    std::cout << strtk::convert_bin_to_hex(strOut) << std::endl;

    oRC.Decrypt(strOut);

    std::cout << strOut << std::endl;

    return 0;
}
