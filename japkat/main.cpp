#include "japkat.h"

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        JapKat j;
        QStringList tempDirList = QString(argv[0]).split("/");
        tempDirList.removeLast();
        j.dataFolder = tempDirList.join("/")+"/";
        j.doConj(QString::fromUtf8(argv[1])); // "住む"
        return 0;
    }

    return -1;
}
