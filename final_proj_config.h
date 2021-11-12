/*
 * final_proj_config.h
 *
 *  Created on: Nov 12, 2021
 *      Author: Collin Graham
 */

#ifndef SRC_HEADER_FILES_FINAL_PROJ_CONFIG_H_
#define SRC_HEADER_FILES_FINAL_PROJ_CONFIG_H_

//-1 = undecided
//-1.5 = may be unused
//-2 = unused
//Any natural number: set val

//Other
#define DATA_STRUCTURE_VER      1

//Properties
#define GRAVITY                 10  /// [m/s^2]
#define V_MASS                  -1  /// [kg]
#define CONVERSION_EFF          -1.5/// [%]
#define FUEL_ENERGY_DENSITY     -1.5/// [kJ/g]
#define ANGLE_CHANGE_QUANTA     -2  /// [mrad]

//Initial Properties
#define INITIAL_V_X             -1  /// [cm/s]
#define INITIAL_V_Y             -1  /// [cm/s]
#define INITIAL_Y               -1  /// [mm]
#define INITIAL_FUEL_MASS       -1  /// [kg]

//Max Properties
#define MAX_THRUST              -1  /// [N]
#define MAX_LANDING_SPEED_X     -1  /// [cm/s]
#define MAX_LANDING_SPEED_Y     -1  /// [mm/s]
#define MAX_ACCELERATION        -1  /// [mm/s^2]
#define MAX_ACC_BLACKOUT_AFTER  -1  /// [s]
#define BLACKOUT_DURATION       -1  /// [s]

//Hardware Constraints
#define XMIN                    -1  /// [cm]
#define XMAX                    -1  /// [cm]

//Configurable
enum Selected_Option {NormalMode, HardMode};

#endif /* SRC_HEADER_FILES_FINAL_PROJ_CONFIG_H_ */
