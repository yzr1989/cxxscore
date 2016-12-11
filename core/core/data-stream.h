#pragma once

#include <string>
#include <vector>
#include "core/types.h"

namespace Core {

class DataStream {
public:
	explicit DataStream();
	virtual ~DataStream() = default;

	bool readRawData(char *data, i64 size) noexcept;
	bool writeRawData(cchar *data, i64 size) noexcept;

	DataStream &operator << (const std::string& value);
	DataStream &operator >> (std::string& value);

	DataStream &operator << (ci64 value);
	DataStream &operator << (ci32 value);
	DataStream &operator << (ci16 value);
	DataStream &operator << (ci8 value);
	DataStream &operator << (cu64 value);
	DataStream &operator << (cu32 value);
	DataStream &operator << (cu16 value);
	DataStream &operator << (cu8 value);
	DataStream &operator << (const double value);

	DataStream &operator >> (i64 &value);
	DataStream &operator >> (i32 &value);
	DataStream &operator >> (i16 &value);
	DataStream &operator >> (i8 &value);
	DataStream &operator >> (u64 &value);
	DataStream &operator >> (u32 &value);
	DataStream &operator >> (u16 &value);
	DataStream &operator >> (u8 &value);
	DataStream &operator >> (double &value);

private:
	std::vector<byte> m_data;
	i64 m_seek = 0;
};
}
