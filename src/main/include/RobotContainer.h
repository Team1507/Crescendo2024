#pragma once

#include <frc2/command/CommandPtr.h>


#include "Constants.h"
#include "subsystems/Climber.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Amperatus.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/PhotonVision.h"
#include "subsystems/DriverFeedback.h"

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <frc2/command/button/POVButton.h>
#include "subsystems/DriverFeedback.h"



class RobotContainer
{
 public:
  RobotContainer();

  //****************Controllers*******************
  frc::XboxController m_botDriver{0};
  frc::XboxController m_topDriver{1};


  //****************Subsystems*******************
  Shooter        m_shooter;
  Climber        m_climber;
  Intake         m_intake;
  Amperatus      m_amperatus;
  Drivetrain     m_drivetrain;
  //PhotonVision   m_photonvision;
  DriverFeedback m_driverfeedback;


  frc::Timer   m_timer;
  frc2::Command* GetAutonomousCommand();

 private:
  //Top Driver Buttons
  frc2::JoystickButton m_topDriver_LeftBumper {&m_topDriver,frc::XboxController::Button::kLeftBumper};
  frc2::JoystickButton m_topDriver_XButton    {&m_topDriver,frc::XboxController::Button::kX};
  frc2::JoystickButton m_topDriver_BButton    {&m_topDriver,frc::XboxController::Button::kB};
  frc2::JoystickButton m_topDriver_RightBumper{&m_topDriver,frc::XboxController::Button::kRightBumper};
  frc2::JoystickButton m_topDriver_BackButton {&m_topDriver,frc::XboxController::Button::kBack};
  frc2::JoystickButton m_topDriver_YButton    {&m_topDriver,frc::XboxController::Button::kY};


  frc2::POVButton      m_topDriver_POVup      {&m_topDriver, 0};
  frc2::POVButton      m_topDriver_POVdown    {&m_topDriver, 180};
  frc2::POVButton      m_topDriver_POVleft    {&m_topDriver, 270};
  frc2::POVButton      m_topDriver_POVright   {&m_topDriver, 90};

  //Bottom Driver Buttons
  frc2::JoystickButton m_botDriver_StartButton{&m_botDriver, frc::XboxController::Button::kStart };
  frc2::JoystickButton m_botDriver_YButton    {&m_botDriver, frc::XboxController::Button::kY };
  frc2::JoystickButton m_botDriver_BButton    {&m_botDriver, frc::XboxController::Button::kB };

  frc2::POVButton      m_botDriver_POVup      {&m_botDriver, 0};
  frc2::POVButton      m_botDriver_POVdown    {&m_botDriver, 180};
  frc2::POVButton      m_botDriver_POVleft    {&m_botDriver, 270};
  frc2::POVButton      m_botDriver_POVright   {&m_botDriver, 90};

  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureBindings();
};
