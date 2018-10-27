TARGET = qtgeoservices_osmscoutoffline
QT += location location-private network

TEMPLATE = lib
CONFIG += plugin
QMAKE_CXXFLAGS += -std=c++11

target.path += $$[QT_INSTALL_PLUGINS]/geoservices/
INSTALLS += target

#    src/qgeoroutingmanagerengineosmscoutoffline.h \
HEADERS += \
    src/qgeoserviceproviderfactoryosmscoutoffline.h \
    src/qgeotiledmappingmanagerengineosmscoutoffline.h \
    src/qgeotilefetcherosmscoutoffline.h \
    src/qgeomapreplyosmscoutoffline.h

#    src/qgeoroutingmanagerengineosmscoutoffline.cpp \
SOURCES += \
    src/qgeoserviceproviderfactoryosmscoutoffline.cpp \
    src/qgeotiledmappingmanagerengineosmscoutoffline.cpp \
    src/qgeotilefetcherosmscoutoffline.cpp \
    src/qgeomapreplyosmscoutoffline.cpp

DISTFILES += \
    rpm/qtgeoservices_osmscoutoffline.spec \
    rpm/qtgeoservices_osmscoutoffline.yaml \
    src/osmscoutoffline_plugin.json
