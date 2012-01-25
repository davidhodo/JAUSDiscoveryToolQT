#ifndef URN_IS4S_DISCOVERY_CLIENT_1_0_GUICONTROLENTERED_H
#define URN_IS4S_DISCOVERY_CLIENT_1_0_GUICONTROLENTERED_H

#include "JausUtils.h"
#include "InternalEvents/InternalEvent.h"
namespace urn_is4s_discovery_client_1_0
{

class DllExport GuiControlEntered: public JTS::InternalEvent
{
public:
	class DllExport GuiControlEnteredBody
	{
	public:
		class DllExport GuiControlEnteredRecord
		{
		public:
			void setParent(GuiControlEnteredBody* parent);
			void setParentPresenceVector();
			jUnsignedByte getPresenceVector();
			bool checkPresenceVector(unsigned int index) const;
			jInteger getCommand();
			int setCommand(jInteger value);
			bool isValueValid() const;
			jUnsignedInteger getValue();
			int setValue(jUnsignedInteger value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			GuiControlEnteredRecord &operator=(const GuiControlEnteredRecord &value);
			bool operator==(const GuiControlEnteredRecord &value) const;
			bool operator!=(const GuiControlEnteredRecord &value) const;
			GuiControlEnteredRecord();
			GuiControlEnteredRecord(const GuiControlEnteredRecord &value);
			virtual ~GuiControlEnteredRecord();
		
		protected:
			int setPresenceVector(unsigned int index);
		
			GuiControlEnteredBody* m_parent;
			jUnsignedByte m_PresenceVector;
			jInteger m_Command;
			jUnsignedInteger m_Value;
		};
	
		GuiControlEnteredRecord* const getGuiControlEnteredRecord();
		int setGuiControlEnteredRecord(const GuiControlEnteredRecord &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		GuiControlEnteredBody &operator=(const GuiControlEnteredBody &value);
		bool operator==(const GuiControlEnteredBody &value) const;
		bool operator!=(const GuiControlEnteredBody &value) const;
		GuiControlEnteredBody();
		GuiControlEnteredBody(const GuiControlEnteredBody &value);
		virtual ~GuiControlEnteredBody();
	
	protected:
		GuiControlEnteredRecord m_GuiControlEnteredRecord;
	};

	GuiControlEnteredBody* const getGuiControlEnteredBody();
	int setGuiControlEnteredBody(const GuiControlEnteredBody &value);
	const unsigned int getSize();
	virtual void encode(unsigned char *bytes);
	virtual void decode(const unsigned char *bytes);
	GuiControlEntered &operator=(const GuiControlEntered &value);
	bool operator==(const GuiControlEntered &value) const;
	bool operator!=(const GuiControlEntered &value) const;
	GuiControlEntered();
	GuiControlEntered(const GuiControlEntered &value);
	virtual ~GuiControlEntered();

protected:
	GuiControlEnteredBody m_GuiControlEnteredBody;
};

}

#endif // URN_IS4S_DISCOVERY_CLIENT_1_0_GUICONTROLENTERED_H
