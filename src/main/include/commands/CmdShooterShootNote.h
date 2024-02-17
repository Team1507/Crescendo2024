#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>

class CmdShooterShootNote
    : public frc2::CommandHelper<frc2::Command, CmdShooterShootNote> {
 public:

  CmdShooterShootNote();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  frc::Timer m_timer;
};
