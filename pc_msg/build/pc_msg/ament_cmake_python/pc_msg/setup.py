from setuptools import find_packages
from setuptools import setup

setup(
    name='pc_msg',
    version='0.0.0',
    packages=find_packages(
        include=('pc_msg', 'pc_msg.*')),
)
