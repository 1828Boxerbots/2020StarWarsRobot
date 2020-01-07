/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../RobotMap.h"

//#include <frc/Victor.h>

class DriveTrain : public frc::Subsystem {
 //private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;

  //Objects
  /*
  frc::Victor m_motorL {PWM_MOTOR_LEFT};
  frc::Victor m_motorR {PWM_MOTOR_RIGHT};
  */

  //Functions
  virtual void StopMotor(){}
  virtual void ForwardMax(){}
  virtual void BackwardMax(){}
  virtual void Move(double distance){}
  virtual void Turn(double angle){}
  virtual void SideLeft(double distance){}
  virtual void SlideRight(double distance){}
  virtual void SideLeftInSeconds(double time){}
  virtual void SlideRightInSeconds(double time){}
  virtual double GetAngle(){}
  
};
