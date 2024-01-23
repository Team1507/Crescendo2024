#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <rev/CANSparkMax.h>
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsModuleType.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

    void ClimberInit(void);

    void ClimberSetPower(double power);

    void ClimberBrakeEngage(void);

    void ClimberBrakeDisengage(void);

    bool IsClimberEngaged(void);

    bool IsClimberBrakeEngaged(void);


 
  void Periodic() override;

 private:

 rev::CANSparkMax m_leftClimbMotor{CLIMBER_LEFT_CANID, rev::CANSparkMax::MotorType::kBrushless};
 rev::CANSparkMax m_rightClimbMotor{CLIMBER_RIGHT_CANID, rev::CANSparkMax::MotorType::kBrushless};

 frc::DoubleSolenoid m_climbBrake{PCM_CAN, frc::PneumaticsModuleType::CTREPCM, CLIMBER_BRAKE_ENGAGE_PCM, CLIMBER_BRAKE_DISENGAGE_PCM};

 bool m_isClimberActivated;
 bool m_isClimberBrakeActivated;
 
};
