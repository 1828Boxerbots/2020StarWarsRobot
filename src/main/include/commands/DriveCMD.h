/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveTrainSubsystemBase.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveCMD
    : public frc2::CommandHelper<frc2::CommandBase, DriveCMD> {
 public:
  DriveCMD(DriveTrainSubsystemBase *drive, std::function<double()> x, std::function<double()> y);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

    DriveTrainSubsystemBase* m_pDriveTrain;
    std::function<double()> m_x;
    std::function<double()> m_y;
};
