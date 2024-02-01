#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class AutoTwoPieceMiddle
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoPieceMiddle> {
 public:
  AutoTwoPieceMiddle();
};
