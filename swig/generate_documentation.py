import sys

sys.path.insert(1, '../wrappers/pyautodoc/pyautodoc')
from pyautodoc import AutoDoc

pyautodoc_swig_documentation = AutoDoc(
    "../include/autodoc.h",
    {
        "std::map<std::string, std::string>*": "dict[str:str]",
        "std::map<std::string, std::string> *": "dict[str:str]",
        "const std::string&": "str",
        "void": "None",
    },
    {
        "std::map<std::string, std::string>*": "dict[str:str]",
        "std::map<std::string, std::string> *": "dict[str:str]",
        "const std::string&": "str",
        "void": "None",
    }
)
pyautodoc_swig_documentation.writeSwigDocString("autodoc_documentation.i")
