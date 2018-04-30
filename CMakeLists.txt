cmake_minimum_required(VERSION 2.8.3)
project(roscpp_example)

add_compile_options(-std=c++11) #If full ROS integration is aimed, avoid this. See echoer.cpp for alternative

find_package(catkin REQUIRED COMPONENTS
  roscpp
#  std_msgs #why isn't this needed?
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES roscpp_example
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Either this
## (preferred?: http://docs.ros.org/api/catkin/html/howto/format2/building_executables.html)
## if this is used then no library will be exported and you can comment first 3 lines inside the catkin_package() call
add_executable(echoer src/nodes/echoer.cpp src/base.cpp)
target_link_libraries(echoer ${catkin_LIBRARIES})

## Or this
#add_library(roscpp_example src/base.cpp)
#add_executable(echoer src/nodes/echoer.cpp)
#target_link_libraries(echoer ${catkin_LIBRARIES} roscpp_example)