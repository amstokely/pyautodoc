import sys

sys.path.insert(1, '../lib')
from atom import Atom

index = 0
name = 'CA'
element = 'C'
residueName = 'GLU'
residueId = 1
mass = 12.001

'''
Creates an empty Atom object
'''
newAtom = Atom()

'''
Sets newAtom's element symbol to C 
'''
newAtom.element(element)

'''
->C
'''
print(newAtom.element())