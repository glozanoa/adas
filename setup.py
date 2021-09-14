#!/usr/bin/env python3
#
# adas setup
#
# date: Sep 1 2021
# Maintainer: glozanoa <glozanoa@uni.pe>


from setuptools import find_packages
from distutils.core import setup, Extension
from Cython.Build import cythonize

from adas import VERSION

cxx_extensions = [
   Extension(name='adas.algorithm.sort.pysort',
             sources=['adas/algorithm/sort/pysort.pyx'],
             include_dirs = ['adas'],
             language='c++')
]



LONG_DESCRIPTION = ''
with open('README.md', 'r') as f:
    LONG_DESCRIPTION = f.read()

def get_requirements():
    requirements = []
    with open('requirements.txt', 'r') as adas_requirements:
        for line in adas_requirements:
            line = line.rstrip()
            if line == '' or line.startswith("#"):
                continue

            requirements.append(line)

    return requirements


setup(
    name='pyadas',
    version=VERSION,
    description='Generic algorithms and data structures',
    long_description=LONG_DESCRIPTION,
    long_description_content_type='text/markdown',
    keywords=['Algorithms', 'Data Structures'],
    author='glozanoa',
    author_email='glozanoa@uni.pe',
    url='https://github.com/glozanoa/adas',
    license='GPL3',
    classifiers = [
        "License :: OSI Approved :: GNU General Public License v3 (GPLv3)",
        "Topic :: Software Development :: Libraries",
        "Operating System :: POSIX :: Linux",
        "Programming Language :: Python :: 3.9",
        "Programming Language :: Python :: 3.8",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.6",
    ],
    ext_modules=cythonize(cxx_extensions, language_level=3),
    package_data={
        'adas': ['algorithm/sort/serial.hpp',
                 'utilities/*.hpp',
                 'algorithm/sort/pysort.pyx']
    },
    packages=find_packages(),
    #install_requires = get_requirements(),
    include_package_data=True
)
