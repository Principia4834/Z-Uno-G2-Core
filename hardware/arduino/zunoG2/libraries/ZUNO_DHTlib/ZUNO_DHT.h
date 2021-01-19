
#ifndef ZUNO_DHT_H
#define ZUNO_DHT_H

#define DHT_RESULT_OK				ZunoErrorOk
#define DHT_RESULT_PREVIOUS			ZunoErrorDhtResultPrevisous
#define DHT_RESULT_ERROR_NOSYNC		ZunoErrorDhtNoSync
#define DHT_RESULT_ERROR_TIMEOUT	ZunoErrorDhtTimeout
#define DHT_RESULT_ERROR_CRC		ZunoErrorDhtCrc

#define BAD_DHT_VALUE				0x7FFF

typedef enum			DHT_TYPE_SENSORS_e
{
	DHT11,
	DHT21,
	DHT22,
	AM2301 = DHT21
}						DHT_TYPE_SENSORS_t;

typedef union			DHT_TYPE_VALUE_u
{
	uint32_t			value;
	struct
	{
		uint8_t			byte3;
		uint8_t			byte2;
		uint8_t			byte1;
		uint8_t			byte0;
	};
}						DHT_TYPE_VALUE_t;

class DHT {
	public:
		DHT(uint8_t pin, DHT_TYPE_SENSORS_t type = DHT22);
		ZunoError_t								begin(void);
		void									end(void);
		inline ZunoError_t						read(uint8_t bForce=false) {return (this->_read(bForce));};
		int16_t									readTemperatureC10(uint8_t bForce=false);// returns temperature in 10 th of Celsius
		int16_t									readHumidityH10(uint8_t bForce=false);// returns humidity in 10 th of percent
		float									readTemperature(uint8_t bForce=false);// Returns temperature as float in Celsius
		float									readHumidity(uint8_t bForce=false);// Returns humidity as float in pecents
		inline void								getRawData(uint8_t *ptr) {
			ptr[0] = _value.byte0;
			ptr[1] = _value.byte1;
			ptr[2] = _value.byte2;
			ptr[3] = _value.byte3;
			ptr[4] = _crc;
		};
	private:
		static ZunoError_t						_init(size_t param);
		static ZunoError_t						_deInit(size_t param);
		ZunoError_t								_read(uint8_t bForce);
		inline ZunoError_t						_readBody(const void *lpConfig, uint8_t bForce);
		bool                             		_find_startmarker(uint16_t * &b, uint8_t max_size);
		bool                             		_extract_value(uint16_t * &b, uint32_t &value, uint8_t bits=32);
		
		size_t									_lastreadtime;
		DHT_TYPE_VALUE_t						_value;
		uint8_t									_crc;
		uint8_t									_pin;
		DHT_TYPE_SENSORS_t						_type;
		uint8_t									_lpKey;
		uint8_t									_freq;
		ZunoError_t								_result;//last resultat
};

#endif//ZUNO_DHT_H
