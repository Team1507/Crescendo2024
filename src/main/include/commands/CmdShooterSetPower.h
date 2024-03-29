#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdShooterSetPower
    : public frc2::CommandHelper<frc2::Command, CmdShooterSetPower> {
 public:

  CmdShooterSetPower(double shooterPower);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private: 

  double m_shooterPower;


};
