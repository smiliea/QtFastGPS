QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SettingsDialog.cpp \
    acquire.cpp \
    code_table.cpp \
    correlator.cpp \
    datetime.cpp \
    dopp_pos.cpp \
    ephemerides.cpp \
    fastgps.cpp \
    gnss_utils.cpp \
    intrpsp3c.cpp \
    kiss_fft.c \
    kiss_fftr.c \
    lin_alg.cpp \
    main.cpp \
    MainWindow.cpp \
    nav.cpp \
    snap_shot.cpp \
    tracking.cpp

HEADERS += \
    MainWindow.h \
    SettingsDialog.h \
    _kiss_fft_guts.h \
    datetime.h \
    dopp_pos.h \
    fastgps.h \
    funcs.h \
    globals.h \
    intrpsp3c.h \
    kiss_fft.h \
    kiss_fftr.h \
    parameters.h \
    snap_shot.h \
    structs.h \
    types.h

FORMS += \
    MainWindow.ui \
    SettingsDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
