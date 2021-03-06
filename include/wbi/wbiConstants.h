/*
 * Copyright (C) 2013  CoDyCo Consortium
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 *
 * Authors: Andrea Del Prete
 * email: andrea.delprete@iit.it
 */

#ifndef WBI_CONSTANTS_H
#define WBI_CONSTANTS_H

#include <string>

namespace wbi
{
    /** List of available joint control modes. */
    enum ControlMode
    {
        CTRL_MODE_UNKNOWN,
        CTRL_MODE_MOTOR_PWM,    // motor PWM
        CTRL_MODE_POS,          // joint position
        CTRL_MODE_DIRECT_POSITION, //joint direct position (without trajectory generator)
        CTRL_MODE_VEL,          // joint velocity
        CTRL_MODE_TORQUE       // joint torque
    };
    const int CTRL_MODE_SIZE = 6; //number of elements in the ControlMode enum

    /** List of available parameters for the various control modes. */
    enum ControlParam
    {
        CTRL_PARAM_KP,          // proportional gain of PID
        CTRL_PARAM_KI,          // integral gain of PID
        CTRL_PARAM_KD,          // derivative gain of PID
        CTRL_PARAM_OFFSET,      // offset for the control
        CTRL_PARAM_STIFFNESS,   // stiffness of impedance controller
        CTRL_PARAM_DAMPING,     // damping of impedance controller
        CTRL_PARAM_REF_VEL,     // reference velocity for trajectory generator
        CTRL_PARAM_REF_ACC      // reference acceleration for trajectory generator
    };

    /** List of available sensor types. */
    enum SensorType
    {
        // JOINT SPACE SENSORS
        SENSOR_ENCODER_POS,     // joint encoder position
        SENSOR_ENCODER_SPEED,   // joint encoder speed
        SENSOR_ENCODER_ACCELERATION, // joint encoder acceleration
        SENSOR_PWM,             // motor PWM (proportional to motor voltage)
        SENSOR_CURRENT,         // motor current
        SENSOR_TORQUE,          // joint torque

        // CARTESIAN SPACE SENSORS
        SENSOR_IMU,             // 13d inertial measurement unit (4d: axis-angle orientation[rad], 3d: linear acc: ddp[m/s^2], 3d: angular vel: dw[rad/s], magnetometer[] )
        SENSOR_FORCE_TORQUE,    // 6-axis force/torque
        SENSOR_ACCELEROMETER,    // 3d linear acceleration
        SENSOR_GYROSCOPE        // 3d angular velocity
    };
    const int SENSOR_TYPE_SIZE = 10; //number of elements in SensorType enum
    // Legacy value (deprecated)
    extern const SensorType SENSOR_ENCODER;

    //TODO FIXME when we support C++11, add here a static_assert SENSOR_ACCELEROMETER + 1 = SENSOR_TYPE_SIZE


    /** Collection of data to describe a sensor type. */
    class SensorTypeDescription
    {
    public:
        SensorType id;              // id associated to this sensor type
        std::string name;           // name
        std::string description;    // description
        int dataSize;               // size of the data vector returned by a sensor reading
        bool isJointSensor;         // true if this sensor type is associated to a joint

        SensorTypeDescription(SensorType _id, std::string _name, int _dataSize, bool _isJoint, std::string _descr="");
        bool operator ==(const SensorTypeDescription &st);
    };

    /** Descriptions of the available sensor types. */
    extern const SensorTypeDescription sensorTypeDescriptions[SENSOR_TYPE_SIZE];

    /** List of available estimates. */
    enum EstimateType
    {
        // JOINT SPACE ESTIMATES
        ESTIMATE_JOINT_POS,                 // joint position
        ESTIMATE_JOINT_VEL,                 // joint velocity
        ESTIMATE_JOINT_ACC,                 // joint acceleration
        ESTIMATE_JOINT_TORQUE,              // joint torque
        ESTIMATE_JOINT_TORQUE_DERIVATIVE,   // joint torque derivative
        ESTIMATE_JOINT_FORCE_TORQUE,        // joint force torque
        // MOTOR SPACE ESTIMATES
        ESTIMATE_MOTOR_POS,                 // motor position
        ESTIMATE_MOTOR_VEL,                 // motor velocity
        ESTIMATE_MOTOR_ACC,                 // motor acceleration
        ESTIMATE_MOTOR_TORQUE,              // motor torque
        ESTIMATE_MOTOR_TORQUE_DERIVATIVE,   // motor torque derivative
        ESTIMATE_MOTOR_PWM,                 // motor PWM (proportional to motor voltage)
        ESTIMATE_MOTOR_CURRENT,             // motor current
        // CARTESIAN SPACE ESTIMATES
        ESTIMATE_FORCE_TORQUE_SENSOR,       // 6-axis force/torque sensor
        ESTIMATE_IMU,                       // Same of sensor IMU, but filtered
        ESTIMATE_ACCELERATION,              // 3d linear acceleration
        ESTIMATE_ANGVELOCITY,               // 3d angular velocity
        ESTIMATE_BASE_POS,                  // position of the base of the robot
        ESTIMATE_BASE_VEL,                  // velocity of the base of the robot
        ESTIMATE_BASE_ACC,                  // acceleration of the base of the robot
        ESTIMATE_EXTERNAL_FORCE_TORQUE      // 6-axis external force/torque acting on a link
    };
    const int ESTIMATE_TYPE_SIZE = 20; //number of elements in EstimateType enum

    //TODO FIXME when we support C++11, add here a static_assert ESTIMATE_EXTERNAL_FORCE_TORQUE + 1 = ESTIMATE_TYPE_SIZE

    /** List of parameters of estimation algorithms. */
    enum EstimationParameter
    {
        ESTIMATION_PARAM_ADAPTIVE_WINDOW_MAX_SIZE,
        ESTIMATION_PARAM_ADAPTIVE_WINDOW_THRESHOLD,
        ESTIMATION_PARAM_LOW_PASS_FILTER_CUT_FREQ,
        ESTIMATION_PARAM_ENABLE_OMEGA_IMU_DOMEGA_IMU,
        ESTIMATION_PARAM_MIN_TAXEL
    };

} // end namespace

#endif

