#include "commands/CmdWaitShooterSpeed.h"
#include "Robot.h"
#include <iostream>
CmdWaitShooterSpeed::CmdWaitShooterSpeed() 
{
  AddRequirements(&robotContainer.m_shooter);
}


void CmdWaitShooterSpeed::Initialize() 
{
  std::cout <<"Shooter Is Waiting... Any Day Now" << std::endl;
  m_timer.Reset();
  m_timer.Start();
}

void CmdWaitShooterSpeed::Execute() 
{

}

void CmdWaitShooterSpeed::End(bool interrupted) 
{
  std::cout <<"Shooter Is Done Waiting :)" <<std::endl;
  m_timer.Stop();
}

bool CmdWaitShooterSpeed::IsFinished()
{
 const units::second_t timeout = units::second_t(0.65); 
 return m_timer.Get() >= timeout;
}
