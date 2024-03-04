#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>
#include <frc/AddressableLED.h>
#include "ctre/phoenix/led/CANdle.h"
#include "Constants.h"

#define COLOR_RED   255, 0, 0
#define COLOR_GREEN 0, 255, 0
#define COLOR_BLUE  0, 0, 255

#define COLOR_WHITE 255, 255, 255 

#define COLOR_YELLOW 255, 255, 0
#define COLOR_PURPLE 128,   0, 128
#define COLOR_ORANGE 255, 160, 0      //NO Used looks like yellow
#define COLOR_TEAL     0, 255, 255


#define COLOR_BLACK 0, 0, 0

class DriverFeedback : public frc2::SubsystemBase {
 public:
  DriverFeedback();

  void RumbleBot(float power);
  void RumbleTop(float power);

  void FeedbackLED(int r, int g, int b);

  void BlinkLED(int r, int g, int b);
  void DisableBlink(void);

  void Periodic() override;

 private:


  ctre::phoenix::led::CANdle m_frontCandle {CANDLE_LED_1_CANID, ""};
  ctre::phoenix::led::CANdle m_rearCandle  {CANDLE_LED_2_CANID, ""};

  bool m_blinkEnable;
  int  m_blink_count;
  int  m_blink_r;
  int  m_blink_g;
  int  m_blink_b;

  int  m_pulseCount;

  bool m_prevFeederNote;


};
