TEMPLATE = app

QT += quick qml widgets

SOURCES += main.cpp \
    customtextnode.cpp \
    customtextpainter.cpp

HEADERS += \
    customtextnode.h \
    customtextpainter.h

RESOURCES += \
    qml.qrc

DISTFILES += \
    main.qml \
    CustomTextNode.qml \
    CustomTextPainter.qml

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

# Add C++11 support
CONFIG += c++11

# Add private headers
QT += quick-private

# For Qt 5.4.2 specifically
INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtQuick/$$[QT_VERSION]
INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtQuick/$$[QT_VERSION]/QtQuick
