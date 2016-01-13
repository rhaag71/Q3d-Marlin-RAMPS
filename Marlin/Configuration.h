#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "boards.h"

// Printer type
//#define Three_Up  //Uncomment for ThreeUp
#define Two_Up  //Uncomment for OneUp
//#define One_Up  //Uncomment for TwoUp

//Filament Drive Gear Type
//#define Stainless_Gear  //Uncomment for New Gear
#define Brass_Gear      //Uncomment for Old Gear

//Hotend
#define AnUBIS //Q3d AnUBIS Hotend
//#define METAL  //Q3d Metal Hotend

#ifdef Three_Up
    #define CUSTOM_MACHINE_NAME "Q3d Three UP"
  #define X_MAX_POS 175  //ThreeUP size
  #define Y_MAX_POS 175
  #define Z_MAX_POS 210
  #define  DEFAULT_bedKp 239.7
  #define  DEFAULT_bedKi 27.71
  #define  DEFAULT_bedKd 518.4
#endif

#ifdef Two_Up
  #define CUSTOM_MACHINE_NAME "Q3d Two UP"
  #define X_MAX_POS 175  //TwoUP size
  #define Y_MAX_POS 175
  #define Z_MAX_POS 125
  #define  DEFAULT_bedKp 239.7
  #define  DEFAULT_bedKi 27.71
  #define  DEFAULT_bedKd 518.4
#endif

#ifdef One_Up
  #define CUSTOM_MACHINE_NAME "Q3d One UP"
  #define X_MAX_POS 100 //OneUp size
  #define Y_MAX_POS 100
  #define Z_MAX_POS 125
  #define  DEFAULT_bedKp 130.02
  #define  DEFAULT_bedKi 15.75
  #define  DEFAULT_bedKd 268.42
#endif     

//#define SDSUPPORT // Enable SD Card Support with SD Ramps

#ifdef Brass_Gear
  #define E_Step 88.57326053533955
#endif

#ifdef Stainless_Gear
  #define E_Step 136.611842 
#endif
// @section machine

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
#define INVERT_X_DIR true
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true


#define STRING_VERSION "1.0.2"
#define STRING_URL "q3dprinter.com"

#define STRING_SPLASH_LINE2 STRING_VERSION_CONFIG_H // will be shown during bootup in line2


#define STRING_CONFIG_H_AUTHOR "(none, default config)" // Who made the changes.
#define STRING_SPLASH_LINE1 "v" STRING_VERSION // will be shown during bootup in line 1
// @section machine

// SERIAL_PORT selects which serial port should be used for communication with the host.
// This allows the connection of wireless adapters (for instance) to non-default port pins.
// Serial port 0 is still used by the Arduino bootloader regardless of this setting.
// :[0,1,2,3,4,5,6,7]
#define SERIAL_PORT 0

// This determines the communication speed of the printer
// :[2400,9600,19200,38400,57600,115200,250000]
#define BAUDRATE 250000

// This enables the serial port associated to the Bluetooth interface
//#define BTENABLED              // Enable BT interface on AT90USB devices

// The following define selects which electronics board you have.
// Please choose the name from boards.h that matches your setup
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_13_EFB
#endif

// Define this to set a unique identifier for this printer, (Used by some programs to differentiate between machines)
// You can use an online service to generate a random UUID. (eg http://www.uuidgenerator.net/version4)
// #define MACHINE_UUID ""

// This defines the number of extruders
// :[1,2,3,4]
#define EXTRUDERS 1

//// The following define selects which power supply you have. Does not support stock power supply
// 1 = ATX
// 2 = X-Box 360 203Watts (the blue wire connected to PS_ON and the red wire to VCC)

#define POWER_SUPPLY 1

// Define this to have the electronics keep the power supply off on startup. If you don't know what this is leave it.
// #define PS_DEFAULT_OFF

