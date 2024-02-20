#include "commands/AutoDoNothing.h"
#include "commands/CmdPrintText.h"

#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdGyroSetAngleOffset.h"


AutoDoNothing::AutoDoNothing() 
{
  AddCommands(

    //Auto Setup 
    CmdPrintText("****** AutoDoNothing ******"),
    CmdDriveClearAll(),
    //CmdGyroSetAngleOffset( 180.0),



    CmdDriveStop(),    // saftey
    CmdPrintText("AutoDoNothing Complete")
  );
}
