#include "ros/ros.h"
#include "det_matrix_service/det_matrix_service.h"
#include <iostream>

int main(int argc, char **argv) {

  ros::init(argc, argv, "find_det_matrix_client");
  
  ros::NodeHandle nh;

  ros::ServiceClient client = nh.serviceClient<det_matrix_service::det_matrix_service>("det_matrix_3");
  det_matrix_service::det_matrix_service srv;
  
  while (ros::ok()) {
  	int a1, b1, c1, a2, b2, c2, a3, b3, c3;
  	std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;
  	
  	srv.request.row1_column1 = a1;
  	srv.request.row1_column2 = b1;
  	srv.request.row1_column3 = c1;
  	srv.request.row2_column1 = a2;
  	srv.request.row2_column2 = b2;
  	srv.request.row2_column3 = c2;
  	srv.request.row3_column1 = a3;
  	srv.request.row3_column2 = b3;
  	srv.request.row3_column3 = c3;
  	
  	if (client.call(srv)) {
  		if (srv.response.det_matrix/2 == round(srv.response.det_matrix/2))
  		{
  			ROS_INFO ("even");
  		}
  		else
  		{
  			ROS_INFO ("odd");
  		}
  		
  	}
  	else {
  		ROS_INFO ("Failed to call service det_matrix_3");
  		return 1;
  	}
  }
  	
  return 0;
}
