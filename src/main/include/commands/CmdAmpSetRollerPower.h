#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class CmdAmpSetRollerPower
    : public frc2::CommandHelper<frc2::Command, CmdAmpSetRollerPower> {
 public:
  CmdAmpSetRollerPower(double power);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:

  double m_ampPower;
};
