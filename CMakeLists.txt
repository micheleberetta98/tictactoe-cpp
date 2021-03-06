cmake_minimum_required(VERSION 3.14)

project(tictactoe-cpp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

if(ANDROID)
    add_library(tictactoe-cpp SHARED
      main.cpp
      controllers/gamecontroller.cpp
      controllers/boxcontroller.cpp
      controllers/playercontroller.cpp
      controllers/winnercontroller.cpp
      lib/box.cpp
      lib/entity.cpp
      lib/game.cpp
      lib/player.cpp
      lib/symbol.cpp
      qml.qrc
    )
else()
    add_executable(tictactoe-cpp
      main.cpp
      controllers/gamecontroller.cpp
      controllers/boxcontroller.cpp
      controllers/playercontroller.cpp
      controllers/winnercontroller.cpp
      lib/box.cpp
      lib/entity.cpp
      lib/game.cpp
      lib/player.cpp
      lib/symbol.cpp
      qml.qrc
    )
endif()

target_compile_definitions(tictactoe-cpp
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(tictactoe-cpp
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
