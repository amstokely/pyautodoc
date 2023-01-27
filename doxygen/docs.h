//
// Created by andy on 1/19/23.
//

#ifndef PYAUTODOC_DOXYGEN_H
#define PYAUTODOC_DOXYGEN_H

/*!
* @mainpage
* <H1>About</H1>
* PyAutoDoc is a documentation solution for C++/Python projects.
* By converting C++ doxygen comment blocks into SWIG docstring
* feature directives, PyAutoDoc automates documentation transfer
* between wrapped C++/Python functions and classes.
* <H1>Installation</H1>
* As of right now, PyAutoDoc has to be installed from source and
* requires that cmake, doxygen, and SWIG are installed. PyAutoDoc
* can be installed as follows.
* - Use git to download a copy of PyAutoDoc's source code.
* @code{.sh}
* git clone https://github.com/amstokely/pyautodoc.git
* @endcode
* - Go into pyautodoc's root directory
* @code{.sh}
* cd pyautodoc
* @endcode
* - Create a directory to build pyautodoc in.
* @code{.sh}
* mkdir build
* @endcode
* - Enter the build directory
* @code{.sh}
* cd build
* @endcode
* - Build pyautodoc with cmake.
* @code{.sh}
* cmake ..
* make
* make PythonInstall
* @endcode
* - To test the install run
* @code{.sh}
* python -c "from pyautodoc import AutoDoc"; echo $?
* @endcode
* which should ouput
* @code
* 0
* @endcode
* if the install was successful
* .
* <H1>Getting started</H1>
* After installing PyAutoDoc, define the following doxygen aliases in
* the project's CMakeLists.txt.
* @include doxygen_aliases.txt
* These aliases are used to communicate difficult to parse
* information to PyAutoDoc, and are hidden from doxygen's HTML,
* XML, and LaTex. Brief descriptions of each alias are provided below.
* - <B>PythonExample{\<text\>} </B>
* 		-# The provided text is the path to a Python example file.
* 		with respect to the DOXYGEN_EXAMPLE_PATH.
* - <B>CppExample{\<text\>} </B>
* 		-# The provided text is the path to a C++ example file.
* 		with respect to the DOXYGEN_EXAMPLE_PATH.
* - <B>type{\<text\>}</B>
* 		-# The provided text defines the type of a function or parameter
* 		-# If used with a parameter, place on the line following the
* 		parameter's name and/or description.
* 		-# If used with a function, place next to the \@function
* 		command.
* - <B>function{\<text\>}</B>
* 		-# The provided text defines the name of a function.
* 		-# Place on the second of the docstring.
* - <B>const</B>
* 		-# Indicates that a function is const.
* 		-# Place next to the \@function or \@type command.
* - <B>AutoDocIgnore</B>
* 		-# Indicates PyAutoDoc should ignore a class or function.
* 		-# Place on the first line of the comment block.
*/

#endif //PYAUTODOC_DOXYGEN_H
