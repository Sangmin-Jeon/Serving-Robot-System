from setuptools import find_packages
from setuptools import setup

setup(
    name='b4_serv_robot_interface',
    version='0.0.0',
    packages=find_packages(
        include=('b4_serv_robot_interface', 'b4_serv_robot_interface.*')),
)
