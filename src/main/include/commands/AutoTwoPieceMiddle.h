#pragma once

#include "Robot.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
//#include "subsystems/DriveTrain"

class AutoTwoPieceMiddle
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoPieceMiddle> {
 public:
  AutoTwoPieceMiddle();
};
