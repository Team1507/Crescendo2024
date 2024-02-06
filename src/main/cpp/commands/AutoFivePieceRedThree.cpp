#include "commands/AutoFivePieceRedThree.h"
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
AutoFivePieceRedThree::AutoFivePieceRedThree() {
  
  AddCommands(
    CmdPrintText("Auto Five Piece Red Three Started"), 
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
    //Rotate to starting position
    //Drive Back
    //Sense Notes
    //Arc to One of remaining Note(s)
    CmdIntakeDeploy(),
    CmdIntakeRetract(),
    //drive  forwards
    CmdShooterSetAngle(0),//set to correct shoting angle not 0
    //rotate to speaker
    CmdShooterShootNote(0),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Five Piece Red Three Ended")
  );
}