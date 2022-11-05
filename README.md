# RoboSoftEngr-HomeServiceRobot

For the last project in the nanodegree, the functionality of a ROS-enabled home service robot is to be developed. The robot is to receive commands to pick up up an object, will localize itself through AMCL using a pregenerated static map of its environment, use the navigation stack to plan a path and move to the object, upon arriving and "pickin up" the object, the destination is sent over to the robot and the localization/path planning/navigation is to happen again.

The following is developed:
- A gazebo world file and a map built through SLAM are generated.
- Scripts: Shell scripts are written to ease the launch of many nodes with varying arguments and parameters.
- rvizConfig: Customized rviz configuration files are saved as needed.
- pick_objects: A node that commands the robot to drive to the pickup and drop off zones.
- add_markers: A node that models the virtual object with a marker in rviz and displays it at the pickup and drop off zones.

The following shows the Home Service Robot packages, topics, nodes and gazebo simulation environemnt when everything is running. 

![rosgraph](https://user-images.githubusercontent.com/23568809/200134443-13faa60f-7cda-4cc7-8fb7-53949b66ed5c.svg)


The directory uploaded here includes all but any dependency packages that can be download via apt-get:
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

To get the prerequisites the [SETUP](setup.sh) script can be used.
