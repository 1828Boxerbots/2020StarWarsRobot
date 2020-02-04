/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/RunCommand.h>

#include <frc/XboxController.h>

#include "commands/ExampleCommand.h"
#include "commands/CameraCMD.h"
#include "commands/DriveCMD.h"
#include "subsystems/CameraSubsystem.h"
#include "subsystems/ColorDetection.h"
#include "subsystems/DistanceFinder.h"
#include "subsystems/DriveTrainSubsystemBase.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Hook.h"
#include "subsystems/Joint.h"
#include "subsystems/PickUp.h"
#include "subsystems/Shooter.h"
#include "subsystems/Spike.h"
#include "subsystems/Spinner.h"
#include "subsystems/Vision.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  frc::XboxController m_controller{0};
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  frc::XboxController m_xboxController{CONTROLLER};

  ColorDetection m_colorDetection;
  DistanceFinder m_distanceFinder;
  
  DriveTrainSubsystemBase m_drivetrain;
  Hook m_hook;
  Joint m_joint;
  PickUp m_pickUp;
  Shooter m_shooter;
  Spike m_spike;
  Spinner m_spinner;
  Vision m_vision;
  CameraSubsystem m_camera;
  
  CameraCMD m_cameraCMD{&m_camera};
  DriveCMD m_driveCMD{&m_drivetrain, m_controller.GetX(GenericHID::kLeftHand), m_controller.GetY(GenericHID::kLeftHand)};
  frc2::RunCommand m_turnLightsOn {[this] {m_spike.TurnLightsOn() ;}, {&m_spike}};
  frc2::RunCommand m_turnLightsOff{[this] {m_spike.TurnLightsOff();}, {&m_spike}};

  void ConfigureButtonBindings();
};
