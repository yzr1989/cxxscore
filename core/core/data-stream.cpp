#include <core/core/data-stream.h>

#include <cstring>

using namespace Core;

DataStream::DataStream() {
	m_data.reserve(4096);
}

bool DataStream::readRawData(char *data, i64 size) noexcept {
	std::memcpy(data, m_data.data() + m_seek, size);
	m_seek += size;
	return true;
}

bool DataStream::writeRawData(cchar *data, i64 size) noexcept {
	m_data.resize(m_data.size() + size);
	std::memcpy(m_data.data() + m_seek, data, size);
	m_seek += size;
	return true;
}

DataStream &DataStream::operator<<(const std::string &value) {
	const auto size = static_cast<i32>(value.size());
	writeRawData(reinterpret_cast<cchar *>(&size), sizeof(size));
	writeRawData(value.c_str(), size);
	return *this;
}

DataStream &DataStream::operator>>(std::string &value) {
	i32 size;
	readRawData(reinterpret_cast<char *>(&size), sizeof(size));
	value.resize(size);
	readRawData(const_cast<char *>(value.data()), size);
	return *this;
}

DataStream &DataStream::operator<<(cu64 value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator<<(cu32 value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator<<(cu16 value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator<<(cu8 value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator<<(ci32 value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator<<(ci16 value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator<<(const double value) {
	writeRawData(reinterpret_cast<cchar *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(i64 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(i32 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(i16 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(i8 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(u64 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(u32 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(u16 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(u8 &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

DataStream &DataStream::operator>>(double &value) {
	readRawData(reinterpret_cast<char *>(&value), sizeof(value));
	return *this;
}

auto DataStream::data() const noexcept -> char * { return reinterpret_cast<char *>(const_cast<unsigned char *>(m_data.data())); }
auto DataStream::size() const noexcept -> i32 { return static_cast<i32>(m_data.size()); }

void DataStream::setSize(ci32 size) noexcept {
	m_data.resize(size);
}

bool DataStream::atEnd() const noexcept {
	return m_seek >= m_data.size();
}
