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

residueId_ = newAtom.residueId()

'''
->1
'''
print(residueId_)