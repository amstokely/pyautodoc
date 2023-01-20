from pyautodoc import AutoDoc
import os

functionCppPyTypes = {
    "double": "float",
    "double&": "float",
    "const double&": "float",
    "std::string": "str",
    "std::string&": "str",
    "const std::string&": "str",
    "std::vector<int>*": "list[int]",
    "void": "None",
}

parameterCppPyTypes = {
    "double": "[np.float64, float, np.float32]",
    "double&": "[np.float64, float, np.float32]",
    "const double&": "[np.float64, float, np.float32",
    "std::string": "str",
    "std::string&": "str",
    "const std::string&": "str",
    "std::vector<int>*": "list[int]"
}
atom_docs = AutoDoc(
    '../include/atom.h',
    '/home/andy/CLionProjects/pyautodoc/example/atom',
    functionCppPyTypes,
    parameterCppPyTypes
)
if os.path.exists('atom_docs.i'):
    os.remove('atom_docs.i')
atom_docs.writeSwigDocString('atom_docs.i')
