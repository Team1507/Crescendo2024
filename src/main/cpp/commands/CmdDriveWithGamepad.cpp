// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>

#include "Robot.h"
#include "commands/CmdDriveWithGamepad.h"
#include <cmath>

CmdDriveWithGamepad::CmdDriveWithGamepad() 
{

  m_max_loop_time = -1.0;
  m_min_loop_time =  1.0;

  SetName("CmdDriveWithGamepad");
  AddRequirements( &robotContainer.m_drivetrain );
}


void CmdDriveWithGamepad::Initialize() 
{
  std::cout<<"Starting CmdDriveWithGamepad"<<std::endl;


}

//Running in Velocity Mode
void CmdDriveWithGamepad::Execute() 
{

  //
  float loop_start_time = (float)frc::Timer::GetFPGATimestamp();

  //Get Gamepad input;
  float leftY  = robotContainer.m_botDriver.GetLeftY();
  float leftX  = robotContainer.m_botDriver.GetLeftX();
  float rightX = robotContainer.m_botDriver.GetRightX();

  bool  leftBumper  = robotContainer.m_botDriver.GetLeftBumper();
  bool  rightBumper = robotContainer.m_botDriver.GetRightBumper();

  float rightTrigger = robotContainer.m_botDriver.GetRightTriggerAxis();




  const float xyMaxVelocity = 19600; //
  const float rMaxVelocity  = 13000; //

  const float DEADBAND  = 0.10;

  //Default normal drive power
  float xyScaleValue  = 0.7;
  float rScaleValue   = 0.7;  



  // //Square Inputs???
  // leftY  = ( leftY  < 0 ) ? -pow(  leftY,  2) : pow(  leftY,  2);
  // leftX  = ( leftX  < 0 ) ? -pow(  leftX,  2) : pow(  leftX,  2);
  // rightX = ( rightX < 0 ) ? -pow( rightX,  2) : pow( rightX,  2);

  // Re-apply deadband - bad controller
  //Apply DeadBand
  if (fabs(leftY)  < DEADBAND) leftY  = 0;
  if (fabs(leftX)  < DEADBAND) leftX  = 0;
  if (fabs(rightX) < DEADBAND) rightX = 0;

  //Subtract off deadband for smooth transition 
  if (fabs(leftY) >= DEADBAND) leftY  +=   (leftY>0)? -DEADBAND : +DEADBAND;
  if (fabs(leftX) >= DEADBAND) leftX  +=   (leftX>0)? -DEADBAND : +DEADBAND;
  if (fabs(rightX)>= DEADBAND) rightX +=  (rightX>0)? -DEADBAND : +DEADBAND;

  //Creep/Comb the Desert mode
  if( leftBumper )     
  {
    xyScaleValue  = 0.2;
    rScaleValue   = 0.2;  
  }

  //Turbo/ludicrous mode
  if( rightBumper )     
  {
    xyScaleValue  = 0.9;
    rScaleValue   = 0.9;  
  }

  //Apply max velocity and scaling
  float fwdrev    = -(leftY  * xyMaxVelocity * xyScaleValue);    //Invert Axis, make positive forward
  float rightleft =  (leftX  * xyMaxVelocity * xyScaleValue);    
  float rotate    = -(rightX * rMaxVelocity  * rScaleValue);     //Invert Axis, make positive CCW



  //Use PhotonVision to aim, overwriting rotate parameter
  if( rightTrigger > 0.9 )
  {
    float delta_angle = robotContainer.m_photonvision.GetTargetYaw();
    float turn_Velocity = delta_angle * 200.0;

    if( turn_Velocity >  2000.0 ) turn_Velocity =  2000.0;
    if( turn_Velocity < -2000.0 ) turn_Velocity = -2000.0;
    
    rotate = -turn_Velocity;
  }


  if( robotContainer.m_drivetrain.GetDriveType() == Drivetrain::ROBOTCENTRIC )
    robotContainer.m_drivetrain.RobotcentricDriveVelocity( fwdrev,  rightleft,  rotate );
  else
    robotContainer.m_drivetrain.FieldcentricDriveVelocity( fwdrev,  rightleft,  rotate );


  float loop_time = (float)frc::Timer::GetFPGATimestamp() - loop_start_time;

  if( loop_time > m_max_loop_time ) m_max_loop_time = loop_time;
  if( loop_time < m_min_loop_time ) m_min_loop_time = loop_time;

  frc::SmartDashboard::PutNumber("Loop Max", m_max_loop_time);
  frc::SmartDashboard::PutNumber("Loop Min", m_min_loop_time);

  // frc::SmartDashboard::PutNumber("DrvleftY", leftY);
  // frc::SmartDashboard::PutNumber("DrvleftX", leftX);
  // frc::SmartDashboard::PutNumber("DrvrightX", rightX);

}


void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}

bool CmdDriveWithGamepad::IsFinished() 
{
  return false;
}
