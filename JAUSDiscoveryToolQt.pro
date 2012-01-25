#-------------------------------------------------
#
# Project created by QtCreator 2012-01-19T14:41:28
#
#-------------------------------------------------

QT       += core gui

TARGET = JAUSDiscoveryToolQt
TEMPLATE = app

LIBS += -lJAUS_common -lpthread -lrt
CONFIG += -Wno-write-strings
INCLUDEPATH += JTS/include
INCLUDEPATH += JTS
INCLUDEPATH += /usr/local/include/jts_common

SOURCES += main.cpp\
        mainwindow.cpp \
    JTS/src/DiscoveryClient.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/DiscoveryClientService.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/DiscoveryClient_DiscoveryClientFSM_sm.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/DiscoveryClient_DiscoveryClientFSM.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/InternalEvents/GuiControlEntered.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/ReportSubsystemList.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/ReportServices.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/ReportServiceList.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/ReportIdentification.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/ReportConfiguration.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/QuerySubsystemList.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/QueryServices.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/QueryServiceList.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/QueryIdentification.cpp \
    JTS/src/urn_is4s_discovery_client_1_0/Messages/QueryConfiguration.cpp

HEADERS  += mainwindow.h \
    JTS/include/JConstants.h \
    JTS/include/DiscoveryClient.h \
    JTS/include/urn_is4s_discovery_client_1_0/DiscoveryClientService.h \
    JTS/include/urn_is4s_discovery_client_1_0/DiscoveryClient_DiscoveryClientFSM_sm.h \
    JTS/include/urn_is4s_discovery_client_1_0/DiscoveryClient_DiscoveryClientFSM.h \
    JTS/include/urn_is4s_discovery_client_1_0/InternalEvents/InternalEventsSet.h \
    JTS/include/urn_is4s_discovery_client_1_0/InternalEvents/GuiControlEntered.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/ReportSubsystemList.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/ReportServices.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/ReportServiceList.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/ReportIdentification.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/ReportConfiguration.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/QuerySubsystemList.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/QueryServices.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/QueryServiceList.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/QueryIdentification.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/QueryConfiguration.h \
    JTS/include/urn_is4s_discovery_client_1_0/Messages/MessageSet.h

FORMS    += mainwindow.ui