// @section temperature

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================
//
//--NORMAL IS 4.7kohm PULLUP!-- 1kohm pullup can be used on hotend sensor, using correct resistor and table
//
//// Temperature sensor settings:
// 0 is not used
// 1 is 100k thermistor - best choice for EPCOS 100k (4.7k pullup)
// 2 is 200k thermistor - ATC Semitec 204GT-2 (4.7k pullup)
// 3 is Mendel-parts thermistor (4.7k pullup)
// 998 and 999 are Dummy Tables. They will ALWAYS read 25°C or the temperature defined below.
//     Use it for Testing or Development purposes. NEVER for production machine.
//     #define DUMMY_THERMISTOR_998_VALUE 25
//     #define DUMMY_THERMISTOR_999_VALUE 100
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0

// This makes temp sensor 1 a redundant sensor for sensor 0. If the temperatures difference between these sensors is to high the print will be aborted.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

// Actual temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 10  // (seconds)
#define TEMP_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

// The minimal temperature defines the temperature below which the heater will not be enabled It is used
// to check that the wiring to the thermistor is not broken.
// Otherwise this would lead to the heater being powered on all the time.
#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define HEATER_3_MINTEMP 5
#define BED_MINTEMP 5

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define HEATER_0_MAXTEMP 250
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define BED_MAXTEMP 120

// If your bed has low resistance e.g. .6 ohm and throws the fuse you can duty cycle it to reduce the
// average current. The value should be an integer and the heat bed will be turned on for 1 interval of
// HEATER_BED_DUTY_CYCLE_DIVIDER intervals.
//#define HEATER_BED_DUTY_CYCLE_DIVIDER 4

// If you want the M105 heater power reported in watts, define the BED_WATTS, and (shared for all extruders) EXTRUDER_WATTS
//#define EXTRUDER_WATTS (12.0*12.0/6.7) //  P=I^2/R
//#define BED_WATTS (12.0*12.0/1.1)      // P=I^2/R

//===========================================================================
//============================= PID Settings ================================
//===========================================================================
// PID Tuning Guide here: http://reprap.org/wiki/PID_Tuning

// Comment the following line to disable PID and enable bang-bang.
#define PIDTEMP
#define BANG_MAX 255 // limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#ifdef PIDTEMP
  //#define PID_DEBUG // Sends debug data to the serial port.
  //#define PID_OPENLOOP 1 // Puts PID in open loop. M104/M140 sets the output power from 0 to PID_MAX
  //#define SLOW_PWM_HEATERS // PWM with very low frequency (roughly 0.125Hz=8s) and minimum state time of approximately 1s useful for heaters driven by a relay
  //#define PID_PARAMS_PER_EXTRUDER // Uses separate PID parameters for each extruder (useful for mismatched extruders)
                                    // Set/get with gcode: M301 E[extruder number, 0-2]
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature
                                  // is more then PID_FUNCTIONAL_RANGE then the PID will be shut off and the heater will be set to min/max.
  #define PID_INTEGRAL_DRIVE_MAX PID_MAX  //limit for the integral term
  #define K1 0.95 //smoothing factor within the PID
#endif
// AnUBIS Hotend PID
#ifdef AnUBIS
    #define  DEFAULT_Kp 26.70
    #define  DEFAULT_Ki 1.55
    #define  DEFAULT_Kd 114.83
#endif // PIDTEMP

//Q3d Metal Hotend PID
#ifdef METAL
    #define  DEFAULT_Kp 24.95
    #define  DEFAULT_Ki 2.42
    #define  DEFAULT_Kd 64.37
#endif
  

//===========================================================================
//============================= Bed Temperature Control =====================
//===========================================================================
#define PIDTEMPBED
//
//#define BED_LIMIT_SWITCHING

// This sets the max power delivered to the bed, and replaces the HEATER_BED_DUTY_CYCLE_DIVIDER option.
// all forms of bed control obey this (PID, bang-bang, bang-bang with hysteresis)
// setting this to anything other than 255 enables a form of PWM to the bed just like HEATER_BED_DUTY_CYCLE_DIVIDER did,
// so you shouldn't use it unless you are OK with PWM on your bed.  (see the comment on enabling PIDTEMPBED)
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

//#define PID_BED_DEBUG // Sends debug data to the serial port.

