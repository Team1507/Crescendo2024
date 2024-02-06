#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/PneumaticsModuleType.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  void   IntakeDeploy(void);
  void   IntakeRetract(void);

  void   IntakeSetPower(double power);

  double IntakeGetPower(void);

  bool   IntakeIsDeployed(void);

  void   Periodic() override;

 private:
  
  rev::CANSparkMax    m_intakeMotor     {INTAKE_MOTOR_CANID, rev::CANSparkMax::MotorType::kBrushless};

  frc::DoubleSolenoid m_intakeDoubleSolenoid {PCM_CAN, frc::PneumaticsModuleType::CTREPCM, INTAKE_DEPLOY_PCM, INTAKE_RETRACT_PCM};
  
  bool                m_isIntaking;

};
