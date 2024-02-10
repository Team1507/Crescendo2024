#pragma once

#include <frc2/command/CommandPtr.h>

#include "commands/AutoDoNothing.h"
#include "Constants.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Amperatus.h"
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SmartDashboard.h>


class RobotContainer
{
 public:
  RobotContainer();

  frc::XboxController m_botDriver{0};
  frc::XboxController m_topDriver{1};

  Shooter   m_shooter;
  Climber   m_climber;
  Intake    m_intake;
  Amperatus m_amperatus;
  frc2::CommandPtr GetAutonomousCommand();

  AutoDoNothing m_autoDoNothing{};

 private:

  //frc::SendableChooser<frc2::CommandPtr> m_chooser;
  
  frc2::JoystickButton m_topDriver_LeftBumper{&m_topDriver,frc::XboxController::Button::kLeftBumper};

  frc2::JoystickButton m_topDriver_XButton{&m_topDriver,frc::XboxController::Button::kX};
  frc2::JoystickButton m_topDriver_BButton{&m_topDriver,frc::XboxController::Button::kB};

  frc2::JoystickButton m_topDriver_RightBumper{&m_topDriver,frc::XboxController::Button::kRightBumper};

  frc2::JoystickButton m_topDriver_BackButton{&m_topDriver,frc::XboxController::Button::kBack};

  void ConfigureBindings();
};
