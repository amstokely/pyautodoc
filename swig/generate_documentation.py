import sys
from pathlib import Path

from pyautodoc import AutoDoc

header_path = Path("/home/astokely/pyautodoc/include/autodoc.h")
print(header_path.exists())

pyautodoc_swig_documentation = AutoDoc(
    str(header_path),
    "/home/astokely/pyautodoc/samples",
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
