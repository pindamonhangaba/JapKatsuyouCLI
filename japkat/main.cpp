#include <QCoreApplication>
#include <QDebug>
#include "japkat.h"

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        JapKat j;
        j.doConj(QString::fromUtf8(argv[1])); // "住む"
        return 0;
    }

    return -1;
}
