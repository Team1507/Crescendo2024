#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>


class CmdShooterHome
    : public frc2::CommandHelper<frc2::Command, CmdShooterHome> {
 public:
  CmdShooterHome();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
};
