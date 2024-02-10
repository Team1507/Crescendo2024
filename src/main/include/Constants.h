
#pragma once

//PCM IDS


#define INTAKE_DEPLOY_PCM 0
#define INTAKE_RETRACT_PCM 1

#define CLIMBER_BRAKE_ENGAGE_PCM 2
#define CLIMBER_BRAKE_DISENGAGE_PCM 3
// #define AMP_DEPLOY_PCM 4
// #define AMP_RETRACT_PCM 5

//CAN IDS
#define CLIMBER_LEFT_CANID 13
#define CLIMBER_RIGHT_CANID 14

#define SHOOTER_UPPER_CANID 15
#define SHOOTER_LOWER_CANID 16
#define SHOOTER_PIVOT_CANID 17

#define AMP_MOTOR_CANID 18
#define AMP_ROLLER_CANID 19

#define SHOOTER_FEEDER_CANID 20
#define FEEDER_TOF_CANID 21

#define AMP_TOF_CANID 22

#define CANDLE_LED_1_CANID 23
#define CANDLE_LED_2_CANID 24
#define CANDLE_LED_3_CANID 25

#define PCM_CANID 26
#define PDH_CANID 27

#define INTAKE_MOTOR_CANID 28

//Digital I/O

// #define AMP_UPPER_LIMIT 0
// #define AMP_LOWER_LIMIT 0

#define CLIMBER_LIMIT_TOP 0
#define CLIMBER_LIMIT_BOTTOM 1


namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants
