#include <QGuiApplication>
#include <QDebug>
#include <QDir>
#include <QImage>
#include <QPainter>
#include <QPointF>
#include <QString>
#include <QStringList>
#include <exception>

class FileSavingFailed : public std::runtime_error {
public:
	FileSavingFailed (const QString &fileName) : std::runtime_error("File saving failed."), _fileName(fileName) {}
	const QString &fileName() { return _fileName; }
private:
	QString _fileName;
};

void AddTextWatermarkToImage(const QFileInfo &file, const QDir &resDir) {
	qDebug() << file.absoluteFilePath() << endl;
	QImage image(file.absoluteFilePath());
	QPainter p(&image);
	p.setPen(QPen(Qt::white));
	p.setFont(QFont("Times", 10));
	p.drawText(0, 10, QObject::trUtf8("Zarubenko Julia | https://vk.com/phzarubenkoiuliia |"));
	auto resFileName = resDir.filePath(file.fileName());
	if(!image.save(resFileName)) {
		throw FileSavingFailed(resFileName);
	}
}

void AddTextWatermarkToImageList(const QString &dirPath, const QString &resDirPath) {
	QDir directory(dirPath);
	QDir resDir(resDirPath);
	if(!resDir.exists()) {
		if(!resDir.mkpath(resDirPath)) {
			qCritical() << QObject::trUtf8("Не могу создать каталог %0").arg(resDirPath) << endl;
			return;
		}
	}
	auto fileList = directory.entryInfoList({"*.jpg"});
	for (auto file: fileList) {
		AddTextWatermarkToImage(file, resDir);
	}
}

int main(int argc, char *argv[]) {
	QGuiApplication a(argc, argv);
	try
	{
		AddTextWatermarkToImageList("D:/test images", "D:/test images result");
	} catch (FileSavingFailed ex) {
		qCritical() << QObject::trUtf8("Не могу сохранить файл %0").arg(ex.fileName());
	}
}
