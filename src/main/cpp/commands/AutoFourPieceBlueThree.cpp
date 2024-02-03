
#include "commands/AutoFourPieceBlueThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"


#include "commands/AutoFourPieceBlueThree.h"


AutoFourPieceBlueThree::AutoFourPieceBlueThree() {

  AddCommands(
    CmdPrintText("Auto Four Piece Blue Three Started"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    CmdIntakeDeploy(),
    //Drive backwards
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    //Arc to Note on right
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    //Arc to note on right
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(0),
    CmdIntakeRetract(),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Four Piece Blue Three Ended")
  );
}
