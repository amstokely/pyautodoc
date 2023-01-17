from pyautodoc import AutoDoc
import os

atom_docs = AutoDoc('../include/atom.h')
os.remove('atom_docs.i')
atom_docs.writeSwigDocString('atom_docs.i')
