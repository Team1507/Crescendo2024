#include "commands/AutoDoNothing.h"
#include "commands/CmdPrintText.h"

AutoDoNothing::AutoDoNothing() 
{
  AddCommands(
    CmdPrintText("Auto Do Nothing"),
  //Drive Clear All
  //Gyro Set Angle Offset
  //Drive Stop
    CmdPrintText("Auto Do Nothing Completed")

  );
}
