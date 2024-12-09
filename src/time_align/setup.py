from setuptools import setup
import os
from glob import glob

package_name = 'time_align'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ubuntu',
    maintainer_email='ubuntu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'timestamp_align_pts = time_align.timestamp_align_node:main',
            'stamp_marker_parse = time_align.stamp_marker:main',
            'timestamp_align_all = time_align.timestamp_align_node_subprocess:main',
        ],
    },
)
