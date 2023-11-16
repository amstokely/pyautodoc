import sys

sys.path.insert(1, 'lib')
from atom import Atom

obj = Atom()
obj.element("C")
print(obj.element())
help(Atom)
