#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>

#include <QLocale>
#include <QTranslator>

#include <QQuickView>
#include <QPushButton>
#include <iostream>

#include "src/backend.hpp"

#include <qdebug.h>
#include <qlogging.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <QDebug>
#include <qtmetamacros.h>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Reloj_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Reloj/qml/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    Backend backend;
    engine.rootContext()->setContextProperty("backend", &backend);

    engine.load(url);


    return app.exec();
}
