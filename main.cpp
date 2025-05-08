#include "ctigerdemon.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Met ici l'URL d'un vrai JSON distant pour tester
    CTigerDemon demon("https://arrera-software.fr/depots.json", "six");
    cout << demon.getVersionSoft().toStdString() << endl;

    if (demon.checkUpdate()){
        cout << "Mise a jour dispo" << endl;
    }else{
        cout << "Pas de mise a jour" << endl;
    }

    a.quit();
    return 1;
}
