#include "settings.h"
#include <QSettings>

const QString defaultWatermarkText = QObject::trUtf8("Zarubenko Julia | https://vk.com/phzarubenkoiuliia |");
const int defaultSizeCoef = 70;
const QString defaultWatermarkFont = QObject::trUtf8("Times");

Settings::Settings(const QString &watermarkText, int sizeCoef, const QString &watermarkFont, QObject *parent) :
  QObject(parent),
  _watermarkText(watermarkText),
  _sizeCoef(sizeCoef),
  _watermarkFont(watermarkFont)
{

}

Settings::Settings(QObject *parent) :
  QObject(parent)
{
	QSettings settings;
	_watermarkText = settings.value("watermarkText", defaultWatermarkText).toString();
	_sizeCoef = settings.value("sizeCoef", defaultSizeCoef).toInt();
	_watermarkFont = settings.value("watermarkFont", defaultWatermarkFont).toString();
}

const QString & Settings::watermarkText() const {
	return _watermarkText;
}
void Settings::setWitermarkText(const QString &witermarkText) {
	if(_watermarkText != witermarkText) {
		_watermarkText = witermarkText;
		emit witermarkTextChanged();
	}
}

int Settings::sizeCoef() const {
	return _sizeCoef;
}

void Settings::setSizeCoef(int sizeCoef) {
	if(_sizeCoef != sizeCoef) {
		_sizeCoef = sizeCoef;
		emit sizeCoefChanged();
	}
}

const QString &Settings::watermarkFont() const {
	return _watermarkFont;
}

void Settings::setWatermarkFont(const QString &watermarkFont) {
	if(_watermarkFont != watermarkFont) {
		_watermarkFont = watermarkFont;
		emit watermarkFontChanged();
	}
}

void Settings::save() {
	QSettings settings;
	settings.setValue("watermarkText", _watermarkText);
	settings.setValue("sizeCoef", _sizeCoef);
	settings.setValue("watermarkFont", _watermarkFont);
}
