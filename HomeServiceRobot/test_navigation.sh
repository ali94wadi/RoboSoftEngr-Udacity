#!/bin/bash

# build the workspace
#cd $(pwd)/../../..; catkin_make

source $(find / -type d -name 'catkin_ws')/devel/setup.bash
#source ~/opt/ros/kinetic/setup.bash
export TURTLEBOT_GAZEBO_WORLD_FILE=$(find / -type d -name 'catkin_ws')/worlds/myworld.world
export TURTLEBOT_GAZEBO_MAP_FILE=$(find / -type d -name 'catkin_ws')/maps/map.yaml

xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch" &    
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch" & 
sleep 5
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch"