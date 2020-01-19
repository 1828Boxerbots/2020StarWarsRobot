/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Spike.h"

Spike::Spike() {}

// This method will be called once per scheduler run
void Spike::Periodic() {}


void Spike::TurnLightsOn() 
{
    m_spike.Set(Relay::kForward);
}

void Spike::TurnLightsOff() 
{
    m_spike.Set(Relay::kOff);
}