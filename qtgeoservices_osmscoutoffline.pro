TARGET = qtgeoservices_osmscoutoffline
QT += location location-private network

TEMPLATE = lib
CONFIG += plugin

target.path += $$[QT_INSTALL_PLUGINS]/geoservices/
INSTALLS += target

HEADERS += \

SOURCES += \
    src/qtgeoservices_osmscoutoffline.cpp

DISTFILES += \
    rpm/qtgeoservices_osmscoutoffline.spec \
    rpm/qtgeoservices_osmscoutoffline.yaml
