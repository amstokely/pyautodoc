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

'''
->0 CA C GLU 1 12.001
'''
print(
    newAtom.index(),
    newAtom.name(),
    newAtom.element(),
    newAtom.residueName(),
    newAtom.residueId(),
    newAtom.mass()
)
