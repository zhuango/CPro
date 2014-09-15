TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    PriorityQueue/BinaryHeap.cpp \
    graph.cpp \
    ShortPathUnweighted.cpp \
    ShortPathWeighted.cpp \
    DisjSet/DisjSet.cpp

OTHER_FILES += \
    Data/mimSpanningTree.input \
    Data/ShortestPath.input \
    Data/Topo.input

HEADERS += \
    PriorityQueue/BinaryHeap.h \
    graph.h \
    DisjSet/DisjSet.h

