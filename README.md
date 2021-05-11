# LetsPlay
### Project #2 - Algorithms and Data Structures II - CE

Requisites:

* C++ and SFML

SFML installation on linux:

    sudo apt-get install libsfml-dev

If using CLion, add to the CmakeLists.txt:

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
    target_link_libraries(SMFLTry sfml-graphics sfml-window sfml-system)
