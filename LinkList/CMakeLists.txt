cmake_minimum_required(VERSION 2.8.9)
PROJECT (HASHMAP)

if(CROSS_COMPILE)
	set(CMAKE_CXX_STANDARD 11)
	list( APPEND CMAKE_CXX_FLAGS" ${CMAKE_CXX_FLAGS} -g ")
	message("\n ###################### CROSS COMPILER ENVIRONMENT ############################ \n ")
else()
	list( APPEND CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS} -g ")
	message("\n  ###################### x86 COMPILER ENVIRONMENT ############################ \n ")
endif()

find_package (Boost 1.65.1 REQUIRED COMPONENTS thread system filesystem)


if(CROSS_COMPILE)
	set(LIBS ${Boost_LIBRARIES} )
else()
        set(LIBS ${Boost_LIBRARIES} -lpthread -lrt )
endif()


ADD_EXECUTABLE(HASHMAP main.cpp)
target_link_libraries(HASHMAP ${LIBS})