#ifdef PIDTEMPBED
//120v 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
//from FOPDT model - kp=.39 Tp=405 Tdead=66, Tc set to 79.2, aggressive factor of .15 (vs .1, 1, 10)
    #define  DEFAULT_bedKp 10.00
    #define  DEFAULT_bedKi .023
    #define  DEFAULT_bedKd 305.4

// FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif // PIDTEMPBED

// @section extruder

//this prevents dangerous Extruder moves, i.e. if the temperature is under the limit
//can be software-disabled for whatever purposes by
#define PREVENT_DANGEROUS_EXTRUDE
//if PREVENT_DANGEROUS_EXTRUDE is on, you can still disable (uncomment) very long bits of extrusion separately.
#define PREVENT_LENGTHY_EXTRUDE

#define EXTRUDE_MINTEMP 170
#define EXTRUDE_MAXLENGTH (X_MAX_LENGTH+Y_MAX_LENGTH) //prevent extrusion of very large distances.

//===========================================================================
//============================= Thermal Runaway Protection ==================
//===========================================================================
/*
This is a feature to protect your printer from burn up in flames if it has
a thermistor coming off place (this happened to a friend of mine recently and
motivated me writing this feature).
The issue: If a thermistor come off, it will read a lower temperature than actual.
The system will turn the heater on forever, burning up the filament and anything
else around.
After the temperature reaches the target for the first time, this feature will
start measuring for how long the current temperature stays below the target
minus _HYSTERESIS (set_temperature - THERMAL_RUNAWAY_PROTECTION_HYSTERESIS).
If it stays longer than _PERIOD, it means the thermistor temperature
cannot catch up with the target, so something *may be* wrong. Then, to be on the
safe side, the system will he halt.
Bear in mind the count down will just start AFTER the first time the
thermistor temperature is over the target, so you will have no problem if
your extruder heater takes 2 minutes to hit the target on heating.
*/
// If you want to enable this feature for all your extruder heaters,
// uncomment the 2 defines below:

// Parameters for all extruder heaters
#define THERMAL_RUNAWAY_PROTECTION_PERIOD 40 //in seconds
#define THERMAL_RUNAWAY_PROTECTION_HYSTERESIS 15 // in degree Celsius

// If you want to enable this feature for your bed heater,
// uncomment the 2 defines below:
//Shouldn't be needed on OneUp or TwoUp heated beds due to thermistor being embedded

// Parameters for the bed heater
//#define THERMAL_RUNAWAY_PROTECTION_BED_PERIOD 20 //in seconds
//#define THERMAL_RUNAWAY_PROTECTION_BED_HYSTERESIS 2 // in degree Celsius


//===========================================================================
//============================= Mechanical Settings =========================
//===========================================================================

// @section homing

// coarse Endstop Settings
#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors

#ifndef ENDSTOPPULLUPS
  // fine endstop settings: Individual pullups. will be ignored if ENDSTOPPULLUPS is defined
  // #define ENDSTOPPULLUP_XMAX
  // #define ENDSTOPPULLUP_YMAX
  // #define ENDSTOPPULLUP_ZMAX
  // #define ENDSTOPPULLUP_XMIN
  // #define ENDSTOPPULLUP_YMIN
  // #define ENDSTOPPULLUP_ZMIN
  // #define ENDSTOPPULLUP_ZPROBE
#endif

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
const bool X_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Y_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_MIN_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool X_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Y_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_MAX_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
const bool Z_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
#define DISABLE_MAX_ENDSTOPS
#define DISABLE_MIN_ENDSTOPS  //Printer has no endstops

// @section machine
// If you want to enable the Z Probe pin, but disable its use, uncomment the line below.
// This only affects a Z Probe Endstop if you have separate Z min endstop as well and have
// activated Z_PROBE_ENDSTOP below. If you are using the Z Min endstop on your Z Probe,
// this has no effect.
//#define DISABLE_Z_PROBE_ENDSTOP

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
// :{0:'Low',1:'High'}
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

// @section extruder

#define DISABLE_E false // For all extruders
#define DISABLE_INACTIVE_EXTRUDER true //disable only inactive extruders and keep active extruder enabled


// @section extruder

