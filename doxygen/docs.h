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
* - <B>PyExample{\<text\>} \<!\--EXAMPLE END\--\></B>
* 		-# The provided text is a python usage example.
* - <B>CppExample{\<text\>} \<!\--EXAMPLE END\--\></B>
* 		-# The provided text is a C++ usage example.
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
*
* <H1>Tutorial</H1>
* In this short tutorial we'll create a light weight C++/Python
* class called atom, which could be used to store individual atom
* information that is typically
* present in a molecular topology file. First create a project root
* directory.
* @code{.sh}
* mkdir atom
* @endcode
* Navigate into the project's root directory
* @code
* cd atom
* @endcode
* and create a build, src, include, lib, and SWIG directory.
* @code
* mkdir src include lib swig build
* @endcode
* Copy the following CMakeLists.txt file into the projects root
* directory
* @include tutorial/CMakeLists.txt
* ,the following SWIG input file into the a file named atom.i
* in the projects SWIG directory
* @include tutorial/atom1.i
* ,the following header file into the a file named atom.h in
* the project's include directory
* @include tutorial/atom1.h
* and the following source file into a file named atom.cpp in the
* project's src directory.
* @include tutorial/atom1.cpp
* To compile a python callable version of atom, simply go into the
* build directory
* @code{.sh}
* cd build
* @endcode
* and build with cmake.
* @code{.sh}
* cmake ..
* make
* @endcode
* Now, navigate into the project's root directory
* @code{.sh}
* cd ..
* @endcode
* and create a file
* called test.py. Copy the below code into test.py.
* @include tutorial/test.py.
* When you run test.py
* @code{.py}
* python test.py
* @endcode
* it prints the Atom class's docstring.
* @include tutorial/atom_docstring1.txt
* Since this python class is generated from SWIG wrapper code, even if
* the C++ was documented using normal doxygen, none of documentation
* documentation would be copied into the python version. This is
* where PyAutoDoc comes in. Open the projects header file, atom.h,
* and add the below doxygen comment block directly above the Atom
* class declaration.
* @include tutorial/atom2.h
* Now create a file named generate_documentation.py in the projects
* SWIG folder and copy the below code into it.
* @include tutorial/generate_documentation.py
* The AutoDoc class parses the documentation content in the
* provided header file and stores it as a
* tree of various PyAutoDoc classes. Calling the
* AutoDoc.writeSwigDocString method
* writes the AutoDoc tree contents to the provided file in the form
* of SWIG docstring feature directives.
* Generate the SWIG docstring interface file by running
* generate_documentation.py.
* @code{.sh}
* python generate_documentation.py
* @endcode
* This creates a file named atom_docs.i, which is the SWIG interface
* file used to create python docstrings.
* @include tutorial/atom_docs1.i
* In order for SWIG to use this file during compilation, you have to
* add an include directive with the SWIG docstring interface file's
* path to the primary SWIG
* interface file.
* @include tutorial/atom2.i
* Rebuild the project
* @code{.sh}
* cd ../build
* rm -rf *
* cmake ..
* make
* @endcode
* and run test.py.
* @code{.sh}
* python test.py
* @endcode
* The terminal output should look like this.
* @include tutorial/atom_docstring2.txt
* As you can see, the C++ Atom class documentation was completely
* appended to the wrapped Python version's docstring. Let's add some
* more documentation to the C++ side. We'll add parameter
* documentation for each constructor parameter, an in code
* python example of how to create an Atom class instance, and
* descriptions for each of the class methods.
* @include tutorial/atom3.h
* Run generate_documentation.py
* @code{.sh}
* cd swig
* python generate_documentation.py
* @endcode
* ,rebuild the project
* @code{.sh}
* cd ../build
* rm -rf *
* cmake ..
* make
* @endcode
* and run test.py.
* @code{.sh}
* cd ..
* python test.py
* @endcode
* As before, all of the Atom class documentation from the C++ side
* was copied into the python version's docstring.
* @include tutorial/atom_docstring3.txt
* One thing you might notice is that the types in the python
* docstring are C++ types, which might confuse users who are
* unfamiliar with C++. To address this problem, you can pass a
* dictionary of
* C++/Python type substitutions to the python AutoDoc class
* constructor, and these substitutions are used when generating the
* SWIG docstring directives. You can define type substitutions for
* both parameters and functions. This is useful because
* functions can only return one type in python, while
* parameters can take on multiple types.
* To map all occurrences of std::string to str, all parameter
* occurrences of double to [np.float64, np.float32, float], and all
* function occurrences of double to float, modify generate
* documentation.py as follows.
* @include tutorial/generate_documentation2.py
* Notice how all C++ types were replaced by the substitutions passed to
* the AutoDoc python constructor in generate_documentation.py.
* @include tutorial/atom_docstring4.txt
* While python and C++ are both OOP languages that support
* polymorphism, they do so to different extents.
* Unlike C++, python does not support method overloading
* Being that method overloading is commonly used in C++, this poses a
* significant problem when generating python interfaces from C++.
* SWIG addresses this problem by scrambling the names of overloaded
* C++ methods under the hood, which preserves C++ method
* overloading on the python side. Natively, SWIG only copies the
* docstring for the last overloaded method when generating
* documentation for a set of overloaded methods. PyAutoDoc addresses
* this SWIG limitation, by concatenating all docstrings for a set of
* overloaded methods into one docstring. To illustrate this, lets
* overload all Atom class methods by defining a setting for each
* attribute, which will have the same name as the already implemented
* getter. We'll also add a note, using the doxygen \@note special
* method, to each getter/setter method
* specifying the method is a getter or setter. This might be
* helpful for users, since the getters/setters do not have
* get/set in their names. Additionally, each getter/setter will
* have a python example. Replace atom.h with
* @include tutorial/atom4.h
* and atom.cpp with
* @include tutorial/atom2.cpp
* Enter the swig directory, open generate_documentation.py and add
* @code{.py}
* "void" : "None"
* @endcode
* to the functionCppPyTypes dictionary.
* As before, run generate_documentation.py, rebuild the project,
* and run test.py.
* @include atom_docstring5.txt
* The documentation for all of the overloaded methods was copied into
* the python docstrings, and marked with version numbers. <BR>
* This
* concludes the tutorial. All final files used in this tutorial can be
* found in the example/atom PyAutoDoc source code directory.
*/

#endif //PYAUTODOC_DOXYGEN_H
