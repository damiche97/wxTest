cmake_minimum_required(VERSION 3.19)
project(wxtest)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")


# Request the required wxWidgets libs
find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

set(HEADER_FILES
        "cMain.h"
        "cApp.h"
        "cEditorFrame.h"
        "cCanvas.h"
        )

set(SOURCE_FILES
        "cMain.cpp"
        "cApp.cpp"
        "cEditorFrame.cpp"
        "cCanvas.cpp"
        )

SOURCE_GROUP(Header FILES ${HEADER_FILES})
SOURCE_GROUP(Source FILES ${SOURCE_FILES})
add_executable(main ${HEADER_FILES} ${SOURCE_FILES})

# Define the build target for the executable
# add_executable(main WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(main ${wxWidgets_LIBRARIES})

# include_directories(.)

