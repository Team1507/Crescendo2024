#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdShooterDPad
    : public frc2::CommandHelper<frc2::Command, CmdShooterDPad> {
 public:
  CmdShooterDPad(dPadPosition position);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
