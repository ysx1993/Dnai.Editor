#ifndef MODEL_IDENTITY_H
#define MODEL_IDENTITY_H

#include <QString>
#include "models/imodel.h"

namespace duly_gui {
    namespace models {
        class Identity: virtual public IModel
        {
        public:
            Identity(QString const &, QString const &);
            virtual ~Identity();

            QString uid() const;
            void setUid(const QString &uid);

            QString linked_uid() const;
            void setLinked_uid(const QString &linked_uid);

        private:
            QString m_uid;
            QString m_linked_uid;

            // IModel interface
        public:
            virtual void serialize(QJsonObject &) const;
        };
    }
}

#endif // MODEL_IDENTITY_H
