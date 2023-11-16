import os.path

from setuptools import find_packages
from setuptools import setup

path = os.path.relpath(os.path.dirname(__file__))

setup(
    author='Andy Stokely',
    email='amstokely@ucsd.edu',
    name='pyautodoc',
    install_requires=[],
    platforms=['Linux',
               'Unix', ],
    python_requires=">=3.8",
    py_modules=[path + "pyautodoc/pyautodoc"],
    packages=find_packages() + [''],
    zip_safe=False,
    package_data={
        '': [
            path + '/pyautodoc/_pyautodoc.so'
        ]
    },
)
