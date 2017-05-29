#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>

class Settings : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString watermarkText READ watermarkText WRITE setWitermarkText NOTIFY witermarkTextChanged)
	Q_PROPERTY(int sizeCoef READ sizeCoef WRITE setSizeCoef NOTIFY sizeCoefChanged)
	Q_PROPERTY(QString watermarkFont READ watermarkFont WRITE setWatermarkFont NOTIFY watermarkFontChanged)


public:
	explicit Settings(const QString &watermarkText, int sizeCoef, const QString &watermarkFont, QObject *parent = nullptr);
	explicit Settings(QObject *parent = nullptr);

	const QString &watermarkText() const;
	void setWitermarkText(const QString &watermarkText);

	int sizeCoef() const;
	void setSizeCoef(int sizeCoef);

	const QString &watermarkFont() const;
	void setWatermarkFont(const QString &watermarkFont);
signals:
	void witermarkTextChanged();
	void sizeCoefChanged();
	void watermarkFontChanged();

public slots:
private:
	QString _watermarkText;
	int _sizeCoef;
	QString _watermarkFont;
};

#endif // SETTINGS_H
