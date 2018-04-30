# roscpp example
## Rationale behind this package
This is a simple example of a ros package with source files written in C++. The idea is that the folder structure, cmakelists and package.xml files format can be used as template for more complex packages.

As recommended somewhere, the pure C code should be separated from the ROS interface.

## Usage
To serve as an example, the simple node will subscribe to a _listen_ topic and publish an _echo_ topic at a fixed rate with the message repeated _n_ times. Whenever a new message is received in _listen_, the output message will be updated.

_n_ can be chosen by setting a _echoer/n_echos_ parameter on ROS parameter server before running the node. If not set, it defaults to 5. Value of _n_ can be changed during run time by calling the services _increase_echos_ and _decrease_echos_.

To run an example, go to a terminal and issue:

`roslaunch roscpp_example echoer.launch`

Then, on another terminal, issue:

`rostopic pub /listen std_msgs/String "data: 'Hello'"`

To increase number of echos:

`rosservice call echoer/increase_echos`
