cmake_minimum_required(VERSION 2.8.3)

project(gazebo_demo1)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

catkin_package()

find_package(catkin REQUIRED COMPONENTS
  # roslaunch
  # controller_manager
  # gazebo_ros
  # gazebo_ros_control
  # joint_state_publisher
  # robot_state_publisher
  roscpp
  rospy
  # rviz
  # xacro
  # kdl_parser
  # tf
  # sensor_msgs
  std_msgs
  # trac_ik_lib
  # serial
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${orocos_kdl_INCLUDE_DIRS}
)

add_executable(gazebo_demo1 src/gazebo_demo1.cpp)
target_link_libraries(gazebo_demo1 ${catkin_LIBRARIES} ${orocos_kdl_LIBRARIES})

# foreach(dir config launch meshes urdf)
# 	install(DIRECTORY ${dir}/
# 		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
# endforeach(dir)
