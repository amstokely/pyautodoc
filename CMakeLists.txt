cmake_minimum_required(VERSION 3.21)
project(pyautodoc LANGUAGES CXX)


set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/wrappers/pyautodoc/pyautodoc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/wrappers/pyautodoc/pyautodoc)

find_package (Python3 COMPONENTS Interpreter Development)
find_package(SWIG REQUIRED)
set(SWIG_INTERFACE ${CMAKE_SOURCE_DIR}/swig/autodoc.i)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/example/include)
include_directories(${Python3_INCLUDE_DIRS})

set_source_files_properties(${SWIG_INTERFACE} PROPERTIES CPLUSPLUS ON
        )
include(${SWIG_USE_FILE})

add_library(_pyautodoc SHARED
        src/autodoc.cpp
        src/autodoc_function.cpp
        src/utils.cpp
        src/autodoc_parameter.cpp
        src/autodoc_description.cpp
        src/autodoc_return.cpp
        src/autodoc_class.cpp
        src/autodoc_example.cpp src/autodoc_note.cpp include/autodoc_note.h)
set_target_properties(_pyautodoc PROPERTIES OUTPUT_DIR ${LIB_DIR} LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_SWIG_OUTDIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

swig_add_library(
        pyautodoc LANGUAGE python
        SOURCES ${SWIG_INTERFACE} ${SRC_DIR}/autodoc.cpp ${SWIG_INTERFACE}
)
swig_link_libraries(pyautodoc _pyautodoc)
set(PYTHON_BUILD_EXT_ARGS "setup.py" "build_ext" "--inplace")
set(PYTHON_BUILD_ARGS "setup.py" "build")
set(PYTHON_INSTALL_ARGS "setup.py" "install")
add_custom_target(PythonInstall
        COMMAND ${Python3_EXECUTABLE} ${PYTHON_BUILD_EXT_ARGS}
        COMMAND ${Python3_EXECUTABLE} ${PYTHON_BUILD_ARGS}
        COMMAND ${Python3_EXECUTABLE} ${PYTHON_INSTALL_ARGS}
        WORKING_DIRECTORY ../wrappers/pyautodoc)
