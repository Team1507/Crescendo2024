#pragma once

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <rev/CANSparkBase.h>
#include <frc/DigitalInput.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void   Periodic() override;
  void   ShooterInterpolate(double distance);

  //***********SHOOTER***********
  void   ShooterInit(void);
  void   SetShooterPower(double power);
  void   SetShooterRPM(double rpm);
  void   SetIdle(bool idle);

  double GetUpperShooterPower(void);
  double GetUpperShooterRPM(void);
  double GetLowerShooterPower(void);
  double GetLowerShooterRPM(void);
  bool   IsIdle(void);

  //***********PIVOT***********
  void   SetPivotAngle(double angle);
  void   SetPivotPower(double power);

  void   ResetPivotEncoder(void);

  double GetPivotAngle(void);
  double GetPivotPower(void);

  bool   GetUpperPivotLimitSW(void);
  bool   GetLowerPivotLimitSW(void);

  void   HoldPivotAngle(float position);

  // ***********FEEDER***********

  void   SetFeederIntakePower(double power);
  double GetFeederIntakePower(void);
  void   SetFeederShooterPower(double power);
  double GetFeederShooterPower(void);
  bool   GetFeederStatus(void);
  bool   GetFeederPhotoEye(void);

 private:

  rev::CANSparkMax          m_shooterUpper {SHOOTER_UPPER_CANID, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkPIDController   m_shooterUpperPID     = m_shooterUpper.GetPIDController();
  rev::SparkRelativeEncoder m_shooterUpperEncoder = m_shooterUpper.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::CANSparkMax          m_shooterLower {SHOOTER_LOWER_CANID, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkPIDController   m_shooterLowerPID     = m_shooterLower.GetPIDController();
  rev::SparkRelativeEncoder m_shooterLowerEncoder = m_shooterLower.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::CANSparkMax          m_shooterPivot {SHOOTER_PIVOT_CANID, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkPIDController   m_shooterPivotPID     = m_shooterPivot.GetPIDController();
  rev::SparkRelativeEncoder m_shooterPivotEncoder = m_shooterPivot.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
  rev::SparkLimitSwitch     m_shooterPivotFwLimit = m_shooterPivot.GetForwardLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);
  rev::SparkLimitSwitch     m_shooterPivotRvLimit = m_shooterPivot.GetReverseLimitSwitch(rev::SparkLimitSwitch::Type::kNormallyOpen);

  rev::CANSparkMax          m_feederMotor{SHOOTER_FEEDER_CANID, rev::CANSparkMax::MotorType::kBrushless};
  frc::DigitalInput         m_feederPhotoEye{SHOOTER_FEEDER_PHOTOEYE};

  bool                      m_isIdle;
  bool                      m_feederStatus;
};
