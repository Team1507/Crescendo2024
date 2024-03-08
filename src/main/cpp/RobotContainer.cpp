#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterCalculateShot.h"
#include "commands/CmdAmpEject.h"
#include "commands/CmdAmpIntake.h"
#include "commands/CmdAmpSetAngle.h"
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
#include "commands/CmdShooterDPad.h"
#include "commands/CmdDriveForcePark.h"
#include "commands/CmdIntakeDefault.h"
#include "commands/CmdShooterSourceLoad.h"
#include "commands/CmdAmperatusDefault.h"
#include "commands/CmdAmpTrapDeploy.h"
#include "commands/CmdAmpTrapRetract.h"
#include "commands/CmdDriverDPad.h"

//Autos
#include "commands/AutoDoNothing.h"
#include "commands/AutoRedFourPieceMiddle.h"
#include "commands/AutoRedThreePieceRight.h"
#include "commands/AutoRedFourPieceRight.h"
#include "commands/AutoJustShoot.h"



RobotContainer::RobotContainer() 
{

  //******************** Subsystem Defaults ******************************
  m_drivetrain.SetDefaultCommand(  CmdDriveWithGamepad());
  m_shooter.SetDefaultCommand   (  CmdShooterDefault());
  m_intake.SetDefaultCommand    (  CmdIntakeDefault());
  m_amperatus.SetDefaultCommand (  CmdAmperatusDefault());

  //******************** Dashboard Buttons *******************************
  frc::SmartDashboard::PutData( "CmdDriveTypeToggle",    new CmdDriveTypeToggle());
  frc::SmartDashboard::PutData( "CmdDriveClearAll",      new CmdDriveClearAll());
  frc::SmartDashboard::PutData( "GrpTest1",              new GrpTest1());
  frc::SmartDashboard::PutData( "GrpTest2",              new GrpTest2());
  frc::SmartDashboard::PutData( "AmpTrapDeploy",         new CmdAmpTrapDeploy());
  frc::SmartDashboard::PutData( "AmpTrapRetract",        new CmdAmpTrapRetract());


  //Smartdashboard SwerveDrive test/calibration buttons
  frc::SmartDashboard::PutData( "SteerAngle=0",          new CmdDriveForceSteerAngle( 0.0));
  frc::SmartDashboard::PutData( "SteerAngle=90",         new CmdDriveForceSteerAngle( 90.0));
  frc::SmartDashboard::PutData( "CmdCalSwerveEnc_1",     new CmdCalibrateSwerveEncoders(&m_drivetrain, 1));
  frc::SmartDashboard::PutData( "CmdCalSwerveEnc_2",     new CmdCalibrateSwerveEncoders(&m_drivetrain, 2));



  //*************************************Auto**********************************************

  m_chooser.AddOption("Auto Do Nothing",           new AutoDoNothing() );

  m_chooser.AddOption("Auto Just Shoot",           new AutoJustShoot());
  
  m_chooser.SetDefaultOption("Auto Do Nothing",    new AutoDoNothing() );

  frc::SmartDashboard::PutData("Auto Mode", &m_chooser);
  
  //Red Autos
  m_chooser.AddOption("Four Piece Red Middle",     new AutoRedFourPieceMiddle());


  m_chooser.AddOption("Three Piece Right Red",     new AutoRedThreePieceRight);

  m_chooser.AddOption("Four Piece Right Red",      new AutoRedFourPieceRight());

  //Blue Autos

  

  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  m_topDriver_RightBumper.OnTrue(new CmdIntakeDeploy());
  m_topDriver_RightBumper.OnFalse(new CmdIntakeRetract()); 

  m_topDriver_YButton.OnTrue(new CmdShooterSourceLoad());
  
   m_topDriver_XButton.WhileTrue(new CmdAmpIntake(0)); //amp intake

   m_topDriver_BButton.WhileTrue(new CmdAmpEject(0)); //amp eject

   m_topDriver_LeftBumper.OnTrue(new CmdAmpSetAngle()); //amp up
   m_topDriver_LeftBumper.OnFalse(new CmdAmpSetAngle()); //amp down

  m_topDriver_BackButton.WhileTrue(new CmdClimberClimb()); //climber climb

  m_topDriver_StartButton.OnTrue(new CmdAmpTrapDeploy());

  m_topDriver_POVup.OnTrue(    new CmdShooterDPad( DPAD_UP   ) );
  m_topDriver_POVdown.OnTrue(  new CmdShooterDPad( DPAD_DOWN ) );
  m_topDriver_POVleft.OnTrue(  new CmdShooterDPad( DPAD_LEFT ) );
  m_topDriver_POVright.OnTrue( new CmdShooterDPad( DPAD_RIGHT) );

 
  //Bottom Driver Mapped buttons
  m_botDriver_StartButton.OnTrue(new CmdDriveZeroGyro());           //Zero Gyro
  m_botDriver_YButton.OnTrue(new CmdDriveForceSteerAngle( 90.0));   //Straighten drive wheels
  m_botDriver_BButton.OnTrue(new CmdDriveForcePark()); 


  m_botDriver_POVup.OnTrue(    new CmdDriverDPad( DPAD_UP   ) );
  m_botDriver_POVdown.OnTrue(  new CmdDriverDPad( DPAD_DOWN ) );
  m_botDriver_POVleft.OnTrue(  new CmdDriverDPad( DPAD_LEFT ) );
  m_botDriver_POVright.OnTrue( new CmdDriverDPad( DPAD_RIGHT) );


}

frc2::Command* RobotContainer::GetAutonomousCommand() 
{
  return m_chooser.GetSelected();
}
