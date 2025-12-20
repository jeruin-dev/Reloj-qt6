#pragma once

#include <QObject>
#include <QDebug>

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

    Q_INVOKABLE void hola();

signals:
    void mensajeCambiado(const QString &mensaje);
};