// For direct drive extruder v9 set to true, for geared extruder set to false.
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false

// @section homing

// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define min_software_endstops false // If true, axis won't move to coordinates less than HOME_POS.
#define max_software_endstops false  // If true, axis won't move to coordinates greater than the defined lengths below.

// @section machine

// Travel limits after homing (units are in mm)
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0


//===========================================================================
//============================= Filament Runout Sensor ======================
//===========================================================================
//#define FILAMENT_RUNOUT_SENSOR // Uncomment for defining a filament runout sensor such as a mechanical or opto endstop to check the existence of filament
                                 // In RAMPS uses servo pin 2. Can be changed in pins file. For other boards pin definition should be made.
                                 // It is assumed that when logic high = filament available
                                 //                    when logic  low = filament ran out
//const bool FIL_RUNOUT_INVERTING = true;  // Should be uncommented and true or false should assigned
//#define ENDSTOPPULLUP_FIL_RUNOUT // Uncomment to use internal pullup for filament runout pins if the sensor is defined.

//===========================================================================
//============================ Mesh Bed Leveling ============================
//===========================================================================

// #define MANUAL_BED_LEVELING  // Add display menu option for bed leveling
// #define MESH_BED_LEVELING    // Enable mesh bed leveling

#ifdef MANUAL_BED_LEVELING
  #define MBL_Z_STEP 0.025  // Step size while manually probing Z axis
#endif  // MANUAL_BED_LEVELING

#ifdef MESH_BED_LEVELING
  #define MESH_MIN_X 10
  #define MESH_MAX_X (X_MAX_POS - MESH_MIN_X)
  #define MESH_MIN_Y 10
  #define MESH_MAX_Y (Y_MAX_POS - MESH_MIN_Y)
  #define MESH_NUM_X_POINTS 3  // Don't use more than 7 points per axis, implementation limited
  #define MESH_NUM_Y_POINTS 3
  #define MESH_HOME_SEARCH_Z 4  // Z after Home, bed somewhere below but above 0.0
#endif  // MESH_BED_LEVELING

//===========================================================================
//============================= Bed Auto Leveling ===========================
//===========================================================================

// @section bedlevel

//#define ENABLE_AUTO_BED_LEVELING // Delete the comment to enable (remove // at the start of the line)
#define Z_PROBE_REPEATABILITY_TEST  // If not commented out, Z-Probe Repeatability test will be included if Auto Bed Leveling is Enabled.

#ifdef ENABLE_AUTO_BED_LEVELING

  // There are 2 different ways to specify probing locations
  //
  // - "grid" mode
  //   Probe several points in a rectangular grid.
  //   You specify the rectangle and the density of sample points.
  //   This mode is preferred because there are more measurements.
  //
  // - "3-point" mode
  //   Probe 3 arbitrary points on the bed (that aren't colinear)
  //   You specify the XY coordinates of all 3 points.

  // Enable this to sample the bed in a grid (least squares solution)
  // Note: this feature generates 10KB extra code size
  #define AUTO_BED_LEVELING_GRID

  #ifdef AUTO_BED_LEVELING_GRID

    #define LEFT_PROBE_BED_POSITION 15
    #define RIGHT_PROBE_BED_POSITION 170
    #define FRONT_PROBE_BED_POSITION 20
    #define BACK_PROBE_BED_POSITION 170

    #define MIN_PROBE_EDGE 10 // The probe square sides can be no smaller than this

    // Set the number of grid points per dimension
    // You probably don't need more than 3 (squared=9)
    #define AUTO_BED_LEVELING_GRID_POINTS 2

  #else  // !AUTO_BED_LEVELING_GRID

      // Arbitrary points to probe. A simple cross-product
      // is used to estimate the plane of the bed.
      #define ABL_PROBE_PT_1_X 15
      #define ABL_PROBE_PT_1_Y 180
      #define ABL_PROBE_PT_2_X 15
      #define ABL_PROBE_PT_2_Y 20
      #define ABL_PROBE_PT_3_X 170
      #define ABL_PROBE_PT_3_Y 20

  #endif // AUTO_BED_LEVELING_GRID

  // Offsets to the probe relative to the extruder tip (Hotend - Probe)
  // X and Y offsets must be integers
  #define X_PROBE_OFFSET_FROM_EXTRUDER -25     // Probe on: -left  +right
  #define Y_PROBE_OFFSET_FROM_EXTRUDER -29     // Probe on: -front +behind
  #define Z_PROBE_OFFSET_FROM_EXTRUDER -12.35  // -below (always!)

  #define Z_RAISE_BEFORE_HOMING 4       // (in mm) Raise Z before homing (G28) for Probe Clearance.
                                        // Be sure you have this distance over your Z_MAX_POS in case

  #define XY_TRAVEL_SPEED 8000         // X and Y axis travel speed between probes, in mm/min

  #define Z_RAISE_BEFORE_PROBING 15   //How much the extruder will be raised before traveling to the first probing point.
  #define Z_RAISE_BETWEEN_PROBINGS 5  //How much the extruder will be raised when traveling from between next probing points
  #define Z_RAISE_AFTER_PROBING 15    //How much the extruder will be raised after the last probing point.

