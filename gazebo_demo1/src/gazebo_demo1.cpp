#include "ros/ros.h"
#include "std_msgs/Float64.h" 
#include <sstream>
 

int main(int argc, char  *argv[])
{   
    setlocale(LC_ALL,"");//防止中文乱码
    ros::init(argc,argv,"bengine_gazebo_demo1");//初始化ros节点
    ros::NodeHandle nh;
    //创建发布者对象
    ros::Publisher pub_lf = nh.advertise<std_msgs::Float64>("/bengine/LF_position_controller/command",10);
    ros::Publisher pub_lb = nh.advertise<std_msgs::Float64>("/bengine/LB_position_controller/command",10);
    ros::Publisher pub_rf = nh.advertise<std_msgs::Float64>("/bengine/RF_position_controller/command",10);
    ros::Publisher pub_rb = nh.advertise<std_msgs::Float64>("/bengine/RB_position_controller/command",10);
    //组织数据
    std_msgs::Float64 control_gazebo_demo1;
    control_gazebo_demo1.data=0.0;
    bool flag=0;//0weizeng 1weijian
    ros::Rate r(50);//消息发布频率
    while (ros::ok())
    {
        //发布消息使四个关节匀速转动
        pub_lf.publish(control_gazebo_demo1);
        pub_lb.publish(control_gazebo_demo1);
        pub_rf.publish(control_gazebo_demo1);
        pub_rb.publish(control_gazebo_demo1);
        control_gazebo_demo1.data+=0.1;
        r.sleep();
        
        ros::spinOnce();
    }
    return 0;
}
