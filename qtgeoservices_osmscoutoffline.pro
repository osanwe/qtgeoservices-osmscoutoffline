TARGET = qtgeoservices_osmscoutoffline
QT += location location-private network

TEMPLATE = lib
CONFIG += plugin

target.path += $$[QT_INSTALL_PLUGINS]/geoservices/
INSTALLS += target

HEADERS += \
    src/qgeoserviceproviderfactoryosmscoutoffline.h \
    src/qgeotiledmappingmanagerengineosmscoutoffline.h

SOURCES += \
    src/qgeoserviceproviderfactoryosmscoutoffline.cpp \
    src/qgeotiledmappingmanagerengineosmscoutoffline.cpp

DISTFILES += \
    rpm/qtgeoservices_osmscoutoffline.spec \
    rpm/qtgeoservices_osmscoutoffline.yaml \
    src/osmscoutoffline_plugin.json