#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>
#include <frc/AddressableLED.h>
#include "Constants.h"

#define COLOR_RED   50, 0, 0
#define COLOR_GREEN 0, 255, 0
#define COLOR_BLUE  0, 0, 50

#define COLOR_WHITE 255, 255, 255 

#define COLOR_YELLOW 255, 255, 0
#define COLOR_PURPLE 128, 0, 128
#define COLOR_ORANGE 255, 160, 0 //NO Used looks like yellow

#define COLOR_BLACK 0, 0, 0

class DriverFeedback : public frc2::SubsystemBase {
 public:
  DriverFeedback();

  void RumbleBot(float power);
  void RumbleTop(float power);

  void FeedbackLED(int r, int g, int b);

  void Periodic() override;

 private:


};
