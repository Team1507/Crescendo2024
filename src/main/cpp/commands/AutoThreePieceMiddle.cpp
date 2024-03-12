

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
#include "commands/AutoThreePieceMiddle.h"


AutoThreePieceMiddle::AutoThreePieceMiddle() {

  AddCommands(
        CmdPrintText("Auto Three Piece Middle Started"), 
    CmdDriveClearAll(),
    //Shooting Starting Note
    // CmdShooterSetAngle(52),
    CmdShooterSetPower(0.8),
    CmdWaitShooterSpeed(),
    CmdShooterShootNote(),
    //Deploying Intake to pick up second note
    CmdIntakeDeploy(),
    //drive to note
    CmdDriveToPoint(0, 37, 0, 4000, true, 10),
    //Driving To Speaker
    CmdDriveToPoint(0, 0, 0, 4000, true, 10),
    //Shoot Second Note
    CmdIntakeRetract(),
    CmdShooterShootNote(),
  
    //Go To Third Note
    CmdIntakeDeploy(),
    CmdDriveToPoint(57, 37, 25, 2000, true, 10),
    CmdDriveToPoint(30, -5, 25, 2000, true, 10),  
    CmdShooterShootNote(),


    //Go get 4th note!
    CmdDriveToPoint(70, 176, 0, 12000, false, 10),
    CmdIntakeDeploy(),
    CmdDriveToPoint(74, 249, 0, 6000, true, 10),


   //Drive to score fourth
   CmdShooterSetPower(0.85),
   CmdDriveToPoint(12, 70, 0, 12000, true, 10),
   CmdShooterShootNote(),
 



    CmdShooterSetPower(0),
    CmdDriveStop(),
    CmdPrintText("Auto Four Piece Red Middle Completed")
  );

}
