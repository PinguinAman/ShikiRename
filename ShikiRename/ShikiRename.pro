# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = ShikiRename
DESTDIR = ../x64/$(ConfigurationName)
QT += core network widgets gui
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB QT_NETWORK_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += $(ConfigurationName)
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ShikiRename.pri)