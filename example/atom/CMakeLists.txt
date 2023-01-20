cmake_minimum_required(VERSION 3.21)
project(atom LANGUAGES CXX)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
find_package (Python3 COMPONENTS Interpreter Development)
find_package(Doxygen REQUIRED)
find_package(SWIG REQUIRED)
set(SWIG_INTERFACE ${CMAKE_SOURCE_DIR}/swig/atom.i)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${Python3_INCLUDE_DIRS})
set_source_files_properties(${SWIG_INTERFACE} PROPERTIES CPLUSPLUS ON)
include(${SWIG_USE_FILE})
add_library(_atom SHARED
        src/atom.cpp
        )
set_target_properties(_atom PROPERTIES OUTPUT_DIR ${LIB_DIR} LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
set(CMAKE_SWIG_OUTDIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
swig_add_library(
        atom LANGUAGE python
        SOURCES ${SWIG_INTERFACE} ${SRC_DIR}/atom.cpp ${SWIG_INTERFACE}
)
swig_link_libraries(atom _atom)
set(DOXYGEN_PROJECT_NAME Atom)
set(DOXYGEN_ALIASES
        [[PythonExample{1}=<b>Python Example</b><br>\code{.py}\1\endcode]]
        [[CppExample{1}=<b>C++ Example</b><br>\code{.cpp}\1\endcode]]
        [[PythonExampleFile{1}=<b>Python Example</b><br>\include \1]]
        [[CppExampleFile{1}=<b>C++ Example</b><br>\include \1]]
        [[type{1}=<!-- \1 -->]]
        [[function{1}=<!-- \1 -->]]
        [[const=<!--  -->]]
        [[AutoDocIgnore=<!--  -->]]
        )
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN_EXAMPLE_PATH /home/andy/)
set(DOXYGEN_FULL_PATH_NAMES NO)
set(DOXYGEN_ENABLE_PREPROCESSING NO)
set(DOXYGEN_STRIP_CODE_COMMENTS NO)
set(DOXYGEN_COMPACT_LATEX YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN_EXAMPLE_PATH
        ${CMAKE_SOURCE_DIR}/doxygen/
        ${CMAKE_SOURCE_DIR}/
        )
set(DOXYGEN_IMAGE_PATH ${CMAKE_SOURCE_DIR}/doxygen/tutorial)
set(DOXYGEN_GENERATE_DOCBOOK YES)
set(DOXYGEN_GENERATE_LATEX YES)
set(DOXYGEN_SHOW_FILES NO)
set(DOXYGEN_USE_PDFLATEX YES)
set(DOXYGEN_FULL_PATH_NAMES NO)
set(DOXYGEN_GENERATE_XML TRUE)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs)
list(APPEND ATOM_DOCUMENTATION_INPUT_FILES ${CMAKE_SOURCE_DIR}/include/atom.h )
doxygen_add_docs(
        atom_docs
        ${ATOM_DOCUMENTATION_INPUT_FILES}
)
set(DOCUMENTATION_ARGS "Doxyfile.atom_docs")
add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOCUMENTATION_ARGS}
        )