from setuptools import find_packages
from setuptools import setup

setup(
    name='stamp_markerarray',
    version='0.0.0',
    packages=find_packages(
        include=('stamp_markerarray', 'stamp_markerarray.*')),
)