//   #define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10" //These commands will be executed in the end of G29 routine.
                                                                            //Useful to retract a deployable probe.
                                                                           
  //#define Z_PROBE_SLED // turn on if you have a z-probe mounted on a sled like those designed by Charles Bell
  //#define SLED_DOCKING_OFFSET 5 // the extra distance the X axis must travel to pickup the sled. 0 should be fine but you can push it further if you'd like.

  //If defined, the Probe servo will be turned on only during movement and then turned off to avoid jerk
  //The value is the delay to turn the servo off after powered on - depends on the servo speed; 300ms is good value, but you can try lower it.
  // You MUST HAVE the SERVO_ENDSTOPS defined to use here a value higher than zero otherwise your code will not compile.

//  #define PROBE_SERVO_DEACTIVATION_DELAY 300


//If you have enabled the Bed Auto Leveling and are using the same Z Probe for Z Homing,
//it is highly recommended you let this Z_SAFE_HOMING enabled!!!

  #define Z_SAFE_HOMING   // This feature is meant to avoid Z homing with probe outside the bed area.
                          // When defined, it will:
                          // - Allow Z homing only after X and Y homing AND stepper drivers still enabled
                          // - If stepper drivers timeout, it will need X and Y homing again before Z homing
                          // - Position the probe in a defined XY point before Z Homing when homing all axis (G28)
                          // - Block Z homing only when the probe is outside bed area.

  #ifdef Z_SAFE_HOMING

    #define Z_SAFE_HOMING_X_POINT (X_MAX_LENGTH/2)    // X point for Z homing when homing all axis (G28)
    #define Z_SAFE_HOMING_Y_POINT (Y_MAX_LENGTH/2)    // Y point for Z homing when homing all axis (G28)

  #endif

  // Support for a dedicated Z PROBE endstop separate from the Z MIN endstop.
  // If you would like to use both a Z PROBE and a Z MIN endstop together or just a Z PROBE with a custom pin, uncomment #define Z_PROBE_ENDSTOP and read the instructions below.
  // If you want to still use the Z min endstop for homing, disable Z_SAFE_HOMING above. Eg; to park the head outside the bed area when homing with G28.
  // WARNING: The Z MIN endstop will need to set properly as it would without a Z PROBE to prevent head crashes and premature stopping during a print.
  // To use a separate Z PROBE endstop, you must have a Z_PROBE_PIN defined in the pins.h file for your control board.
  // If you are using a servo based Z PROBE, you will need to enable NUM_SERVOS, SERVO_ENDSTOPS and SERVO_ENDSTOPS_ANGLES in the R/C Servo below.
  // RAMPS 1.3/1.4 boards may be able to use the 5V, Ground and the D32 pin in the Aux 4 section of the RAMPS board. Use 5V for powered sensors, otherwise connect to ground and D32
  // for normally closed configuration and 5V and D32 for normally open configurations. Normally closed configuration is advised and assumed.
  // The D32 pin in Aux 4 on RAMPS maps to the Arduino D32 pin. Z_PROBE_PIN is setting the pin to use on the Arduino. Since the D32 pin on the RAMPS maps to D32 on Arduino, this works.
  // D32 is currently selected in the RAMPS 1.3/1.4 pin file. All other boards will need changes to the respective pins_XXXXX.h file.
  // WARNING: Setting the wrong pin may have unexpected and potentially disastrous outcomes. Use with caution and do your homework.

  //#define Z_PROBE_ENDSTOP

