import sys

sys.path.insert(1, 'lib')
from atom import Atom

obj = Atom()
obj.element(element="C")
print(obj.element())
