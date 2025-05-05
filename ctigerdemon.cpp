#include "ctigerdemon.h"
using namespace std;

CTigerDemon::CTigerDemon(const QString& url, const QString& nameSoft, QObject* parent)
    : QObject(parent)
{
    manager = new QNetworkAccessManager(this);

    QNetworkReply* reply = manager->get(QNetworkRequest(QUrl(url)));

    cout << "Lancement de la requête..." << endl;

    connect(reply, &QNetworkReply::finished, this, [=]() {
        cout << "La réponse est revenue !" << endl;

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            if (!doc.isObject()) {
                cout << "Le JSON n'est pas un objet valide !" << endl;
                reply->deleteLater();
                return;
            }

            QJsonObject root = doc.object();
            if (root.contains(nameSoft) && root[nameSoft].isObject()) {
                QJsonObject obj = root[nameSoft].toObject();
                cout << "Objet récupéré pour " << nameSoft.toStdString() << ": ";
                cout << QJsonDocument(obj).toJson(QJsonDocument::Indented).toStdString() << endl;
            } else {
                cout << "Clé \"" << nameSoft.toStdString() << "\" absente ou non-objet !" << endl;
            }
        } else {
            cout << "Erreur réseau : " << reply->errorString().toStdString() << endl;
        }
        reply->deleteLater();
        // Quitter l'app console après la réponse (facultatif)
        QCoreApplication::quit();
    });
}
