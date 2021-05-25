# LetsPlay
### Project #2 - Algorithms and Data Structures II - CE


Requisites:

* C++ (at least C++ 17)
* SpdLog
* SFML

SpdLog installation on linux:

    sudo apt update
    sudo apt install libspdlog-dev

SFML installation on linux:

    sudo apt-get install libsfml-dev

If using CLion, add to the CmakeLists.txt:

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
    target_link_libraries(LetsPlay sfml-graphics sfml-window sfml-system)
