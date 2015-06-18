TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    io/disklist.cpp \
    io/diskdatastructure.cpp \
    io/diskbinarytree.cpp \
    io/diskavltree.cpp \
    io/nosqlrow.cpp \
    io/rowelement.cpp \
    io/badparseexception.cpp \
    io/ioexception.cpp \
    io/nullpointerexception.cpp \
    io/arrayindexoutbounds.cpp \
    io/elementdontfounded.cpp

HEADERS += \
    io/disklist.h \
    io/diskdatastructure.h \
    io/diskbinarytree.h \
    io/diskavltree.h \
    io/nosqlrow.h \
    io/rowelement.h \
    io/badparseexception.h \
    io/ioexception.h \
    io/nullpointerexception.h \
    io/arrayindexoutbounds.h \
    io/elementdontfounded.h

OTHER_FILES += \
    referencias.txt

