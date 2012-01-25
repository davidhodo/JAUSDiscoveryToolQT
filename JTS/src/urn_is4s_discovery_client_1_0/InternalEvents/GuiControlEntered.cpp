#include "urn_is4s_discovery_client_1_0/InternalEvents/GuiControlEntered.h"

namespace urn_is4s_discovery_client_1_0
{

void GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::setParent(GuiControlEnteredBody* parent)
{
	m_parent = parent;
}

void GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::setParentPresenceVector()
{
	if(m_parent != NULL )
	{
		m_parent->setParentPresenceVector();
	}
}

jUnsignedByte GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::getPresenceVector()
{
	return m_PresenceVector;
}

int GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::setPresenceVector(unsigned int index)
{
	std::bitset<sizeof(jUnsignedByte) * 8> pvBitSet((int)(m_PresenceVector));
	
	pvBitSet[index] = 1;
	m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
	return 0;
}

bool GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::checkPresenceVector(unsigned int index) const
{
	std::bitset<sizeof(jUnsignedByte) * 8> pvBitSet((int)(m_PresenceVector));
	
	return (pvBitSet[index] == 1);
}

jInteger GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::getCommand()
{
	return m_Command;
}

int GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::setCommand(jInteger value)
{
	m_Command = value;
	setParentPresenceVector();
	return 0;
}

bool GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::isValueValid() const
{
	if (checkPresenceVector(0))
	{
		return true;
	}
	return false;
}

jUnsignedInteger GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::getValue()
{
	return m_Value;
}

int GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::setValue(jUnsignedInteger value)
{
	m_Value = value;
	setPresenceVector(0);
	setParentPresenceVector();
	return 0;
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 * 
 * @return
 */
const unsigned int GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::getSize()
{
	unsigned int size = 0;
	
	size += sizeof(jUnsignedByte);
	size += sizeof(jInteger);
	if (checkPresenceVector(0))
	{
		size += sizeof(jUnsignedInteger);
	}
	
	return size;
}

void GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::encode(unsigned char *bytes)
{
	
	if (bytes == NULL)
	{
		return;
	}
	
	int pos = 0;
	jUnsignedByte m_PresenceVectorTemp;
	
	m_PresenceVectorTemp = JSIDL_v_1_0::correctEndianness(m_PresenceVector);
	memcpy(bytes + pos, &m_PresenceVectorTemp, sizeof(jUnsignedByte));
	pos += sizeof(jUnsignedByte);
	jInteger m_CommandTemp;
	
	m_CommandTemp = JSIDL_v_1_0::correctEndianness(m_Command);
	memcpy(bytes + pos, &m_CommandTemp, sizeof(jInteger));
	pos += sizeof(jInteger);
	if (checkPresenceVector(0))
	{
		jUnsignedInteger m_ValueTemp;
		
		m_ValueTemp = JSIDL_v_1_0::correctEndianness(m_Value);
		memcpy(bytes + pos, &m_ValueTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
}

void GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::decode(const unsigned char *bytes)
{
	
	if (bytes == NULL)
	{
		return;
	}
	
	int pos = 0;
	jUnsignedByte m_PresenceVectorTemp;
	
	memcpy(&m_PresenceVectorTemp, bytes + pos, sizeof(jUnsignedByte));
	m_PresenceVector = JSIDL_v_1_0::correctEndianness(m_PresenceVectorTemp);
	pos += sizeof(jUnsignedByte);
	jInteger m_CommandTemp;
	
	memcpy(&m_CommandTemp, bytes + pos, sizeof(jInteger));
	m_Command = JSIDL_v_1_0::correctEndianness(m_CommandTemp);
	pos += sizeof(jInteger);
	if (checkPresenceVector(0))
	{
		jUnsignedInteger m_ValueTemp;
		
		memcpy(&m_ValueTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_Value = JSIDL_v_1_0::correctEndianness(m_ValueTemp);
		pos += sizeof(jUnsignedInteger);
	}
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord &GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::operator=(const GuiControlEnteredRecord &value)
{
	m_PresenceVector = value.m_PresenceVector;
	m_Command = value.m_Command;
	m_Value = value.m_Value;
	
	return *this;
}

bool GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::operator==(const GuiControlEnteredRecord &value) const
{
	if (m_PresenceVector != value.m_PresenceVector)
	{
		return false;
	}
	if (m_Command != value.m_Command)
	{
		return false;
	}
	if (m_Value != value.m_Value)
	{
		return false;
	}
	
	return true;
}

bool GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::operator!=(const GuiControlEnteredRecord &value) const
{
	return !((*this) == value);
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::GuiControlEnteredRecord()
{
	m_parent = NULL;
	m_PresenceVector = 0;
	m_Command = 0;
	m_Value = 0;
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::GuiControlEnteredRecord(const GuiControlEnteredRecord &value)
{
	/// Initiliaze the protected variables
	m_parent = NULL;
	m_PresenceVector = 0;
	m_Command = 0;
	m_Value = 0;
	
	/// Copy the values
	m_PresenceVector = value.m_PresenceVector;
	m_Command = value.m_Command;
	m_Value = value.m_Value;
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord::~GuiControlEnteredRecord()
{
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredRecord* const GuiControlEntered::GuiControlEnteredBody::getGuiControlEnteredRecord()
{
	return &m_GuiControlEnteredRecord;
}

int GuiControlEntered::GuiControlEnteredBody::setGuiControlEnteredRecord(const GuiControlEnteredRecord &value)
{
	m_GuiControlEnteredRecord = value;
	setParentPresenceVector();
	return 0;
}

void GuiControlEntered::GuiControlEnteredBody::setParentPresenceVector()
{
	// Nothing needed here, placeholder function
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 * 
 * @return
 */
const unsigned int GuiControlEntered::GuiControlEnteredBody::getSize()
{
	unsigned int size = 0;
	
	size += m_GuiControlEnteredRecord.getSize();
	
	return size;
}

void GuiControlEntered::GuiControlEnteredBody::encode(unsigned char *bytes)
{
	
	if (bytes == NULL)
	{
		return;
	}
	
	int pos = 0;
	m_GuiControlEnteredRecord.encode(bytes + pos);
	pos += m_GuiControlEnteredRecord.getSize();
}

void GuiControlEntered::GuiControlEnteredBody::decode(const unsigned char *bytes)
{
	
	if (bytes == NULL)
	{
		return;
	}
	
	int pos = 0;
	m_GuiControlEnteredRecord.decode(bytes + pos);
	pos += m_GuiControlEnteredRecord.getSize();
}

GuiControlEntered::GuiControlEnteredBody &GuiControlEntered::GuiControlEnteredBody::operator=(const GuiControlEnteredBody &value)
{
	m_GuiControlEnteredRecord = value.m_GuiControlEnteredRecord;
	m_GuiControlEnteredRecord.setParent(this);
	/// This code is currently not supported
	
	return *this;
}

bool GuiControlEntered::GuiControlEnteredBody::operator==(const GuiControlEnteredBody &value) const
{
	if (m_GuiControlEnteredRecord != value.m_GuiControlEnteredRecord)
	{
		return false;
	}
	/// This code is currently not supported
	return true;
}

bool GuiControlEntered::GuiControlEnteredBody::operator!=(const GuiControlEnteredBody &value) const
{
	return !((*this) == value);
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredBody()
{
	m_GuiControlEnteredRecord.setParent(this);
	/// No Initialization of m_GuiControlEnteredRecord necessary.
}

GuiControlEntered::GuiControlEnteredBody::GuiControlEnteredBody(const GuiControlEnteredBody &value)
{
	/// Initiliaze the protected variables
	m_GuiControlEnteredRecord.setParent(this);
	/// No Initialization of m_GuiControlEnteredRecord necessary.
	
	/// Copy the values
	m_GuiControlEnteredRecord = value.m_GuiControlEnteredRecord;
	m_GuiControlEnteredRecord.setParent(this);
	/// This code is currently not supported
}

GuiControlEntered::GuiControlEnteredBody::~GuiControlEnteredBody()
{
}

GuiControlEntered::GuiControlEnteredBody* const GuiControlEntered::getGuiControlEnteredBody()
{
	return &m_GuiControlEnteredBody;
}

int GuiControlEntered::setGuiControlEnteredBody(const GuiControlEnteredBody &value)
{
	m_GuiControlEnteredBody = value;
	return 0;
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 * 
 * @return
 */
const unsigned int GuiControlEntered::getSize()
{
	unsigned int size = 0;
	
	size += m_GuiControlEnteredBody.getSize();
	
	return size;
}

void GuiControlEntered::encode(unsigned char *bytes)
{
	
	if (bytes == NULL)
	{
		return;
	}
	
	int pos = 0;
	m_GuiControlEnteredBody.encode(bytes + pos);
	pos += m_GuiControlEnteredBody.getSize();
}

void GuiControlEntered::decode(const unsigned char *bytes)
{
	
	if (bytes == NULL)
	{
		return;
	}
	
	int pos = 0;
	m_GuiControlEnteredBody.decode(bytes + pos);
	pos += m_GuiControlEnteredBody.getSize();
}

GuiControlEntered &GuiControlEntered::operator=(const GuiControlEntered &value)
{
	m_GuiControlEnteredBody = value.m_GuiControlEnteredBody;
	
	return *this;
}

bool GuiControlEntered::operator==(const GuiControlEntered &value) const
{
	if (m_GuiControlEnteredBody != value.m_GuiControlEnteredBody)
	{
		return false;
	}
	
	return true;
}

bool GuiControlEntered::operator!=(const GuiControlEntered &value) const
{
	return !((*this) == value);
}

GuiControlEntered::GuiControlEntered()
{
	/// No Initialization of m_GuiControlEnteredBody necessary.
	m_Name = "GuiControlEntered";
}

GuiControlEntered::GuiControlEntered(const GuiControlEntered &value)
{
	/// Initiliaze the protected variables
	/// No Initialization of m_GuiControlEnteredBody necessary.
	m_Name = "GuiControlEntered";
	
	/// Copy the values
	m_GuiControlEnteredBody = value.m_GuiControlEnteredBody;
}

GuiControlEntered::~GuiControlEntered()
{
}


}
