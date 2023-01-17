from pyautodoc import AutoDoc
import os

atom_docs = AutoDoc('../include/atom.h')
print(atom_docs.classes()[0].methods()[0].description())
print(atom_docs.classes()[0].methods()[0].parameters()[0])
print(atom_docs.classes()[0].methods()[1].returnInfo())
os.remove('atom_docs.i')
atom_docs.writeSwigDocString('atom_docs.i')
