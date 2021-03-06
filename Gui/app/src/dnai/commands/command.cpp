#include "dnai/commands/command.h"

namespace dnai
{
	namespace commands
	{
        const QEvent::Type Command::CommandEvent = static_cast<QEvent::Type>(QEvent::registerEventType());
        Command::Command(const QString &name, bool save) :
            QEvent(CommandEvent),
            m_name(name),
            m_save(save)
		{
		}

		void Command::execute() const
		{
			
		}

		void Command::unExcute() const
		{
			
		}

		void Command::executeSave()
		{
		}

		bool Command::isSave() const
		{
			return m_save;
		}

		const QString& Command::name() const
		{
			return m_name;
		}

		QString Command::infos() const
		{
			return m_name + "()";
        }
	}
}
