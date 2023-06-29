from setuptools import setup

package_name = 'snuboat_nav'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jiyoung',
    maintainer_email='mouse890@snu.ac.kr',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
		# 'WP_Following = snuboat_navigation.WP_Following:main',
        ],
    },
)
