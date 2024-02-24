#pragma once

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <rev/CANSparkBase.h>
#include <frc/DigitalInput.h>
#include "TimeOfFlight.h"

#define FEEDER_SHOOTER_POWER 0
#define FEEDER_INTAKE_POWER 0

enum dPadPosition {DPAD_UP, DPAD_DOWN, DPAD_LEFT, DPAD_RIGHT};


class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void   Periodic() override;
  void   ShooterInterpolate(double distance);

  //***********SHOOTER***********
  void   ShooterInit(void);
  void   SetShooterPower(double power);
  void   SetShooterRPM(double rpm);

  double GetUpperShooterPower(void);
  double GetUpperShooterRPM(void);
  double GetLowerShooterPower(void);
  double GetLowerShooterRPM(void);

  //***********PIVOT***********
  void   SetPivotPower(double power);

  void   ResetPivotEncoder(float angle);

  double GetPivotAngle(void);
  double GetPivotPower(void);

  bool   GetUpperPivotLimitSW(void);
  bool   GetLowerPivotLimitSW(void);

  void   SetPivotAngle(float position);

  // ***********FEEDER***********

  void   SetFeederIntakePower(double power);
  double GetFeederIntakePower(void);
  void   SetFeederShooterPower(double power);
  double GetFeederShooterPower(void);
  bool   GetFeederTOF(void);

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
  frc::TimeOfFlight         m_feederTOF{FEEDER_TOF_CANID};
  // frc::DigitalInput         m_feederPhotoEye{SHOOTER_FEEDER_PHOTOEYE};

  const float DEG_PER_ROT = 0.1;

  float Deg2Rot(float deg); 
  float Rot2Deg(float rot);
};
