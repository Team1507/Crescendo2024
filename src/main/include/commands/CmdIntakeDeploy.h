#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/DigitalInput.h>

#include "Robot.h"

class CmdIntakeDeploy
    : public frc2::CommandHelper<frc2::Command, CmdIntakeDeploy> {
 public:
  CmdIntakeDeploy();

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  
};
