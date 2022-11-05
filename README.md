# RoboSoftEngr-HomeServiceRobot

For the last project in the nanodegree, the following is developed minus any packages that one can download:
```
catkin_ws/
|-- add_markers.sh
|-- home_service.sh
|-- maps
|   |-- map.pgm
|   `-- map.yaml
|-- pick_objects.sh
|-- rviz
|   `-- home_service_robot.rviz
|-- setup.sh
|-- src
|   |-- CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
|   |-- add_markers
|   |   |-- CMakeLists.txt
|   |   |-- package.xml
|   |   `-- src
|   |       `-- add_markers.cpp
|   |-- pick_objects
|   |   |-- CMakeLists.txt
|   |   |-- package.xml
|   |   `-- src
|   |       `-- pick_objects.cpp
|   `-- using_markers
|       |-- CMakeLists.txt
|       |-- include
|       |   `-- using_markers
|       |-- package.xml
|       `-- src
|           `-- using_markers.cpp
|-- test_navigation.sh
|-- test_slam.sh
|-- timed_markers.sh
`-- worlds
    |-- Untitled
    |   |-- Untitled
    |   |   |-- model.config
    |   |   `-- model.sdf
    |   |-- model.config
    |   `-- model.sdf
    |-- empty.world
    |-- myworld
    |   |-- model.config
    |   `-- model.sdf
    |-- myworld.world
    `-- wworld.world
```

To get the prerequisites the setup.sh script can be used.
