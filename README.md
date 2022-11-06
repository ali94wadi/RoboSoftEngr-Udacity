## UDACITY RoboSoftEngr-HomeServiceRobot

### Summary of Requirements
For the last project in the nanodegree, the software side of things for a ROS-enabled home service robot is to be developed. The robot is to receive commands to pick up up an object, will localize itself through AMCL using a pregenerated static map of its environment, use the navigation stack to plan a path and move to the object, upon arriving and "pickin up" the object, the destination is sent over to the robot and the localization/path planning/navigation is to happen again.

The following is developed:
- A gazebo world file and a map built through SLAM are generated.
- Scripts: Shell scripts are written to ease the launch of many nodes with varying arguments and parameters.
- rvizConfig: Customized rviz configuration files are saved as needed.
- pick_objects: A node that commands the robot to drive to the pickup and drop off zones.
- add_markers: A node that models the virtual object with a marker in rviz and displays it at the pickup and drop off zones.

### Dependencies
To get the prerequisites the [SETUP](setup.sh) script can be used.


### Developed Packages
#### Localization & Mapping
To perform the localization and mapping, `gmapping SLAM` can be used. The script [test_slam](test_slam.sh) will launch the needed packages to perform this task: gazebo simulation environment, SLAM packages, rviz topic visualization, and robot teleoperation through the keyboard. The user can drive the robot around the building to generate the ocupancy grid map. The map can be saved using `rosrun map_server map_saver -f map`.

#### Navigation
Path panning and following, when a map is available to it, can be seemlessly done with the ROS `move_base` navigation stack. The script [test_navigation](test_navigation.sh) will launch the needed packages to perform this task. 

#### Pick Objects
This package integrates with the ROS `move_base` navigation stack to send waypoints to the robot and monitor its pose in the environment. As soon as the robot reaches its sent waypoint (pick up zone) successfully, another waypoint (drop off zone) is sent for the robot to navigate to after a waiting period of 5 seconds. The script [pick_objects](pick_objects.sh) will launch the needed packages to perform this task. 

#### Add Markers
This package uses gazebo markers to show in rviz a cube in eithe pick up/drop off zones. This `add_markers` integrates with `pick_objects` to work in unison and show the markers where required. The script [add_markers](add_markers.sh) will launch the needed packages to perform this task. 

Additionally, to see this package functioning independently, another duplpicate package `using_markers` is developed to show the marker at pick up, wait 5 seconds, hide it and wait 5 seconds, and then show the marker at drop off. The script [using_markers](using_markers.sh) will launch the needed packages to perform this task. 

#### Home service robot
This task integrates all the aforementioned packages in performing the required task:
1. Displaying a marker at pick up zone
2. Sending the waypoint to the Robot
3. Localizing the Robot with AMCL using the saved map file 
4. Navigating to the pick up zone 
5. Hiding the first marker and showing another at drop off zone
6. Sending the waypoint to the Robot

The script [home_service](home_service.sh) will launch the needed packages to perform this task. 

### Everything in Action
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