#endif // ENABLE_AUTO_BED_LEVELING


// @section homing

// The position of the homing switches
//#define MANUAL_HOME_POSITIONS  // If defined, MANUAL_*_HOME_POS below will be used
//#define BED_CENTER_AT_0_0  // If defined, the center of the bed is at (X=0, Y=0)

// Manual homing switch locations:
// For deltabots this means top and center of the Cartesian print volume.
#ifdef MANUAL_HOME_POSITIONS
  #define MANUAL_X_HOME_POS 0
  #define MANUAL_Y_HOME_POS 0
  #define MANUAL_Z_HOME_POS 0
  //#define MANUAL_Z_HOME_POS 402 // For delta: Distance between nozzle and print surface after homing.
#endif

// @section movement

/**
 * MOVEMENT SETTINGS
 */
 
 //Extruder gear settings
 //Old brass gear = 88.57326053533955
 //New stainless gear = 136.611842

#define HOMING_FEEDRATE {50*60, 50*60, 4*60, 0}  // set the homing speeds (mm/min)

#define DEFAULT_AXIS_STEPS_PER_UNIT   {88.88888888889,88.88888888889,1511.811023622047,E_Step}  // Steps per MM For One and Two Up printers. (X, Y, Z, E)
#define DEFAULT_MAX_FEEDRATE          {500, 500, 5, 45}    // (mm/sec)    
#define DEFAULT_MAX_ACCELERATION      {5000,5000,100,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.

#define DEFAULT_ACCELERATION          5000    // X, Y, Z and E max acceleration in mm/s^2 for printing moves 
#define DEFAULT_RETRACT_ACCELERATION  5000   // X, Y, Z and E max acceleration in mm/s^2 for r retracts
#define DEFAULT_TRAVEL_ACCELERATION   5000
// 
#define DEFAULT_XYJERK                20.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.4     // (mm/sec)
#define DEFAULT_EJERK                 5.0    // (mm/sec)


//=============================================================================
//============================= Additional Features ===========================
//=============================================================================

// @section more

// Custom M code points
#define CUSTOM_M_CODES
#ifdef CUSTOM_M_CODES
  #ifdef ENABLE_AUTO_BED_LEVELING
    #define CUSTOM_M_CODE_SET_Z_PROBE_OFFSET 851
    #define Z_PROBE_OFFSET_RANGE_MIN -20
    #define Z_PROBE_OFFSET_RANGE_MAX 20
  #endif
#endif

// @section extras

// EEPROM
// The microcontroller can store settings in the EEPROM, e.g. max velocity...
// M500 - stores parameters in EEPROM
// M501 - reads parameters from EEPROM (if you need reset them after you changed them temporarily).
// M502 - reverts to the default "factory settings".  You still need to store them in EEPROM afterwards if you want to.
//define this to enable EEPROM support
//#define EEPROM_SETTINGS

#ifdef EEPROM_SETTINGS
  // To disable EEPROM Serial responses and decrease program space by ~1700 byte: comment this out:
  #define EEPROM_CHITCHAT // please keep turned on if you can.
#endif


// @section temperature

// Preheat Constants
#define PLA_PREHEAT_HOTEND_TEMP 200
#define PLA_PREHEAT_HPB_TEMP 60
#define PLA_PREHEAT_FAN_SPEED 0   // Insert Value between 0 and 255

#define ABS_PREHEAT_HOTEND_TEMP 240
#define ABS_PREHEAT_HPB_TEMP 90
#define ABS_PREHEAT_FAN_SPEED 0   // Insert Value between 0 and 255

//==============================LCD and SD support=============================
// @section lcd

