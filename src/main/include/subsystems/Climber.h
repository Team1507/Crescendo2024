#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <rev/CANSparkMax.h>
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/DigitalInput.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

    void ClimberInit(void);

    void ClimberSetPower(double power);

    void ClimberBrakeEngage(void);
    void ClimberBrakeDisengage(void);

    bool IsClimberTopLimitSwitch(void);
    bool IsClimberBotLimitSwitch(void);

    bool IsClimberEngaged(void);

    bool IsClimberBrakeEngaged(void);

  void Periodic() override;

 private:

  //Climber motors: Brushed 775pro
  rev::CANSparkMax    m_leftClimbMotor    {CLIMBER_LEFT_CANID, rev::CANSparkMax::MotorType::kBrushed};
  rev::CANSparkMax    m_rightClimbMotor   {CLIMBER_RIGHT_CANID, rev::CANSparkMax::MotorType::kBrushed};

  //Limit Switch linked to left motor
  rev::SparkLimitSwitch m_forwardLimit = m_leftClimbMotor.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);
  rev::SparkLimitSwitch m_reverseLimit = m_leftClimbMotor.GetReverseLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);
  
  frc::DoubleSolenoid m_climbBrake        {PCM_CANID, frc::PneumaticsModuleType::REVPH, CLIMBER_BRAKE_ENGAGE_PCM, CLIMBER_BRAKE_DISENGAGE_PCM};
  // frc::DigitalInput   m_topLimitSwitch    {0};
  // frc::DigitalInput   m_botLimitSwitch    {0};

  bool                m_isClimberActivated;
  bool                m_isClimberBrakeActivated;
 
};
