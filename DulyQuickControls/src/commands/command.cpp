#include "commands/command.h"

namespace duly_gui
{
	namespace commands
	{
		Command::Command(const QString &name, bool save) : QEvent(CommandEvent), m_name(name), m_save(save)
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

		QString Command::infos() const
		{
			return m_name + "()";
		}


		std::ostream& operator<<(std::ostream& os, const Command& c)
		{
            return  os << c.infos().constData();
		}
	}
}
