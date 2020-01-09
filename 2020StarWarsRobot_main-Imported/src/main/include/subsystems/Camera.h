/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <cameraserver/CameraServer.h>
using namespace frc;
using namespace cv;


class Camera : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  cv::Mat m_frame; 
  VideoCapture m_camera;
  
  cs::CvSource source = CameraServer::GetInstance()->PutVideo("test",640,480);
  cs::CvSink sink = CameraServer::GetInstance()->GetVideo();
  //cs::UsbCamera m_cam = CameraServer::GetInstance()->StartAutomaticCapture();
 public:
  Camera();
  void InitDefaultCommand() override;
  void startCamera();
  void TakeFrame();

  
};