// Define your display language below. Replace (en) with your language code and uncomment.
// en, pl, fr, de, es, ru, it, pt, pt-br, fi, an, nl, ca, eu, kana, kana_utf8, test
// See also language.h
#define LANGUAGE_INCLUDE GENERATE_LANGUAGE_INCLUDE(en)

// Choose ONE of these 3 charsets. This has to match your hardware. Ignored for full graphic display.
// To find out what type you have - compile with (test) - upload - click to get the menu. You'll see two typical lines from the upper half of the charset.
// See also documentation/LCDLanguageFont.md
  #define DISPLAY_CHARSET_HD44780_JAPAN        // this is the most common hardware
  //#define DISPLAY_CHARSET_HD44780_WESTERN
  //#define DISPLAY_CHARSET_HD44780_CYRILLIC

//#define ULTRA_LCD  //general LCD support, also 16x2
//#define DOGLCD  // Support for SPI LCD 128x64 (Controller ST7565R graphic Display Family)
//#define SDSLOW // Use slower SD transfer mode (not normally needed - uncomment if you're getting volume init error)
//#define SD_CHECK_AND_RETRY // Use CRC checks and retries on the SD communication
//#define ENCODER_PULSES_PER_STEP 1 // Increase if you have a high resolution encoder
//#define ENCODER_STEPS_PER_MENU_ITEM 5 // Set according to ENCODER_PULSES_PER_STEP or your liking
//#define ULTIMAKERCONTROLLER //as available from the Ultimaker online store.
//#define ULTIPANEL  //the UltiPanel as on Thingiverse
//#define LCD_FEEDBACK_FREQUENCY_HZ 1000	// this is the tone frequency the buzzer plays when on UI feedback. ie Screen Click
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 100 // the duration the buzzer plays the UI feedback sound. ie Screen Click
                                               // 0 to disable buzzer feedback  

// PanelOne from T3P3 (via RAMPS 1.4 AUX2/AUX3)
// http://reprap.org/wiki/PanelOne
//#define PANEL_ONE

// The MaKr3d Makr-Panel with graphic controller and SD support
// http://reprap.org/wiki/MaKr3d_MaKrPanel
//#define MAKRPANEL

// The Panucatt Devices Viki 2.0 and mini Viki with Graphic LCD
// http://panucatt.com
// ==> REMEMBER TO INSTALL U8glib to your ARDUINO library folder: http://code.google.com/p/u8glib/wiki/u8glib
//#define VIKI2
//#define miniVIKI

// The RepRapDiscount Smart Controller (white PCB)
// http://reprap.org/wiki/RepRapDiscount_Smart_Controller
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

// The GADGETS3D G3D LCD/SD Controller (blue PCB)
// http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//#define G3D_PANEL

// The RepRapDiscount FULL GRAPHIC Smart Controller (quadratic white PCB)
// http://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
// ==> REMEMBER TO INSTALL U8glib to your ARDUINO library folder: http://code.google.com/p/u8glib/wiki/u8glib
//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

// The RepRapWorld REPRAPWORLD_KEYPAD v1.1
// http://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // how much should be moved when a key is pressed, eg 10.0 means 10mm per click

// The Elefu RA Board Control Panel
// http://www.elefu.com/index.php?route=product/product&product_id=53
// REMEMBER TO INSTALL LiquidCrystal_I2C.h in your ARDUINO library folder: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//#define RA_CONTROL_PANEL

/**
 * I2C Panels
 */

//#define LCD_I2C_SAINSMART_YWROBOT

// PANELOLU2 LCD with status LEDs, separate encoder and click inputs
//#define LCD_I2C_PANELOLU2

// Panucatt VIKI LCD with status LEDs, integrated click & L/R/U/P buttons, separate encoder inputs
//#define LCD_I2C_VIKI

// Shift register panels
// ---------------------
// 2 wire Non-latching LCD SR from:
// https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/schematics#!shiftregister-connection

//#define SAV_3DLCD

// @section extras

// Increase the FAN pwm frequency. Removes the PWM noise but increases heating in the FET/Arduino
//#define FAST_PWM_FAN

