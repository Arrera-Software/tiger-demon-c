#include "ctigerdemon.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QUrl>

using namespace std;

CTigerDemon::CTigerDemon(const QString& url, const QString& nameSoft, QObject* parent)
    : QObject(parent)
{
    QNetworkAccessManager mgr(this);
    QNetworkRequest req(url);             // <-- c'est bien le constructeur !
    QNetworkReply* reply = mgr.get(req);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isObject()) {
            QJsonObject root = doc.object();
            if (root.contains(nameSoft) && root[nameSoft].isObject()) {
                contenuJSON = root[nameSoft].toObject();
            } else {
                qDebug() << "[CTigerDemon] Le nom" << nameSoft << "n'est pas trouvé dans le JSON.";
            }
        } else {
            qDebug() << "[CTigerDemon] Le document JSON n'est pas un objet.";
        }
    } else {
        qWarning() << "[CTigerDemon] Erreur réseau : " << reply->errorString();
    }
    reply->deleteLater();
}

bool CTigerDemon::checkUpdate(){
    cout << contenuJSON["version"].toString().toStdString() << endl;
    return true;
}
