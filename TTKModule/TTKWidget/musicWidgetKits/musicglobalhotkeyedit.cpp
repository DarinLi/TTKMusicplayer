#include "musicglobalhotkeyedit.h"
#include "musichotkeymanager.h"
#include "musicuiobject.h"

#include <QKeyEvent>

MusicGlobalHotKeyEdit::MusicGlobalHotKeyEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setReadOnly(true);
}

MusicGlobalHotKeyEdit::~MusicGlobalHotKeyEdit()
{

}

void MusicGlobalHotKeyEdit::setHotKeyEnabled(bool state)
{
    setEnabled(state);
    setReadOnly(!state);
    setStyleSheet(state ? MusicUIObject::MBackgroundStyle05 : MusicUIObject::MBackgroundStyle08);
}

void MusicGlobalHotKeyEdit::keyPressEvent(QKeyEvent *event)
{
    setText(M_HOTKEY_PTR->toString(event->key(), event->modifiers()));
}