// Use software PWM to drive the fan, as for the heaters. This uses a very low frequency
// which is not as annoying as with the hardware PWM. On the other hand, if this frequency
// is too low, you should also increment SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// Incrementing this by 1 will double the software PWM frequency,
// affecting heaters, and the fan if FAN_SOFT_PWM is enabled.
// However, control resolution will be halved for each increment;
// at zero value, there are 128 effective control positions.
#define SOFT_PWM_SCALE 0

// Temperature status LEDs that display the hotend and bet temperature.
// If all hotends and bed temperature and temperature setpoint are < 54C then the BLUE led is on.
// Otherwise the RED led is on. There is 1C hysteresis.
//#define TEMP_STAT_LEDS

// M240  Triggers a camera by emulating a Canon RC-1 Remote
// Data from: http://www.doc-diy.net/photo/rc-1_hacked/
// #define PHOTOGRAPH_PIN     23

// SkeinForge sends the wrong arc g-codes when using Arc Point as fillet procedure
//#define SF_ARC_FIX

// Support for the BariCUDA Paste Extruder.
//#define BARICUDA

//define BlinkM/CyzRgb Support
//#define BLINKM

/*********************************************************************\
* R/C SERVO support
* Sponsored by TrinityLabs, Reworked by codexmas
**********************************************************************/

// Number of servos
//
// If you select a configuration below, this will receive a default value and does not need to be set manually
// set it manually if you have more servos than extruders and wish to manually control some
// leaving it undefined or defining as 0 will disable the servo subsystem
// If unsure, leave commented / disabled
//
//#define NUM_SERVOS 3 // Servo index starts with 0 for M280 command

// Servo Endstops
//
// This allows for servo actuated endstops, primary usage is for the Z Axis to eliminate calibration or bed height changes.
// Use M851 to set the z-probe vertical offset from the nozzle. Store that setting with M500.
//
//#define SERVO_ENDSTOPS {-1, -1, 0} // Servo index for X, Y, Z. Disable with -1
//#define SERVO_ENDSTOP_ANGLES {0,0, 0,0, 70,0} // X,Y,Z Axis Extend and Retract angles

/**********************************************************************\
 * Support for a filament diameter sensor
 * Also allows adjustment of diameter at print time (vs  at slicing)
 * Single extruder only at this point (extruder 0)
 *
 * Motherboards
 * 34 - RAMPS1.4 - uses Analog input 5 on the AUX2 connector
 * 81 - Printrboard - Uses Analog input 2 on the Exp1 connector (version B,C,D,E)
 * 301 - Rambo  - uses Analog input 3
 * Note may require analog pins to be defined for different motherboards
 **********************************************************************/
// Uncomment below to enable
//#define FILAMENT_SENSOR

#define FILAMENT_SENSOR_EXTRUDER_NUM	0  //The number of the extruder that has the filament sensor (0,1,2)
#define MEASUREMENT_DELAY_CM			14  //measurement delay in cm.  This is the distance from filament sensor to middle of barrel

#define DEFAULT_NOMINAL_FILAMENT_DIA  3.0  //Enter the diameter (in mm) of the filament generally used (3.0 mm or 1.75 mm) - this is then used in the slicer software.  Used for sensor reading validation
#define MEASURED_UPPER_LIMIT          3.30  //upper limit factor used for sensor reading validation in mm
#define MEASURED_LOWER_LIMIT          1.90  //lower limit factor for sensor reading validation in mm
#define MAX_MEASUREMENT_DELAY			20  //delay buffer size in bytes (1 byte = 1cm)- limits maximum measurement delay allowable (must be larger than MEASUREMENT_DELAY_CM  and lower number saves RAM)

//defines used in the code
#define DEFAULT_MEASURED_FILAMENT_DIA  DEFAULT_NOMINAL_FILAMENT_DIA  //set measured to nominal initially

//When using an LCD, uncomment the line below to display the Filament sensor data on the last line instead of status.  Status will appear for 5 sec.
//#define FILAMENT_LCD_DISPLAY






#include "Configuration_adv.h"
#include "thermistortables.h"

#endif //CONFIGURATION_H
