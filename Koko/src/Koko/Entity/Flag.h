#ifndef FLAG_H
#define FLAG_H
#include "kkpch.h"

#define KK_NONE			1 << 0
#define KK_SELECTED		1 << 1
#define KK_UPDATENEEDED	1 << 2
#define KK_REMOVE		1 << 3
#define KK_HIDDEN		1 << 4

namespace Koko
{
	class Flag
	{
	private:
		unsigned int m_Bits = KK_NONE;

	public:
		void Enable(int state)
		{
			m_Bits |= state;
		}
		void Disable(int state)
		{
			m_Bits &= ~state;
		}
		bool Check(int state) const
		{
			return (m_Bits & state);
		}

		static std::string ToString(int state)
		{
			switch (state)
			{
			case (KK_NONE):			{ return "None"; }
			case (KK_SELECTED):		{ return "Selected"; }
			case (KK_UPDATENEEDED): { return "Update Needed"; }
			case (KK_REMOVE):		{ return "Remove"; }
			case (KK_HIDDEN):		{ return "Hidden"; }
			default:				{ return "Not a valid state"; }
			}
		}
	};
}

#endif