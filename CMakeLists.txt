cmake_minimum_required(VERSION 3.15)
project(dp4dsDistribution)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(ADictionary)
include_directories(AQueue)
include_directories(ArrayClassic)
include_directories(ArrayT)
include_directories(ASeq)
include_directories(AShape)
include_directories(ASorter)
include_directories(AStack)
include_directories(BiTreeCS)
include_directories(BiTreeCSV)
include_directories(BiTreeL)
include_directories(CAMetrics)
include_directories(Counter)
include_directories(DictionaryA)
include_directories(DictionaryBST)
include_directories(DictionaryHash)
include_directories(DictionaryL)
include_directories(DictionaryV)
include_directories(FigureA3)
include_directories(FigureA8)
include_directories(Graph)
include_directories(HashData)
include_directories(ListC)
include_directories(ListCS)
include_directories(ListCSV)
include_directories(ListCV)
include_directories(ListL)
include_directories(LLRBTree)
include_directories(NTree)
include_directories(NWBTree)
include_directories(PriorityQ)
include_directories(QueueA)
include_directories(QueueL)
include_directories(QueueLCSV)
include_directories(QueueV)
include_directories(Rational)
include_directories(Shape)
include_directories(ShapeFactory)
include_directories(SortClassic)
include_directories(SortCompAsgn)
include_directories(SortInt)
include_directories(SortProbe)
include_directories(StackA)
include_directories(StackL)
include_directories(StackLCSV)
include_directories(StackV)
include_directories(SwapPtrRef)
include_directories(SwapPtrVal)
include_directories(SwapRef)
include_directories(SwapVal)
include_directories(Utilities)
include_directories(VectorT)

add_executable(ArrayClassic ArrayClassic/ArrayClassicMain.cpp)
add_executable(ArrayT ArrayT/ArrayTMain.cpp)
add_executable(BiTreeCS BiTreeCS/BiTreeCSMain.cpp)
add_executable(BiTreeCSV BiTreeCSV/BiTreeCSVMain.cpp)
add_executable(BiTreeL BiTreeL/BiTreeLMain.cpp)
add_executable(DictionaryA DictionaryA/DictionaryAMain.cpp)
add_executable(DictionaryBST DictionaryBST/DictionaryBSTMain.cpp)
add_executable(DictionaryHash DictionaryHash/DictionaryHashMain.cpp)
add_executable(DictionaryL DictionaryL/DictionaryLMain.cpp)
add_executable(FigureA3 FigureA3/FigureA3Main.cpp)
add_executable(FigureA8 FigureA8/FigureA8Main.cpp)
add_executable(Graph Graph/GraphMain.cpp)
add_executable(HashData HashData/HashMain.cpp)
add_executable(ListC ListC/ListCMain.cpp)
add_executable(ListCS ListCS/ListCSMain.cpp)
add_executable(ListCSV ListCSV/ListCSVMain.cpp)
add_executable(ListCV ListCV/ListCVMain.cpp)
add_executable(ListL ListL/ListLMain.cpp)
add_executable(LLRBTree LLRBTree/LLRBTreeMain.cpp)
add_executable(NTree NTree/NTreeMain.cpp)
add_executable(NWBTree NWBTree/NWBTreeMain.cpp)
add_executable(PriorityQ PriorityQ/PriorityQMain.cpp)
add_executable(QueueA QueueA/QueueAMain.cpp)
add_executable(QueueL QueueL/QueueLMain.cpp)
add_executable(Rational Rational/RationalMain.cpp
        Rational/Rational.cpp)
add_executable(Shape Shape/ShapeMain.cpp
        Shape/Circle.cpp
        Shape/Line.cpp
        Shape/MysteryShape.cpp
        Shape/NullShape.cpp
        Shape/Rectangle.cpp
        Shape/RightTriangle.cpp)
add_executable(SortClassic SortClassic/SortClassicMain.cpp)
add_executable(SortCompAsgn SortCompAsgn/SortCompAsgnMain.cpp)
add_executable(SortInt SortInt/SortIntMain.cpp)
add_executable(SortProbe SortProbe/SortProbeMain.cpp)
add_executable(StackA StackA/StackAMain.cpp)
add_executable(StackL StackL/StackLMain.cpp)
add_executable(SwapPtrRef SwapPtrRef/SwapPtrRefMain.cpp)
add_executable(SwapPtrVal SwapPtrVal/SwapPtrValMain.cpp)
add_executable(SwapRef SwapRef/SwapRefMain.cpp)
add_executable(SwapVal SwapVal/SwapValMain.cpp)
add_executable(VectorT VectorT/VectorTMain.cpp)

add_library(Utilities STATIC Utilities/Utilities.cpp)

target_link_libraries(ArrayClassic LINK_PUBLIC Utilities)
target_link_libraries(ArrayT LINK_PUBLIC Utilities)
target_link_libraries(BiTreeCS LINK_PUBLIC Utilities)
target_link_libraries(BiTreeCSV LINK_PUBLIC Utilities)
target_link_libraries(BiTreeL LINK_PUBLIC Utilities)
target_link_libraries(DictionaryA LINK_PUBLIC Utilities)
target_link_libraries(DictionaryBST LINK_PUBLIC Utilities)
target_link_libraries(DictionaryHash LINK_PUBLIC Utilities)
target_link_libraries(DictionaryL LINK_PUBLIC Utilities)
target_link_libraries(FigureA3 LINK_PUBLIC Utilities)
target_link_libraries(FigureA8 LINK_PUBLIC Utilities)
target_link_libraries(Graph LINK_PUBLIC Utilities)
target_link_libraries(HashData LINK_PUBLIC Utilities)
target_link_libraries(ListC LINK_PUBLIC Utilities)
target_link_libraries(ListCS LINK_PUBLIC Utilities)
target_link_libraries(ListCSV LINK_PUBLIC Utilities)
target_link_libraries(ListCV LINK_PUBLIC Utilities)
target_link_libraries(ListL LINK_PUBLIC Utilities)
target_link_libraries(LLRBTree LINK_PUBLIC Utilities)
target_link_libraries(NTree LINK_PUBLIC Utilities)
target_link_libraries(NWBTree LINK_PUBLIC Utilities)
target_link_libraries(PriorityQ LINK_PUBLIC Utilities)
target_link_libraries(QueueA LINK_PUBLIC Utilities)
target_link_libraries(QueueL LINK_PUBLIC Utilities)
target_link_libraries(Rational LINK_PUBLIC Utilities)
target_link_libraries(Shape LINK_PUBLIC Utilities)
target_link_libraries(SortClassic LINK_PUBLIC Utilities)
target_link_libraries(SortCompAsgn LINK_PUBLIC Utilities)
target_link_libraries(SortInt LINK_PUBLIC Utilities)
target_link_libraries(SortProbe LINK_PUBLIC Utilities)
target_link_libraries(StackA LINK_PUBLIC Utilities)
target_link_libraries(StackL LINK_PUBLIC Utilities)
target_link_libraries(VectorT LINK_PUBLIC Utilities)