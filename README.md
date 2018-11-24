# OSM Scout Offline & Sight Safary Qt Map Plugin

Based on [OSM Qt Map Plugin](https://code.woboq.org/qt5/qtlocation/src/plugins/geoservices/osm/)

## Usage

1. Install the plugin
2. Install OSM Scout Oflline service (see below)
3. Define `Map`, `MapPolyline`, `Plugin`, `RouteQuery`, and `RouteModel` objects like this:
```qml
Page {

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin

        MapPolyline {
            id: mapPolylineRoute
            line.color: 'green'
            line.width: 3
        }

        Component.onCompleted: {
            map.zoomLevel = 14
            map.center = QtPositioning.coordinate(55.7542, 37.6221)

            // Red Square, Moscow
            mapRouteQuery.addWaypoint(QtPositioning.coordinate(55.7708, 37.5944))
            mapRouteQuery.addWaypoint(QtPositioning.coordinate(55.7513, 37.6286))
            mapRouteModel.update()
        }
    }

    Plugin {
        id: mapPlugin
        name: "osmscoutoffline"
    }

    RouteQuery {
        id: mapRouteQuery
    }

    RouteModel {
        id: mapRouteModel
        plugin: mapPlugin
        query: mapRouteQuery
        autoUpdate: false

        onRoutesChanged: {
            console.log("onRoutesChanged")
            mapPolylineRoute.path = mapRouteModel.get(0).path
        }
    }
}
```

## OSM Scout Offline service

The following steps is actual for Sailfish OS.
In your tasks you can use a pure [`libosmscout`](http://libosmscout.sourceforge.net/) library.

1. Install [`OSM Scout Server`](https://openrepos.net/content/rinigus/osm-scout-server)
2. Install [`OSM Scout Server Module: Fonts`](https://openrepos.net/content/rinigus/osm-scout-server-module-fonts)
3. Open `OSM Scout Server` application on your phone
4. Choose a profile recommended for **vector and raster** tiles
5. Download necessary maps

## Demo

You can find a working demo which uses this plugin [here](https://github.com/osanwe/harbour-sight-safary).
