cmake_minimum_required(VERSION 3.21)
project(pyautodoc LANGUAGES CXX)


set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/wrappers/pyautodoc/pyautodoc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/wrappers/pyautodoc/pyautodoc)

find_package (Python3 COMPONENTS Interpreter Development)
find_package(SWIG REQUIRED)
find_package(Doxygen REQUIRED)
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
        src/autodoc_example.cpp src/autodoc_note.cpp)
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
set(DOXYGEN_PROJECT_NAME PyAutoDoc)
set(DOXYGEN_PREDEFINED DOXYGEN_IGNORE)


set(DOXYGEN_ALIASES
        [[PythonExample{1}=<b>Python Example</b><br>\code{.py}\1\endcode]]
        [[CppExample{1}=<b>C++ Example</b><br>\code{.cpp}\1\endcode]]
        [[type{1}=<!-- \1 -->]]
        [[function{1}=<!-- \1 -->]]
        [[const=<!--  -->]]
        [[AutoDocIgnore=<!--  -->]]
        [[doxy=/*!]]
        [[enddoxy=*/]]
        )
set(DOXYGEN_ENABLE_PREPROCESSING NO)
set(DOXYGEN_STRIP_CODE_COMMENTS NO)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN_EXAMPLE_PATH ${CMAKE_SOURCE_DIR}/doxygen/)
set(DOXYGEN_IMAGE_PATH ${CMAKE_SOURCE_DIR}/doxygen/tutorial)
set(DOXYGEN_GENERATE_DOCBOOK YES)
set(DOXYGEN_GENERATE_LATEX YES)
set(DOXYGEN_SHOW_FILES NO)
set(DOXYGEN_USE_PDFLATEX YES)
set(DOXYGEN_FULL_PATH_NAMES NO)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs)
set(DOXYGEN_GENERATE_XML TRUE)
list(APPEND PYAUTODOC_DOCUMENTATION_INPUT_FILES
        ${CMAKE_SOURCE_DIR}/doxygen/docs.h
        )
doxygen_add_docs(
        pyautodoc_docs
        ${PYAUTODOC_DOCUMENTATION_INPUT_FILES}
)
set(DOCUMENTATION_ARGS "Doxyfile.pyautodoc_docs")
add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOCUMENTATION_ARGS}
        )
