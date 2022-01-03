QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddressInput.cpp \
    ContextMenu.cpp \
    DirColumn.cpp \
    DirModel.cpp \
    DirList.cpp \
    MenuBar.cpp \
    Preview.cpp \
    SidePanel.cpp \
    TabFrame.cpp \
    clipboard.cpp \
    main.cpp \
    MainWindow.cpp \
    ToolBar.cpp

HEADERS += \
    AddressInput.hpp \
    ContextMenu.hpp \
    DirColumn.hpp \
    DirList.hpp \
    DirModel.hpp \
    MenuBar.hpp \
    Preview.hpp \
    SidePanel.hpp \
    TabFrame.hpp \
    ToolBar.hpp \
    MainWindow.hpp \
    api_signal.hpp \
    clipboard.hpp

#FORMS += \
#    mainwindow.ui

TRANSLATIONS += \
    fileExpress_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
