#include "backend.hpp"

Backend::Backend(QObject *parent)
    : QObject(parent)
{
}

void Backend::hola()
{
    qDebug() << "Hola Mundo desde C++";
    emit mensajeCambiado("Hola desde C++");
}
