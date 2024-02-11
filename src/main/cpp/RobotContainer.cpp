#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterCalculateShot.h"
#include "commands/CmdAmpEject.h"
#include "commands/CmdAmpIntake.h"
#include "commands/CmdAmpSetAngle.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdClimberClimb.h"
#include "commands/CmdDriveWithGamepad.h"
#include "commands/CmdDriveTypeToggle.h"
#include "commands/CmdCalibrateSwerveEncoders.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/GrpTest1.h"
#include "commands/GrpTest2.h"
#include "commands/CmdDriveZeroGyro.h"
#include "commands/CmdDriveAimAtTarget.h"
#include "commands/CmdShooterDefault.h"

//Autos
#include "commands/AutoDoNothing.h"
#include "commands/AutoTwoPieceBlueOne.h"
#include "commands/AutoTwoPieceRedOne.h"





RobotContainer::RobotContainer() 
{

  //******************** Subsystem Defaults ******************************
  m_drivetrain.SetDefaultCommand( CmdDriveWithGamepad() );
  m_shooter.SetDefaultCommand(    CmdShooterDefault()   );



  //******************** Dashboard Buttons *******************************
  frc::SmartDashboard::PutData( "CmdDriveTypeToggle",    new CmdDriveTypeToggle());
  frc::SmartDashboard::PutData( "CmdDriveClearAll",      new CmdDriveClearAll());
  frc::SmartDashboard::PutData( "GrpTest1",              new GrpTest1());
  frc::SmartDashboard::PutData( "GrpTest2",              new GrpTest2());


  //Smartdashboard SwerveDrive test/calibration buttons
  frc::SmartDashboard::PutData( "SteerAngle=0",          new CmdDriveForceSteerAngle( 0.0));
  frc::SmartDashboard::PutData( "SteerAngle=90",         new CmdDriveForceSteerAngle( 90.0));
  frc::SmartDashboard::PutData( "CmdCalSwerveEnc_1",     new CmdCalibrateSwerveEncoders(&m_drivetrain, 1));
  frc::SmartDashboard::PutData( "CmdCalSwerveEnc_2",     new CmdCalibrateSwerveEncoders(&m_drivetrain, 2));



  //*************************************Auto**********************************************

  m_chooser.AddOption("Auto Do Nothing",           new AutoDoNothing() );

  //Blue Autos
  m_chooser.AddOption("Blue-AutoTwoPieceBlueOne",  new AutoTwoPieceBlueOne() );

  //Red Autos
  m_chooser.AddOption("Red-AutoTwoPieceRedOne",    new AutoTwoPieceRedOne() );



  m_chooser.SetDefaultOption("Auto Do Nothing",    new AutoDoNothing() );

  frc::SmartDashboard::PutData("Auto Mode", &m_chooser);

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  m_topDriver_LeftBumper.OnTrue(new CmdIntakeDeploy());
  m_topDriver_LeftBumper.OnFalse(new CmdIntakeRetract()); 
  
  m_topDriver_XButton.WhileTrue(new CmdAmpIntake(0.3)); //amp intake

  m_topDriver_BButton.OnTrue(new CmdAmpEject(-0.5)); //amp eject
  m_topDriver_BButton.OnFalse(new CmdAmpEject(0.0)); //amp eject stop

  m_topDriver_RightBumper.OnTrue(new CmdAmpSetAngle()); //amp up
  m_topDriver_RightBumper.OnFalse(new CmdAmpSetAngle()); //amp down

  m_topDriver_BackButton.WhileTrue(new CmdClimberClimb()); //climber climb

  //Bottom Driver Mapped buttons
  m_botDriver_StartButton.OnTrue(new CmdDriveZeroGyro());           //Zero Gyro
  m_botDriver_YButton.OnTrue(new CmdDriveForceSteerAngle( 90.0));   //Straighten drive wheels


}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return m_chooser.GetSelected();
}
