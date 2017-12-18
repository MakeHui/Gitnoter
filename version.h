#ifndef VERSION_H
#define VERSION_H

#define VER_FILEVERSION             1,0,0,0     //文件版本
#define VER_FILEVERSION_STR         "1.0.0.0"

#define VER_PRODUCTVERSION          1,0,0,0
#define VER_PRODUCTVERSION_STR      "1.0.0.0"   // 产品版本
#define VER_PRODUCTBUILD_STR        1           // build

#define VER_COMPANYNAME_STR         "Gitnoter"
#define VER_INTERNALNAME_STR        "Gitnoter.exe"
#define VER_LEGALCOPYRIGHT_STR      "Copyright © 2017 MakeHui. "  // 版权
#define VER_LEGALTRADEMARKS1_STR    "All rights reserved. "
#define VER_LEGALTRADEMARKS2_STR    VER_LEGALTRADEMARKS1_STR
#define VER_PRODUCTNAME_STR         "Gitnoter"        // 产品名称
#define VER_ORIGINALFILENAME_STR    "Gitnoter.exe"    // 原始文件名
#define VER_FILEDESCRIPTION_STR     QString("%1 for %3 Version %2 (build %4)").arg(VER_PRODUCTNAME_STR, VER_PRODUCTVERSION_STR, "Windows").arg(VER_PRODUCTBUILD_STR)    // 文件说明

#define VER_ORGANIZATIONDOMAIN_STR  "http://gitnoter.com"

#endif // VERSION_H
