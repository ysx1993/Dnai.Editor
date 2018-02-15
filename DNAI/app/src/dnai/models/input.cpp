#include <QVector2D>
#include "dnai/models/input.h"

namespace dnai {
    namespace models {
        Input::Input(QString const &uid, QString const &name, QString const &description,
                     QString const &type, bool internal, QString const &linked_uid,
                     QObject *parent)
            : Variable(uid, name, description, QVector2D(), type, internal, 0, 0, parent), Identity(linked_uid)
        {

        }

        Input::~Input()
        {

        }

        void Input::serialize(QJsonObject &obj) const
        {
            Variable::serialize(obj);
            Identity::serialize(obj);
        }

        void Input::declare() const
        {

        }

        IClone *Input::clone() const
        {
            return new Input(uid(), name(), description(), varType(), internal(), linked_uid());
        }
    }
}