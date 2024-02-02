#include "Robot.h"

#include <frc2/command/CommandScheduler.h>

RobotContainer robotContainer; // <--- global variable

void Robot::RobotInit() {}

void Robot::RobotPeriodic()
{
  frc2::CommandScheduler::GetInstance().Run();
}


void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit() 
{
  m_autonomousCommand = robotContainer.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
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
