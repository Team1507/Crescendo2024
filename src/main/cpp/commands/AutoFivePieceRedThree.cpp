#include "commands/AutoFivePieceRedThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/CmdDriveAimAtTarget.h"

AutoFivePieceRedThree::AutoFivePieceRedThree() {
  
  AddCommands(
    CmdPrintText("Auto Five Piece Red Three Started"), 
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),

    //Rotate to speaker
    CmdDriveTurn2Angle(0.2, -45),
    CmdShooterShootNote(),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //Drive backwards
    //Turn To Speaker
    CmdDriveToPoint(0, 50, 0, 2000, true, 10),
    CmdDriveTurn2Angle(0.2, -45),
    CmdShooterSetAngle(0),

    CmdIntakeRetract(),
    CmdShooterShootNote(),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //Go to Note on right
    CmdDriveToPoint(56.5, 60, 90, 2000, true, 10),
    CmdIntakeRetract(),

    //Rotate to speaker maybe middle spot
    CmdDriveTurn2Angle(0.2, -90),
    CmdShooterSetAngle(0),
    CmdShooterShootNote(),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //Go to note on right
    CmdDriveToPoint(115.5, 60, 90, 2000, true, 10),
    CmdIntakeRetract(),

    //Rotate to speaker
    CmdDriveTurn2Angle(0.2, -45),
    CmdShooterSetAngle(0),
    CmdShooterShootNote(),

    //Rotate to starting position
    //Drive Back
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdDriveToPoint(132,225,0,3000,false,10),
    CmdIntakeDeploy(),
    CmdDriveToPoint(132,250,0,2000,true,10),
    CmdIntakeRetract(),

    //drive  forwards
    CmdDriveToPoint(132, 179,0,3000,true,10),

    //rotate to speaker
    CmdDriveTurn2Angle(.2, 45),
    CmdShooterSetAngle(0),
    CmdShooterShootNote(),
    
    CmdShooterSetPower(0),
    CmdDriveStop(),
    CmdPrintText("Auto Five Piece Red Three Ended")
  );
}