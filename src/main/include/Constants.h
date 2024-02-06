
#pragma once

//PCM IDS
#define PCM_CAN 0

#define INTAKE_DEPLOY_PCM 0
#define INTAKE_RETRACT_PCM 0

#define CLIMBER_BRAKE_ENGAGE_PCM 0
#define CLIMBER_BRAKE_DISENGAGE_PCM 0

//CAN IDS
#define INTAKE_MOTOR_CANID 0

#define CLIMBER_LEFT_CANID 0
#define CLIMBER_RIGHT_CANID 0

#define SHOOTER_UPPER_CANID 0
#define SHOOTER_LOWER_CANID 0
#define SHOOTER_PIVOT_CANID 0
#define SHOOTER_FEEDER_CANID 0
#define SHOOTER_FEEDER_TIME_OF_FLIGHT 0

#define FEEDER_SHOOTER_POWER 0
#define FEEDER_INTAKE_POWER 0

#define AMP_MOTOR_CANID 0
#define AMP_ROLLER_CANID 0
#define AMP_TIME_OF_FLIGHT_CANID 0
#define AMP_UPPER_LIMIT 0
#define AMP_LOWER_LIMIT 0
#define AMP_DEPLOY_PCM 0
#define AMP_RETRACT_PCM 0
#define DIO_INTAKE_DETECT_ID 0

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants
