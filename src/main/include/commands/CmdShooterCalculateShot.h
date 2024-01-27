#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdShooterCalculateShot
    : public frc2::CommandHelper<frc2::Command, CmdShooterCalculateShot> {
 public:
  CmdShooterCalculateShot();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
