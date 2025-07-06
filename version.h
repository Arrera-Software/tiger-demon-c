#ifndef VERSION_H
#define VERSION_H

#include <QString>

class version{
private :
    const QString version = "" ;
    const QString name = "" ;
public :
    QString getVersion(){
        return version;
    };

    QString getName(){
        return name;
    };
};

#endif // VERSION_H
