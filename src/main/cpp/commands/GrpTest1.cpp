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

GrpTest1::GrpTest1() {
  AddCommands
  (

    CmdPrintText("GrpTest1 Start"),
    CmdDriveClearAll(),
    frc2::WaitCommand(0.5_s),
    //---------------------------------------
    CmdShooterSetPower(0.2),
    CmdWaitShooterSpeed(),
    CmdShooterShootNote(),
    CmdIntakeDeploy(),
    CmdIntakeRetract(),


    //---------------------------------------
    //All Done
    CmdPrintText("GrpTest1 Finished"),
    CmdDriveStop()
  );
}
