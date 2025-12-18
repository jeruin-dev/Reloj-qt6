#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>

#include <QLocale>
#include <QTranslator>

#include <QQuickView>

#include <iostream>
#include <qobject.h>

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

    engine.load(url);


    QObject* root = engine.rootObjects().first();

    QObject* miTexto = root->findChild<QObject*>("miTexto");

    if (miTexto) {
        miTexto->setProperty("text","Hola desde C++");
    }

    return app.exec();
}
