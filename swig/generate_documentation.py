import sys
from pathlib import Path

from pyautodoc import AutoDoc

cwd = Path.cwd()
header_path = cwd.parent / "include/autodoc.h"
samples_dir = cwd.parent / "example/atom/samples"

pyautodoc_swig_documentation = AutoDoc(
    str(header_path),
    str(samples_dir),
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
pyautodoc_swig_documentation.writeSwigDocString(str(cwd / "autodoc_documentation.i"))
