#include "commands/AutoFourPieceRedThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"


#include "commands/AutoFourPieceRedThree.h"


AutoFourPieceRedThree::AutoFourPieceRedThree() {

  AddCommands(
    CmdPrintText("Auto Four Piece Red Three Started"), 
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
    //Arc to Note on left
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    //Arc to note on left
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(0),
    CmdIntakeRetract(),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Four Piece Red Three Ended")
  );
}
