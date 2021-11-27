CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    unit_test.cpp
    dungeon.cpp
    enemy.cpp
    town.cpp
)

ADD_EXECUTABLE(main
    main.cpp
    dungeon.cpp
    enemy.cpp
    town.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
