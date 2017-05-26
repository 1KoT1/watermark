#include "settings.h"

Settings::Settings(const QString &watermarkText, int sizeCoef, const QString &watermarkFont, QObject *parent) :
  QObject(parent),
  _watermarkText(watermarkText),
  _sizeCoef(sizeCoef),
  _watermarkFont(watermarkFont)
{

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
