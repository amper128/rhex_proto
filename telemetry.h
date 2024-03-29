/**
 * @file telemetry.h
 * @author Алексей Хохлов <root@amper.me>
 * @copyright WTFPL License
 * @date 2021
 * @brief Описание структур данных телеметрии
 */

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//#define VOT_SC (0xB01EDEADU)
#define VOT_SC (0xADDE1EB0U)
#define VOT_CRC_Init 0xFFFF

typedef struct __attribute__((packed)) {
	uint32_t StartCode;	     //  0xB01EDEAD
	uint32_t TimestampMS;	     // -not used- timestamp in milliseconds
	int32_t BaroAltitudecm;	     // -fl baro_altitude- zero referenced (from home position)
				     // barometric altitude in cm
	uint16_t AirspeedKPHX10;     // -fl airspeed- KPH * 10, requires optional pitot sensor
	int16_t ClimbRateMSX100;     // -fl vario - meters/second * 100
	uint16_t RPM;		     // -not used- requires optional RPM sensor
	int16_t PitchDegrees;	     // -i16 pitch-
	int16_t RollDegrees;	     // -i16 roll-
	int16_t YawDegrees;	     // -fl heading-
	int16_t AccelXCentiGrav;     // -not used-
	int16_t AccelYCentiGrav;     // -not used-
	int16_t AccelZCentiGrav;     // -not used-
	uint16_t PackVoltageX100;    // -fl voltage-
	uint16_t VideoTxVoltageX100; // -fl vtxvoltage
	uint16_t CameraVoltageX100;  // -fl camvoltage
	uint16_t RxVoltageX100;	     // -fl rxvoltage
	uint16_t PackCurrentX100;    // -fl ampere-
	int16_t TempDegreesCX10;     // -i16 temp- degrees C * 10, from optional temperature sensor
	uint16_t mAHConsumed;	     // -u16 mahconsumed-
	uint16_t CompassDegrees; // -u16 compassdegrees used- either magnetic compass reading (if
				 // compass enabled) or filtered GPS course over ground if not
	uint8_t RSSIPercent;	 // -u8 rssi-
	uint8_t LQPercent;	 // -u8 LQ-
	int32_t LatitudeX1E7;	 // -dbl latitude- (degrees * 10,000,000 )
	int32_t LongitudeX1E7;	 // -dbl longitude- (degrees * 10,000,000 )
	uint32_t DistanceFromHomeMX10; // -fl distance- horizontal GPS distance from home point, in
				       // meters X 10 (decimeters)
	uint16_t GroundspeedKPHX10;    // -fl speed- ( km/h * 10 )
	uint16_t CourseDegreesX10;     // -u16 coursedegrees- GPS course over ground, in degrees
	int32_t GPSAltitudecm;	       // -fl altitude- ( GPS altitude, using WGS-84 ellipsoid, cm)
	uint8_t HDOPx10;	       // -fl hdop- GPS HDOP * 10
	uint8_t SatsInUse;	       // -u8 sats- satellites used for navigation
	uint8_t PresentFlightMode;     // -u8 uav_flightmode- present flight mode, as defined in
				       // VECTOR_FLIGHT_MODES
	uint8_t RFU[24];	       // -not used- reserved for future use
	uint16_t CRC;
} vector_telemetry_t; // 97 bytes

struct rssi_data_t {
	int8_t signal;
	uint32_t lostpackets;
	int8_t signal_rc;
	uint32_t lostpackets_rc;
	uint8_t cpuload;
	uint8_t temp;
	uint32_t injected_block_cnt;
	uint32_t skipped_fec_cnt;
	uint32_t injection_fail_cnt;
	uint64_t injection_time_block;
	uint16_t bitrate_kbit;
	uint16_t bitrate_measured_kbit;
	uint8_t cts;
	uint8_t undervolt;
} __attribute__((__packed__));

#ifdef __cplusplus
}
#endif
