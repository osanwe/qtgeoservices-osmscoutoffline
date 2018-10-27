TARGET = qtgeoservices_osmscoutoffline
QT += location location-private network

TEMPLATE = lib
CONFIG += plugin
QMAKE_CXXFLAGS += -std=c++14

target.path += $$[QT_INSTALL_PLUGINS]/geoservices/
INSTALLS += target

HEADERS += \
    src/qgeoserviceproviderfactoryosmscoutoffline.h \
    src/qgeotiledmappingmanagerengineosmscoutoffline.h \
    src/qgeoroutingmanagerengineosmscoutoffline.h \
    src/qgeotilefetcherosmscoutoffline.h \
    src/qgeomapreplyosmscoutoffline.h

SOURCES += \
    src/qgeoserviceproviderfactoryosmscoutoffline.cpp \
    src/qgeotiledmappingmanagerengineosmscoutoffline.cpp \
    src/qgeoroutingmanagerengineosmscoutoffline.cpp \
    src/qgeotilefetcherosmscoutoffline.cpp \
    src/qgeomapreplyosmscoutoffline.cpp

DISTFILES += \
    rpm/qtgeoservices_osmscoutoffline.spec \
    rpm/qtgeoservices_osmscoutoffline.yaml \
    src/osmscoutoffline_plugin.json
