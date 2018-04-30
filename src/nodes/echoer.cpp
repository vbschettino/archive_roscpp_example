//
// Created by vinicius on 4/25/18.
//

#include "roscpp_example/base.h"

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"

//This is the wrapper class around the base, non-ros, library.
class EchoerROS : public Echoer {
public:
    //Constructor (see note bellow)
    using Echoer::Echoer; //inherit constructors from base class with default arguments; needs c++11 support

    //Subscribers
    void listenROS(const std_msgs::String::ConstPtr &rosmsg){ //wrapper callback around base function
        string msg = rosmsg->data;
        listen(msg);
        makeEcho();
        ROS_INFO("%s%s", "I heard: ", msg.data());
    }

    //Services
    bool increaseNEchos(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response){
        setNEchos(nEchos+1);
        makeEcho();
        ROS_INFO("%s", "Increasing echos");
        return true;
    }

    bool decreaseNEchos(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response){
        setNEchos(nEchos-1);
        makeEcho();
        ROS_INFO("%s", "Decreasing echos");
        return true;
    }

//NOTE: for full ROS integration, it might be better to set constructor as bellow and remove c++11 flag from CMakeLists
/*explicit EchoerROS () {}
explicit EchoerROS (int nEchos) : Echoer(nEchos, "...", "...") {}*/
};



int main(int argc, char **argv) {
    //Start node
    ros::init(argc, argv, "echoer");
    ros::NodeHandle nh; //public node handle
    ros::NodeHandle pnh("~"); //private node handle, adds nodes name to namespace

    //Get parameters from ROS parameter server
    int nEchos;
    pnh.param<int>("n_echos", nEchos, 5); //number of echos; defaults to 5

    //Start wrapper class with retrieved parameter
    EchoerROS echo_maker{nEchos};

    //Start subscribers, publishers and services
    ros::Subscriber listen_sub = nh.subscribe<std_msgs::String>("listen", 100, &EchoerROS::listenROS, &echo_maker);

    ros::Publisher echo_pub = nh.advertise<std_msgs::String>("echo", 100);

    ros::ServiceServer service1 = pnh.advertiseService("increase_echos", &EchoerROS::increaseNEchos, &echo_maker);

    ros::ServiceServer service2 = pnh.advertiseService("decrease_echos", &EchoerROS::decreaseNEchos, &echo_maker);

    //Loop at predefined rate
    ros::Rate loop_rate(1); //run at 1 Hz
    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = echo_maker.shout();

        echo_pub.publish(msg);
        ROS_INFO("%s", msg.data.c_str());

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}