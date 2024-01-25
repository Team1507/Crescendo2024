#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Climber.h"

#include <frc/XboxController.h>

class RobotContainer
{
 public:
  RobotContainer();

  frc::XboxController m_botDriver{0};
  frc::XboxController m_topDriver{1};

  Climber m_climber;

  frc2::CommandPtr GetAutonomousCommand();

 private:
  
  ExampleSubsystem m_subsystem;

  void ConfigureBindings();
};
