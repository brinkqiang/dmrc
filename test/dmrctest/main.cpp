


#include "dmrc.hpp"
#include <iostream>
#include "dmstrtk.hpp"

int main(int argc, char *argv[])
{
    CDMRC oRC;
    oRC.SetKey("31323334");

    char buf[] = {0x0A, 0x01, 0x31};

    std::string strOut = oRC.Encrypt(buf, 3);

    std::cout << strtk::convert_bin_to_hex(strOut) << std::endl;

    oRC.Decrypt(strOut);

    std::cout << strOut << std::endl;

    return 0;
}
