TARGET = qtgeoservices_osmscoutoffline
QT += location location-private network

TEMPLATE = lib
CONFIG += plugin
QMAKE_CXXFLAGS += -std=c++11

target.path += $$[QT_INSTALL_PLUGINS]/geoservices/
INSTALLS += target

HEADERS += \
    src/qgeoserviceproviderfactoryosmscoutoffline.h \
    src/qgeoroutingmanagerengineosmscoutoffline.h \
    src/qgeotiledmappingmanagerengineosmscoutoffline.h \
    src/qgeotilefetcherosmscoutoffline.h \
    src/qgeomapreplyosmscoutoffline.h \
    src/qgeoroutereplyosmscoutoffline.h

SOURCES += \
    src/qgeoserviceproviderfactoryosmscoutoffline.cpp \
    src/qgeoroutingmanagerengineosmscoutoffline.cpp \
    src/qgeotiledmappingmanagerengineosmscoutoffline.cpp \
    src/qgeotilefetcherosmscoutoffline.cpp \
    src/qgeomapreplyosmscoutoffline.cpp \
    src/qgeoroutereplyosmscoutoffline.cpp

DISTFILES += \
    rpm/qtgeoservices_osmscoutoffline.spec \
    rpm/qtgeoservices_osmscoutoffline.yaml \
    osmscoutoffline_plugin.json \
    README.md \
    LICENSE
