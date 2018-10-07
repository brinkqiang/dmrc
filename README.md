# dmrc

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[dmrc GitHub](https://github.com/brinkqiang/dmrc)

## Build status
| [Linux][lin-link] | [MacOSX][osx-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![osx-badge]       | ![win-badge]        |

[lin-badge]: https://travis-ci.org/brinkqiang/dmrc.svg?branch=master "Travis build status"
[lin-link]:  https://travis-ci.org/brinkqiang/dmrc "Travis build status"
[osx-badge]: https://travis-ci.org/brinkqiang/dmrc.svg?branch=master "Travis build status"
[osx-link]:  https://travis-ci.org/brinkqiang/dmrc "Travis build status"
[win-badge]: https://ci.appveyor.com/api/projects/status/github/brinkqiang/dmrc?branch=master&svg=true "AppVeyor build status"
[win-link]:  https://ci.appveyor.com/project/brinkqiang/dmrc "AppVeyor build status"

## Intro
rc4 for C/C++/C#
```cpp
#include <stdio.h>

#include "dmrc.hpp"

int main(int argc, char *argv[])
{
    CDMRC oRC;
    oRC.SetKey("dmrc");

    std::string strData = "hello world";

    std::string strOut = oRC.Encrypt((char*)strData.c_str(), strData.size());

    oRC.Decrypt(strOut);

    return 0;
}

```
## Contacts
[![Join the chat](https://badges.gitter.im/brinkqiang/dmrc/Lobby.svg)](https://gitter.im/brinkqiang/dmrc)

## Thanks
polarssl