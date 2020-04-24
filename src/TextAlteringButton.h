//
// Created by smitropoulos on 24/04/2020.
//

#ifndef _TEXTALTERINGBUTTON_H_
#define _TEXTALTERINGBUTTON_H_
#include <QPushButton>


class TextAlteringButton : public QPushButton {
  Q_OBJECT
  public:
    explicit TextAlteringButton(QWidget *parent);
    void updateOnSuccess(QString input);
    void restoreOriginalText();
  private:
    bool m_haveOriginalText{true};
    QString m_prevText{};
};

#endif //_TEXTALTERINGBUTTON_H_
