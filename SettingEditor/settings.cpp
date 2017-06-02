#include <algorithm>
#include <iterator>
#include "settings.h"
#include <QFont>
#include <QFontDatabase>
#include <QSettings>

const QString defaultWatermarkText = QObject::trUtf8("Zarubenko Julia | https://vk.com/phzarubenkoiuliia |");
const int defaultSizeCoef = 70;
const QString defaultWatermarkFont = QObject::trUtf8("Times");

Settings::Settings(const QString &watermarkText, int sizeCoef, const QString &watermarkFont, QObject *parent) :
  QObject(parent),
  _watermarkText(watermarkText),
  _sizeCoef(sizeCoef)
{
	_fonts = QFontDatabase().families();
	auto f = std::find(_fonts.begin(), _fonts.end(), watermarkFont);
	_watermarkFontId = f != _fonts.end() ? std::distance(_fonts.begin(), f) : 0;
}

Settings::Settings(QObject *parent) :
  QObject(parent)
{
	QSettings settings;
	_watermarkText = settings.value("watermarkText", defaultWatermarkText).toString();
	_sizeCoef = settings.value("sizeCoef", defaultSizeCoef).toInt();
	auto watermarkFont = settings.value("watermarkFont", defaultWatermarkFont).toString();
	_fonts = QFontDatabase().families();
	auto f = std::find(_fonts.begin(), _fonts.end(), watermarkFont);
	_watermarkFontId = f != _fonts.end() ? std::distance(_fonts.begin(), f) : 0;
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
	return _fonts.at(_watermarkFontId);
}

int Settings::watermarkFontId() const {
	return _watermarkFontId;
}

void Settings::setWatermarkFontId(int watermarkFontId) {
	if(_watermarkFontId != watermarkFontId) {
		_watermarkFontId = watermarkFontId;
		emit watermarkFontChanged();
	}
}

QStringList Settings::availableFonts() const {
	return _fonts;
}

void Settings::save() {
	QSettings settings;
	settings.setValue("watermarkText", _watermarkText);
	settings.setValue("sizeCoef", _sizeCoef);
	settings.setValue("watermarkFont", watermarkFont());
}
