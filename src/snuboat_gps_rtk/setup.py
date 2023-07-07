from setuptools import find_packages, setup

package_name = 'snuboat_gps_rtk'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='snuboat',
    maintainer_email='kaboat@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'snuboat_gps_rtk = snuboat_gps_rtk.snuboat_gps_rtk:main'
        ],
    },
)
