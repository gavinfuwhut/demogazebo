#include "ros/ros.h"
#include "std_msgs/Float64.h" 
#include <sstream>

int main(int argc, char  *argv[])
{   
    setlocale(LC_ALL,"");//防止显示中文乱码
    ros::init(argc,argv,"control_gazebo_demo");//节点初始化
    ros::NodeHandle nh;
    //创建发布者对象话题为/gazebo_demo/joint1_position_controller/command
    ros::Publisher pub = nh.advertise<std_msgs::Float64>("/gazebo_demo/joint1_position_controller/command",10);
    std_msgs::Float64 control_gazebo_demo;
    control_gazebo_demo.data=0.0;
    bool flag=0;//0weizeng 1weijian
    ros::Rate r(200);//控制频率1s发布200次

    while (ros::ok())
    {
        
        for(control_gazebo_demo.data=0.0;control_gazebo_demo.data<=1.5;control_gazebo_demo.data+=0.01)
        {
		pub.publish(control_gazebo_demo);

		ROS_INFO("发送的消息:%f",control_gazebo_demo);
		r.sleep();
        }

        for(control_gazebo_demo.data=1.5;control_gazebo_demo.data>=0.0;control_gazebo_demo.data-=0.01)
        {
		pub.publish(control_gazebo_demo);

		ROS_INFO("发送的消息:%f",control_gazebo_demo);
		r.sleep();
        }
       

        
        ros::spinOnce();
    }
    return 0;
}
