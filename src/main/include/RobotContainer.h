#pragma once

#include <frc2/command/CommandPtr.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Amperatus.h"
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
  Amperatus m_amperatus;
  frc2::CommandPtr GetAutonomousCommand();

 private:
  
  ExampleSubsystem m_subsystem;

  frc2::JoystickButton m_topDriver_LeftBumper{&m_topDriver,frc::XboxController::Button::kLeftBumper};

  frc2::JoystickButton m_topDriver_LeftTrigger{&m_topDriver,frc::XboxController::Axis::kLeftTrigger};

  frc2::JoystickButton m_topDriver_XButton{&m_topDriver,frc::XboxController::Button::kX};
  frc2::JoystickButton m_topDriver_BButton{&m_topDriver,frc::XboxController::Button::kB};

  frc2::JoystickButton m_topDriver_RightBumper{&m_topDriver,frc::XboxController::Button::kRightBumper};

  frc2::JoystickButton m_topDriver_RightTrigger{&m_topDriver,frc::XboxController::Axis::kRightTrigger};
  // frc2::JoystickButton m_topDriver_RightTrigger{&m_topDriver,frc::XboxController::POV::};

  void ConfigureBindings();
};
