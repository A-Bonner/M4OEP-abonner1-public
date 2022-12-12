cmake_minimum_required(VERSION 3.8)
project(M4OEP-abonner1)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib/x64")
endif (WIN32)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wno-deprecated")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES})
#add_executable(M4OEP graphics.cpp graphics.h Button.cpp Button.h Quad.cpp Quad.h Slime.cpp Slime.h Food.cpp Food.h EverythingSlime.cpp EverythingSlime.h FavoriteSlime.cpp FavoriteSlime.h UniqueDietSlime.cpp UniqueDietSlime.h)
#add_executable(M2OEP main.cpp Slime.cpp Food.cpp EverythingSlime.cpp FavoriteSlime.cpp UniqueDietSlime.cpp)



if (WIN32)
    target_link_libraries (main.cpp ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()
