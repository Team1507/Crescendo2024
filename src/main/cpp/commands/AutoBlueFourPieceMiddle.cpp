#include "commands/AutoBlueFourPieceMiddle.h"
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
#include "commands/CmdShooterCalculateShot.h"

AutoBlueFourPieceMiddle::AutoBlueFourPieceMiddle() 
{

  AddCommands(
    CmdPrintText("Auto Four Piece Blue Middle Started"), 
    CmdDriveClearAll(),

    //Shooting Starting Note
    CmdShooterSetAngle(50),
    CmdShooterSetPower(0.8),
    CmdWaitShooterSpeed(),
    CmdShooterShootNote(),

    //Deploying Intake to pick up second note
    CmdIntakeDeploy(),

    //drive to note
    CmdDriveToPoint(0, 37, 0, 6000, true, 10),

    //Driving To Speaker
    CmdDriveToPoint(0, 0, 0, 6000, true, 10),

    //Shoot Second Note
    CmdIntakeRetract(),
    CmdShooterShootNote(),
    CmdShooterSetAngle(34),
  
  
    //Go To Third Note
    CmdIntakeDeploy(),
    CmdDriveToPoint(-57, 40, -25, 6000, false, 10),

    CmdDriveToPoint(-57, 55, -30, 3000, true, 10),

    // CmdDriveToPoint(30, -5, 25, 4000, true, 10),  

    //Wait just a hair to let intake to come up
    //frc2::WaitCommand(2.00_s),

    CmdShooterShootNote(),
    CmdIntakeRetract(),
    CmdShooterSetAngle(50),
    
    //Go get 4th note!
    CmdDriveToPoint(-70, 176, 0, 12000, false, 10),
    CmdIntakeDeploy(),
    CmdDriveToPoint(-74, 249, 0, 7000, true, 10),


    //Drive to score fourth
    CmdDriveToPoint(-12, 70, 0, 12000, false, 10),
    CmdDriveToPoint(0 , 10 , 0 , 10000 , true, 10),
    CmdShooterShootNote(),
    CmdIntakeRetract(),

    //Far Out
    CmdDriveToPoint(-70, 176, 0, 12000, true, 10),

    CmdShooterSetPower(0),
    CmdDriveStop(),
    CmdPrintText("Auto Four Piece Blue Middle Completed")
  );

}
