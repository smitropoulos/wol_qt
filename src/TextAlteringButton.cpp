//
// Created by smitropoulos on 24/04/2020.
//

#include "TextAlteringButton.h"


TextAlteringButton::TextAlteringButton(QWidget *parent) : QPushButton(parent) { }

void TextAlteringButton::updateOnSuccess(QString input) {

    if ( m_haveOriginalText )
    {
        m_prevText = this->text();
    }
    this->setText(input);
    m_haveOriginalText = false;
}

void TextAlteringButton::restoreOriginalText() {

    if ( !m_haveOriginalText )
    {
        this->setText(m_prevText);
    }
}

