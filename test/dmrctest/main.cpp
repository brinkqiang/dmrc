


#include "dmrc.hpp"
#include <iostream>
#include "dmstrtk.hpp"

int main(int argc, char *argv[])
{
    CDMRC oRC;
    oRC.SetKey("31323334");

    char buf[] = {0x08, 0x01};

    std::string strOut;
    strOut.assign(oRC.Encrypt(buf, sizeof(buf)), sizeof(buf));

    std::cout << strtk::convert_bin_to_hex(strOut) << std::endl;

    oRC.Decrypt(strOut);

    std::cout << strtk::convert_bin_to_hex(strOut) << std::endl;

    return 0;
}
