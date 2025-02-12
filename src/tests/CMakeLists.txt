set(DArr "../collections/DynamicArray/include") 
set(LList "../collections/LinkedList/include") 
set(HMap "../collections/HashMap/include") 
set(Hist "../core/Histogram/include")
set(SMatrix "../core/SparseMatrix/include")
set(SVector "../core/SparseVector/include") 


add_executable(datests DynamicArrayTests.cpp)
target_include_directories(datests PUBLIC ${DArr})

add_executable(hmtest HashMapTests.cpp)
target_include_directories(hmtest PUBLIC ${HMap})

add_executable(htests HistogramTests.cpp)
target_include_directories(htests PUBLIC ${Hist})

add_executable(lltests LinkedListTests.cpp)
target_include_directories(lltests PUBLIC ${LList})

add_executable(smtests SparseMatrixTests.cpp)
target_include_directories(smtests PUBLIC ${DArr} ${SMatrix})

add_executable(svtests SparseVectorTests.cpp)
target_include_directories(svtests PUBLIC ${DArr} ${SVector})