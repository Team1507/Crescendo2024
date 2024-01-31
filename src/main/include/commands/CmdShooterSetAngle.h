#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdShooterSetAngle
    : public frc2::CommandHelper<frc2::Command, CmdShooterSetAngle> {
 public:
  CmdShooterSetAngle(double angle);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

    double m_shooterAngle;
};
