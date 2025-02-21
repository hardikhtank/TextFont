#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "customtextnode.h"
#include "customtextpainter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Register the CustomTextPainter type with QML
    qmlRegisterType<CustomTextPainter>("CustomControls", 1, 0, "CustomTextPainter");
    qmlRegisterType<CustomTextNode>("CustomComponents", 1, 0, "CustomTextNode");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) {
        qDebug() << "Failed to load QML";
        return -1;
    }

    return app.exec();
}
