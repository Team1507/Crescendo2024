#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdShooterDefault
    : public frc2::CommandHelper<frc2::Command, CmdShooterDefault> {
 public:
  CmdShooterDefault();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:

  bool m_shooting;
  
};
