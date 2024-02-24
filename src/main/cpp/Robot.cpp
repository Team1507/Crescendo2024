#include "Robot.h"

#include <frc2/command/CommandScheduler.h>
#include <frc/DriverStation.h>

RobotContainer robotContainer; // <--- global variable

void WriteToSmartDashboard(void);
void CheckAlliance( void );

void Robot::RobotInit() 
{
  //*************************** INIT ******************************
  std::cout<<"RobotInit"<<std::endl;
  std::cout<<"FRC2024: Decibel"<<std::endl;
  std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 

  //Drivetrain Init
  robotContainer.m_drivetrain.Stop();
  robotContainer.m_drivetrain.HardResetDriveEncoders();
  robotContainer.m_drivetrain.ResetSteerEncoders();
  robotContainer.m_drivetrain.ZeroGyro(); 
  robotContainer.m_drivetrain.ResetOdometry();

  //Subsystem Initialization
  robotContainer.m_shooter.ResetPivotEncoder(0);  // Need to fix
  CheckAlliance();


}

void Robot::RobotPeriodic()
{
  frc2::CommandScheduler::GetInstance().Run();
  WriteToSmartDashboard();
}


void Robot::DisabledInit() 
{
  std::cout<<"Disabled Init"<<std::endl;
}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() 
{
  std::cout<<" **** Auto Init ******"<<std::endl;
  m_autonomousCommand = robotContainer.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
  std::cout<<"Teleop Init"<<std::endl;
  if (m_autonomousCommand) {
      m_autonomousCommand->Cancel();
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif





void WriteToSmartDashboard(void)
{


  //XBox Controllers
  frc::SmartDashboard::PutNumber("Xbox Left-Y",   robotContainer.m_botDriver.GetLeftY()    ); 
  frc::SmartDashboard::PutNumber("Xbox Left-X",   robotContainer.m_botDriver.GetLeftX()    ); 
  frc::SmartDashboard::PutNumber("Xbox Right-X",  robotContainer.m_botDriver.GetRightX()   ); 


  //Nax-X
  frc::SmartDashboard::PutBoolean("navx_IsConn",  robotContainer.m_drivetrain.IsGyroConnected() );
  frc::SmartDashboard::PutNumber("navx_Yaw",      robotContainer.m_drivetrain.GetGyroYaw()      );
  frc::SmartDashboard::PutNumber("navx_Angle",    robotContainer.m_drivetrain.GetGyroAngle()    );

  //Odometry
  frc::SmartDashboard::PutNumber("odo_X",         robotContainer.m_drivetrain.GetOdometryX()       );
  frc::SmartDashboard::PutNumber("odo_Y",         robotContainer.m_drivetrain.GetOdometryY()       );
  frc::SmartDashboard::PutNumber("odo_H",         robotContainer.m_drivetrain.GetOdometryHeading() );

  //Time
  frc::SmartDashboard::PutNumber("MatchTime",  (double)robotContainer.m_timer.GetMatchTime() );       //Match Time



}



void CheckAlliance( void )
{

  //Set Panel LEDs
  if( frc::DriverStation::GetAlliance() == frc::DriverStation::kRed)
  {
      std::cout << "RED Alliance" << std::endl;
  }
  else if(frc::DriverStation::GetAlliance() == frc::DriverStation::kBlue)
  {
      std::cout << "BLUE Alliance" << std::endl;
  }
  else
  {
     std::cout << "UNKNOWN Alliance" << std::endl;
  }

}

