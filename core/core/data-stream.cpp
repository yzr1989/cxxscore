#include <core/core/data-stream.h>

namespace Core {

DataStream::DataStream()
		: QDataStream() {
}

DataStream::DataStream(QIODevice *device)
		: QDataStream(device) {
}

DataStream::DataStream(const QByteArray &array)
		: QDataStream(array) {
}

void DataStream::writeThrivedUtf8String(const QString &input) {
	writeThrivedUtf8String(*this, input);
}

QString DataStream::readThrivedUtf8String() {
	return readThrivedUtf8String(*this);
}

void DataStream::writeThrivedUtf8String(DataStream &out, const QString &input) {
	out.writeThrivedNumeric<int>(input.length());
	out.writeRawData(input.toUtf8().constData(), input.length());
}

QString DataStream::readThrivedUtf8String(DataStream &in) {
	int length = in.readThrivedNumeric<int>();
	QByteArray data;
	data.resize(length);
	in.readRawData(data.data(), length);
	return QString::fromUtf8(data);
}
}
