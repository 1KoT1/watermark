#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>

class Settings : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString watermarkText READ watermarkText WRITE setWitermarkText NOTIFY witermarkTextChanged)
	Q_PROPERTY(int sizeCoef READ sizeCoef WRITE setSizeCoef NOTIFY sizeCoefChanged)
	Q_PROPERTY(QString watermarkFont READ watermarkFont NOTIFY watermarkFontChanged)
	Q_PROPERTY(int watermarkFontId READ watermarkFontId WRITE setWatermarkFontId NOTIFY watermarkFontChanged)

	Q_PROPERTY(QStringList availableFonts READ availableFonts)


public:
	explicit Settings(const QString &watermarkText, int sizeCoef, const QString &watermarkFont, QObject *parent = nullptr);
	explicit Settings(QObject *parent = nullptr);

	const QString &watermarkText() const;
	void setWitermarkText(const QString &watermarkText);

	int sizeCoef() const;
	void setSizeCoef(int sizeCoef);

	const QString &watermarkFont() const;
	int watermarkFontId() const;
	void setWatermarkFontId(int watermarkFontId);

	QStringList availableFonts() const;

	Q_INVOKABLE void save();
signals:
	void witermarkTextChanged();
	void sizeCoefChanged();
	void watermarkFontChanged();

public slots:
private:
	QStringList _fonts;
	QString _watermarkText;
	int _sizeCoef;
	int _watermarkFontId;
};

#endif // SETTINGS_H
