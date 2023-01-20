from pyautodoc import AutoDoc
import os

atom_docs = AutoDoc(
    '../include/atom.h',
)
if os.path.exists('atom_docs1.i'):
    os.remove('atom_docs1.i')
atom_docs.writeSwigDocString('atom_docs.i')
