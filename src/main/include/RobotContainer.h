#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include <frc/XboxController.h>

#include <frc2/command/button/JoystickButton.h>

class RobotContainer
{
 public:
  RobotContainer();

  frc::XboxController m_botDriver{0};
  frc::XboxController m_topDriver{1};

  Shooter m_shooter;
  Climber m_climber;
  Intake  m_intake;
  frc2::CommandPtr GetAutonomousCommand();

 private:
  
  ExampleSubsystem m_subsystem;

  void ConfigureBindings();
};
