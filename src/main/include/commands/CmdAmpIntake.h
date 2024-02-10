#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdAmpIntake
    : public frc2::CommandHelper<frc2::Command, CmdAmpIntake> {
 public:
  CmdAmpIntake(double power);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:

  double m_ampPower;
};
