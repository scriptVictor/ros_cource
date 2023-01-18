#include "ros/ros.h"
#include "det_matrix_service/det_matrix_service.h"

bool find_det_matrix(det_matrix_service::det_matrix_service::Request &req,
  det_matrix_service::det_matrix_service::Response &res)
{
  
  res.det_matrix = req.row1_column1*(req.row2_column2*req.row3_column3-req.row2_column3*req.row3_column2)
  -req.row1_column2*(req.row2_column1*req.row3_column3-req.row3_column1*req.row2_column3)
  +req.row1_column3*(req.row2_column1*req.row3_column2-req.row2_column2*req.row3_column1);
  
  if (res.det_matrix/2 == round(res.det_matrix/2))
  {
  	ROS_INFO ("even");
  }
  else
  {
  	ROS_INFO ("odd");
  }

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "find_det_matrix_server");
  ros::NodeHandle nh;

  ros::ServiceServer service = nh.advertiseService("det_matrix_3", find_det_matrix);
 
  ros::spin();

  return 0;
}
