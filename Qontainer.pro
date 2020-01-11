######################################################################
# Automatically generated by qmake (3.0) lun lug 8 12:27:45 2019
######################################################################

TEMPLATE = app
TARGET = Qontainer
INCLUDEPATH += .

QT += widgets xml
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11
# Input
HEADERS += maincontroller.h \
           model.h \
           core/allhouse.h \
           core/bnb.h \
           core/hotelroom.h \
           core/privateroom.h \
           core/qontainer.h \
           core/roomgroup.h \
           core/service.h \
           core/sharedroom.h \
           gui/query.h \
           gui/createbnb/allhousepage.h \
           gui/createbnb/basepage.h \
           gui/createbnb/createbnbwizard.h \
           gui/createbnb/endpage.h \
           gui/createbnb/intopage.h \
           gui/createbnb/privatepage.h \
           gui/createbnb/sharedpage.h \
           gui/showbnb/bnblist.h \
           gui/showbnb/bnbmenu.h \
           gui/showbnb/bnbwidget.h \
           gui/showbnb/searchwidget.h \
           gui/showbnb/showbnb.h \
           gui/createbnb/components/allhouseinfowidget.h \
           gui/createbnb/components/baseinfowidget.h \
           gui/createbnb/components/hotelinfowidget.h \
           gui/createbnb/components/roomgroupslistwidget.h \
           gui/createbnb/components/roomgroupwidget.h \
           gui/createbnb/components/roomtypewidget.h \
           gui/createbnb/components/servicecheckbox.h \
           gui/createbnb/components/serviceswidget.h \
           gui/createbnb/components/sharedinfowidget.h
SOURCES += main.cpp \
           maincontroller.cpp \
           model.cpp \
           core/allhouse.cpp \
           core/bnb.cpp \
           core/hotelroom.cpp \
           core/privateroom.cpp \
           core/roomgroup.cpp \
           core/sharedroom.cpp \
           gui/query.cpp \
           gui/createbnb/allhousepage.cpp \
           gui/createbnb/basepage.cpp \
           gui/createbnb/createbnbwizard.cpp \
           gui/createbnb/endpage.cpp \
           gui/createbnb/intopage.cpp \
           gui/createbnb/privatepage.cpp \
           gui/createbnb/sharedpage.cpp \
           gui/showbnb/bnblist.cpp \
           gui/showbnb/bnbmenu.cpp \
           gui/showbnb/bnbwidget.cpp \
           gui/showbnb/searchwidget.cpp \
           gui/showbnb/showbnb.cpp \
           gui/createbnb/components/allhouseinfowidget.cpp \
           gui/createbnb/components/baseinfowidget.cpp \
           gui/createbnb/components/hotelinfowidget.cpp \
           gui/createbnb/components/roomgroupslistwidget.cpp \
           gui/createbnb/components/roomgroupwidget.cpp \
           gui/createbnb/components/roomtypewidget.cpp \
           gui/createbnb/components/servicecheckbox.cpp \
           gui/createbnb/components/serviceswidget.cpp \
           gui/createbnb/components/sharedinfowidget.cpp
RESOURCES += resources.qrc
