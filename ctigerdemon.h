#ifndef CTIGERDEMON_H
#define CTIGERDEMON_H

#include <QCoreApplication>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

class CTigerDemon : public QObject
{
    Q_OBJECT
public:
    explicit CTigerDemon(const QString& url, const QString& nameSoft, QObject* parent = nullptr);

private:
    QNetworkAccessManager* manager;
};

#endif // CTIGERDEMON_H
