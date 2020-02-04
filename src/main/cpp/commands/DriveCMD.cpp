/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveCMD.h"

DriveCMD::DriveCMD(DriveTrainSubsystemBase *drive, std::function<double()> x, std::function<double()> y) : m_pDriveTrain{drive}, m_y{y}, m_x{x}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(drive);
}

// Called when the command is initially scheduled.
void DriveCMD::Initialize()
{
  m_pDriveTrain->Stop();
  m_pDriveTrain->Init();
}

// Called repeatedly when this Command is scheduled to run
void DriveCMD::Execute() 
{
  m_pDriveTrain->MoveArcade(m_x(),m_y());
}

// Called once the command ends or is interrupted.
void DriveCMD::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCMD::IsFinished() { return false; }
