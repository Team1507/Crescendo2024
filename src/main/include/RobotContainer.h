#pragma once

#include <frc2/command/CommandPtr.h>


#include "Constants.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Amperatus.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/PhotonVision.h"
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>




class RobotContainer
{
 public:
  RobotContainer();

  //****************Controllers*******************
  frc::XboxController m_botDriver{0};
  frc::XboxController m_topDriver{1};


  //****************Subsystems*******************
  Shooter      m_shooter;
  Climber      m_climber;
  Intake       m_intake;
  Amperatus    m_amperatus;
  Drivetrain   m_drivetrain;
  PhotonVision m_photonvision;


  frc::Timer   m_timer;
  frc2::Command* GetAutonomousCommand();

 private:
  //Top Driver Buttons
  frc2::JoystickButton m_topDriver_LeftBumper {&m_topDriver,frc::XboxController::Button::kLeftBumper};
  frc2::JoystickButton m_topDriver_XButton    {&m_topDriver,frc::XboxController::Button::kX};
  frc2::JoystickButton m_topDriver_BButton    {&m_topDriver,frc::XboxController::Button::kB};
  frc2::JoystickButton m_topDriver_RightBumper{&m_topDriver,frc::XboxController::Button::kRightBumper};
  frc2::JoystickButton m_topDriver_BackButton {&m_topDriver,frc::XboxController::Button::kBack};


  //Bottom Driver Buttons
  frc2::JoystickButton m_botDriver_StartButton{&m_botDriver, frc::XboxController::Button::kStart };
  frc2::JoystickButton m_botDriver_YButton    {&m_botDriver, frc::XboxController::Button::kY };
  frc2::JoystickButton m_botDriver_BButton    {&m_botDriver, frc::XboxController::Button::kB };



  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureBindings();
};
