#pragma once

#include <QDataStream>

namespace Core {

//! Klasa zarzadzajaca strumieniami, rozszerza QDataStream o przydatne metody
class DataStream : public QDataStream {
public:
	explicit DataStream();
	explicit DataStream(QIODevice *device);
	explicit DataStream(const QByteArray &array);
	virtual ~DataStream() = default;

	/// Enum zawierajacy magic numbery wykorzystane do oszczednej notacji
	enum ThrivedLogic : uint8_t {
		/// Oznacza 7-biotwe kodowanie informacji (na tej podstawie dane sa przesowane bitowo)
		SevenBitEncoding = 7,
		/// Najstarszy bit 8bitowego slowa, zapalony decyduje o tym ze nalezy przeczytac kolejny bajt informacji
		HighestBit = 0x80,
		/// Maska na 7 bitow znaczonych (dane)
		DataMask = 0x7F
	};

	/// Odczyt typu numerycznego oszczedzajac bajty (najstarszy bajt mowi o dodatkowym bajcie)
	template <typename type>
	type readThrivedNumeric();

	/// Zapis typu numerycznego oszczedzajac bajty (najstarszy bajt mowi o dodatkowym bajcie)
	template <typename type>
	void writeThrivedNumeric(const type &value);

	/// Odczyt typu numerycznego oszczedzajac bajty (wersja statyczna)
	template <typename type>
	static type readThrivedNumeric(DataStream &in);

	/// Zapis typu numerycznego oszczedzajac bajty (wersja statyczna)
	template <typename type>
	static void writeThrivedNumeric(DataStream &out, type value);

	void writeThrivedUtf8String(const QString &input);
	QString readThrivedUtf8String();

	static void writeThrivedUtf8String(DataStream &out, const QString &input);
	static QString readThrivedUtf8String(DataStream &in);
};

template <typename type>
void DataStream::writeThrivedNumeric(const type &value) {
	writeThrivedNumeric<type>(*this, value);
}

template <typename type>
type DataStream::readThrivedNumeric() {
	return readThrivedNumeric<type>(*this);
}

template <typename type>
type DataStream::readThrivedNumeric(DataStream &in) {
	static_assert(std::is_integral<type>::value, "numeric type required.");
	type value = 0;
	uint8_t data;
	int i = 0;

	do {
		data = 0;
		in.readRawData(reinterpret_cast<char *>(&data), sizeof(data));
		value |= static_cast<type>(data & DataMask) << (SevenBitEncoding * i++);
	} while (data & HighestBit);

	return value;
}

template <typename type>
void DataStream::writeThrivedNumeric(DataStream &out, type value) {
	static_assert(std::is_integral<type>::value, "numeric type required.");

	while (true) {
		uint8_t data = (value & DataMask);

		if (value >>= SevenBitEncoding)
			data |= HighestBit;

		out.writeRawData(reinterpret_cast<char *>(&data), sizeof(data));

		if (!value)
			return;
	}
}
}
