/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Camera.h"

Camera::Camera() : Subsystem("ExampleSubsystem") {}

void Camera::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  

}

void Camera::startCamera()
{
   m_camera.open(0);
}



void Camera::TakeFrame()
{
  m_frame = m_camera.grab();
  sink.GrabFrame(m_frame);
  //cv::imshow("test",m_frame);
  source.PutFrame(m_frame);  
  
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
