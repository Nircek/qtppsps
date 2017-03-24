#include "qtppsps.h"
using namespace GitHub::Nircek;
int main(int argc, char *argv[])
{
    QApplication qapp(argc,argv);
    qtppsps ps("localhost", "super tajne hasło", &qapp);
    return 0;
}

