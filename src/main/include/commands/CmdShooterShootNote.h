#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdShooterShootNote
    : public frc2::CommandHelper<frc2::Command, CmdShooterShootNote> {
 public:

  CmdShooterShootNote(bool status);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:

  bool m_status;
};
