%feature("docstring")
AutoDoc
"\nDescription\n"
"--------------------\n"
"    The user interface class in PyAutoDoc that initiates the\n"
"    transfer of doxygen documentation from C++ to Python. A\n"
"    comprehensive PyAutoDoc tutorial can be found on the\n"
"    documentation main page."
"\n"
;%feature("docstring")
AutoDoc::writeSwigDocString
"writeSwigDocString(fname)->None\n"
"\nDescription\n"
"--------------------\n"
"    Writes a SWIG docstring feature directive interface file.\n"
"    *"
"\n"
"\nParameters\n"
"--------------------\n"
"fname: str\n"
"    The name of the output SWIG interface file. The\n"
"    interface file has a \".i\" extension and it's path must be in an\n"
"    include directive in the primary SWIG interface file."
"\n"
;