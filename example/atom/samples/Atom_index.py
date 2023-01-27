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
Creates a new Atom object using the above 
parameters
'''
newAtom = Atom(
    index,
    name,
    element,
    residueName,
    residueId,
    mass,
)

index_ = newAtom.index()

'''
->0
'''
print(index_)
