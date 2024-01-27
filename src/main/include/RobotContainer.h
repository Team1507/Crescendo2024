#pragma once

#include <frc2/command/CommandPtr.h>

#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"

#include <frc/XboxController.h>

class RobotContainer
{
 public:
  RobotContainer();

  frc::XboxController m_botDriver{0};
  frc::XboxController m_topDriver{1};

  Climber m_climber;
  Intake  m_intake;
  Shooter m_shooter;

  frc2::CommandPtr GetAutonomousCommand();

 private:
  
  ExampleSubsystem m_subsystem;

  frc2::JoystickButton m_topDriver_LeftBumper{&m_topDriver,frc::XboxController::Button::kLeftBumper};
  
  void ConfigureBindings();
};
