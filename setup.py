#!/usr/bin/env python3
#
# adas setup
#
# date: Sep 1 2021
# Maintainer: glozanoa <glozanoa@uni.pe>

import os
from setuptools import setup, find_packages
#from Cython.Build import cythonize

from adas import VERSION

#cxx_extensions = [
#    Extension(name='adas.algortihm.sort', sources=['adas/algorithm/sort.pyx', 'adas/algorithm/sort/single.cpp'], language='c++')
#]




f = open('README.md', 'r')
LONG_DESCRIPTION = f.read()
f.close()

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
    #ext_modules=cythonize(cxx_extensions),
    #package_data={
    #    'adas': ['requirements.txt', 'README.md']#['algorithms/sort/serial.hpp', 'utilities/*.hpp']
    #},
    packages=find_packages(),
    install_requires = get_requirements(),
    include_package_data=True
)
