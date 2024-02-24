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

  // void   SetAmpAngle(double position);

  // void   ResetAmpEncoder(void);

  void   SetAmpRollerPower(double power);

  void   AmpTrapDeploy(bool status);

  void   AmpTrapRetract(bool status);

  double GetAmpPower(void);

  // double GetAmpAngle(void);

  double GetAmpRollerPower(void);

  bool   GetAmpTopLimit(void);

  bool   GetAmpBotLimit(void);

  bool   GetAmpTOF(void);

  void   Periodic() override;

 private:

  // frc::DigitalInput         m_ampTopLimit{AMP_UPPER_LIMIT};
  // frc::DigitalInput         m_ampBotLimit{AMP_LOWER_LIMIT};

  frc::TimeOfFlight         m_ampTOF{AMP_TOF_CANID};  

  rev::CANSparkMax          m_ampRoller{AMP_ROLLER_CANID, rev::CANSparkMax::MotorType::kBrushed};
  // rev::SparkPIDController   m_ampRollerPID     = m_ampRoller.GetPIDController();
  // rev::SparkRelativeEncoder m_ampRollerEncoder = m_ampRoller.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::CANSparkMax          m_ampMotor{AMP_MOTOR_CANID, rev::CANSparkMax::MotorType::kBrushed};
  // rev::SparkPIDController   m_ampMotorPID = m_ampMotor.GetPIDController();
  // rev::SparkRelativeEncoder m_ampEncoder  = m_ampMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor); 

  frc::DoubleSolenoid       m_ampDoubleSolenoid  {PCM_CANID, frc::PneumaticsModuleType::CTREPCM, AMP_DEPLOY_PCM, AMP_RETRACT_PCM}; 

  // bool m_ampIsDeployed;
};
