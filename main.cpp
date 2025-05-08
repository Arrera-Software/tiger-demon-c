#include "ctigerdemon.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Met ici l'URL d'un vrai JSON distant pour tester
    CTigerDemon demon("https://arrera-software.fr/depots.json", "six");
    cout << demon.getVersionSoft().toStdString() << endl;

    a.quit();
    return 1;
}
