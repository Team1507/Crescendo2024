#pragma once

#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include "TimeOfFlight.h"

class Amperatus : public frc2::SubsystemBase {
 public:
  Amperatus();

  void   SetAmpPower(double power);

  void   SetAmpAngle(double position);

  // void   ResetAmpEncoder(void);

  void   SetAmpRollerPower(double power);

  void   AmpTrapDeploy(void);

  void   AmpTrapRetract(void);

  double GetAmpPower(void);

  double GetAmpAngle(void);

  double GetAmpRollerPower(void);

  bool   GetAmpPhotoeye(void);

  void   Periodic() override;

 private:

  // frc::DigitalInput         m_ampTopLimit{AMP_UPPER_LIMIT};
  // frc::DigitalInput         m_ampBotLimit{AMP_LOWER_LIMIT};

   rev::CANSparkMax          m_ampRoller{AMP_ROLLER_CANID, rev::CANSparkMax::MotorType::kBrushed};
  // rev::SparkPIDController   m_ampRollerPID     = m_ampRoller.GetPIDController();
  // rev::SparkRelativeEncoder m_ampRollerEncoder = m_ampRoller.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::CANSparkMax          m_ampMotor{AMP_MOTOR_CANID, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkLimitSwitch     m_photoeye{m_ampRoller.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen)};
  // rev::SparkPIDController   m_ampMotorPID = m_ampMotor.GetPIDController();
  rev::SparkRelativeEncoder m_ampEncoder  = m_ampMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor); 

  frc::DoubleSolenoid       m_ampDoubleSolenoid  {PCM_CANID, frc::PneumaticsModuleType::REVPH, AMP_DEPLOY_PCM, AMP_RETRACT_PCM}; 

  // bool m_ampIsDeployed;
};
