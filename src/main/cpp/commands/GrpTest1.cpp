// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpTest1.h"
#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"

#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdWaitShooterSpeed.h"
#include <frc2/command/WaitCommand.h>



GrpTest1::GrpTest1() {
  AddCommands
  (

    CmdPrintText("GrpTest1 Start"),
    CmdDriveClearAll(),

    frc2::WaitCommand(1.0_s),

    CmdDriveToPoint(0, 60, 0, 2000, true, 10),

    frc2::WaitCommand(1.0_s),

    CmdDriveToPoint(-40, 60, 0, 2000, true, 10),

    frc2::WaitCommand(1.0_s),


    CmdDriveToPoint(0, 0, 0, 2000, true, 10),



    CmdPrintText("GrpTest1 Finished"),
    CmdDriveStop()
  );
}
