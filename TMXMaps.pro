TEMPLATE = app
CONFIG += console
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -L"lib" -ltinyxml-s

DEFINES += TIXML_USE_STL

SOURCES += main.cpp \
    Map.cpp \
    Properties.cpp \
    Tileset.cpp \
    Tile.cpp \
    Image.cpp \
    ILayer.cpp \
    TileLayer.cpp \
    ImageLayer.cpp \
    ObjectLayer.cpp \
    ColorLayer.cpp \
    TileOffset.cpp \
    Data.cpp \
    Object.cpp \
    base64/base64.cpp

HEADERS += \
    Map.hpp \
    Properties.hpp \
    Tileset.hpp \
    Tile.hpp \
    Image.hpp \
    ILayer.hpp \
    TileLayer.hpp \
    Utils.hpp \
    ImageLayer.hpp \
    ObjectLayer.hpp \
    ColorLayer.hpp \
    TileOffset.hpp \
    Data.hpp \
    Object.hpp \
    base64/base64.h

