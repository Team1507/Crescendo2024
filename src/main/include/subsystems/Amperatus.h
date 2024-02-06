#pragma once

#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>

class Amperatus : public frc2::SubsystemBase {
 public:
  Amperatus();

  void   SetAmpPower(double power);

  void   SetAmpAngle(double angle);

  void   SetAmpHome(bool home);

  void   HoldAmpAngle(double position);

  void   SetAmpRollerPower(double power);

  double GetAmpPower(void);

  double GetAmpAngle(void);

  double GetAmpRollerPower(void);

  void   AmpTrapDeploy(void); 

  void   AmpTrapRetract(void); 

  bool   AmpTrapIsDeployed(void); 
 
  bool   GetAmpTopLimit(void);

  bool   GetAmpBotLimit(void);

  bool   GetAmpPhotoEye(void);

  void   Periodic() override;

 private:

  frc::DigitalInput         m_ampTopLimit{AMP_UPPER_LIMIT};
  frc::DigitalInput         m_ampBotLimit{AMP_LOWER_LIMIT};

  frc::DigitalInput         m_ampPhotoEye{AMP_PHOTOEYE_CANID};  

  rev::CANSparkMax          m_ampRoller{AMP_ROLLER_CANID, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkPIDController   m_ampRollerPID     = m_ampRoller.GetPIDController();
  rev::SparkRelativeEncoder m_ampRollerEncoder = m_ampRoller.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::CANSparkMax          m_ampMotor{AMP_MOTOR_CANID, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkPIDController   m_ampMotorPID = m_ampMotor.GetPIDController();
  rev::SparkRelativeEncoder m_ampEncoder  = m_ampMotor.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor); 

  frc::DoubleSolenoid       m_ampDoubleSolenoid  {PCM_CAN, frc::PneumaticsModuleType::CTREPCM, AMP_DEPLOY_PCM, AMP_RETRACT_PCM}; 

  bool m_ampIsDeployed;
};
