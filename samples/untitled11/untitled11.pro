TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_system -lboost_iostreams -lTgBot -lpthread -lssl -lcrypto

SOURCES += main.cpp \
    app.cpp

HEADERS += \
    app.h
