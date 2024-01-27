
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

#define DIO_INTAKE_DETECT_ID 0

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants
