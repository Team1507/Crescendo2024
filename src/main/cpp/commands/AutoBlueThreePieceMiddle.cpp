

#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <---- Drive train
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdWaitShooterSpeed.h"
#include "commands/CmdDriveClearAll.h"
#include <frc2/command/WaitCommand.h>
#include "commands/AutoBlueThreePieceMiddle.h"
#include "frc2/command/WaitCommand.h"


 
 AutoBlueThreePieceMiddle::AutoBlueThreePieceMiddle() {

  AddCommands(
        CmdPrintText("Auto Three Piece Blue Middle Started"), 
    CmdDriveClearAll(),

    //Shooting Starting Note
    CmdShooterSetAngle(50),
    CmdShooterSetPower(0.8),
    CmdWaitShooterSpeed(),
    CmdShooterShootNote(),


    //drive to note
    CmdIntakeDeploy(),
    CmdDriveToPoint(0, 37, 0, 4000, true, 10),

    //go to and Shoot Second Note
    CmdDriveToPoint(0, 0, 0, 4000, true, 10),
    CmdIntakeRetract(),
    CmdShooterShootNote(),
    CmdShooterSetAngle(36),
  
  
    //Go To Third Note
    CmdIntakeDeploy(),
    CmdDriveToPoint(-50, 40, -25, 5000, false, 10),
    CmdDriveToPoint(-50, 55, -20, 2000, true, 10),

    // CmdDriveToPoint(30, -5, 25, 4000, true, 10),  

    //Wait just a hair to let intake to come up
    //frc2::WaitCommand(2.00_s),

    //shoot third note
    CmdShooterShootNote(),

    CmdShooterSetPower(0),
    CmdDriveStop(),
    CmdPrintText("Auto Three Piece Blue Middle Completed")
  );
}
