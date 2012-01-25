#ifndef URN_IS4S_DISCOVERY_CLIENT_1_0_REPORTCONFIGURATION_H
#define URN_IS4S_DISCOVERY_CLIENT_1_0_REPORTCONFIGURATION_H

#include "JausUtils.h"
#include "Messages/Message.h"
#include "JConstants.h"
namespace urn_is4s_discovery_client_1_0
{

class DllExport ReportConfiguration: public JTS::Message
{
public:
	static const int ID = 0x4b01;
	
	class DllExport AppHeader
	{
	public:
		class DllExport HeaderRec
		{
		public:
			void setParent(AppHeader* parent);
			void setParentPresenceVector();
			jUnsignedShortInteger getMessageID();
			int setMessageID(jUnsignedShortInteger value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			HeaderRec &operator=(const HeaderRec &value);
			bool operator==(const HeaderRec &value) const;
			bool operator!=(const HeaderRec &value) const;
			HeaderRec();
			HeaderRec(const HeaderRec &value);
			virtual ~HeaderRec();
		
		protected:
			AppHeader* m_parent;
			jUnsignedShortInteger m_MessageID;
		};
	
		HeaderRec* const getHeaderRec();
		int setHeaderRec(const HeaderRec &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		AppHeader &operator=(const AppHeader &value);
		bool operator==(const AppHeader &value) const;
		bool operator!=(const AppHeader &value) const;
		AppHeader();
		AppHeader(const AppHeader &value);
		virtual ~AppHeader();
	
	protected:
		HeaderRec m_HeaderRec;
	};
	class DllExport Body
	{
	public:
		class DllExport NodeList
		{
		public:
			class DllExport NodeSeq
			{
			public:
				class DllExport NodeRec
				{
				public:
					void setParent(NodeSeq* parent);
					void setParentPresenceVector();
					jUnsignedByte getNodeID();
					int setNodeID(jUnsignedByte value);
					const unsigned int getSize();
					virtual void encode(unsigned char *bytes);
					virtual void decode(const unsigned char *bytes);
					NodeRec &operator=(const NodeRec &value);
					bool operator==(const NodeRec &value) const;
					bool operator!=(const NodeRec &value) const;
					NodeRec();
					NodeRec(const NodeRec &value);
					virtual ~NodeRec();
				
				protected:
					NodeSeq* m_parent;
					jUnsignedByte m_NodeID;
				};
				class DllExport ComponentList
				{
				public:
					class DllExport ComponentRec
					{
					public:
						void setParent(ComponentList* parent);
						void setParentPresenceVector();
						jUnsignedByte getComponentID();
						int setComponentID(jUnsignedByte value);
						jUnsignedByte getInstanceID();
						int setInstanceID(jUnsignedByte value);
						const unsigned int getSize();
						virtual void encode(unsigned char *bytes);
						virtual void decode(const unsigned char *bytes);
						ComponentRec &operator=(const ComponentRec &value);
						bool operator==(const ComponentRec &value) const;
						bool operator!=(const ComponentRec &value) const;
						ComponentRec();
						ComponentRec(const ComponentRec &value);
						virtual ~ComponentRec();
					
					protected:
						ComponentList* m_parent;
						jUnsignedByte m_ComponentID;
						jUnsignedByte m_InstanceID;
					};
				
					void setParent(NodeSeq* parent);
					void setParentPresenceVector();
					unsigned int getNumberOfElements() const;
					ComponentRec* const getElement(unsigned int index);
					int setElement(unsigned int index, const ComponentRec &value);
					int addElement(const ComponentRec &value);
					int deleteElement(unsigned int index);
					int deleteLastElement();
					const unsigned int getSize();
					virtual void encode(unsigned char *bytes);
					virtual void decode(const unsigned char *bytes);
					ComponentList &operator=(const ComponentList &value);
					bool operator==(const ComponentList &value) const;
					bool operator!=(const ComponentList &value) const;
					ComponentList();
					ComponentList(const ComponentList &value);
					virtual ~ComponentList();
				
				protected:
					NodeSeq* m_parent;
					std::vector<ComponentRec> m_ComponentRec;
				};
			
				void setParent(NodeList* parent);
				void setParentPresenceVector();
				NodeRec* const getNodeRec();
				int setNodeRec(const NodeRec &value);
				ComponentList* const getComponentList();
				int setComponentList(const ComponentList &value);
				const unsigned int getSize();
				virtual void encode(unsigned char *bytes);
				virtual void decode(const unsigned char *bytes);
				NodeSeq &operator=(const NodeSeq &value);
				bool operator==(const NodeSeq &value) const;
				bool operator!=(const NodeSeq &value) const;
				NodeSeq();
				NodeSeq(const NodeSeq &value);
				virtual ~NodeSeq();
			
			protected:
				NodeList* m_parent;
				NodeRec m_NodeRec;
				ComponentList m_ComponentList;
			};
		
			void setParent(Body* parent);
			void setParentPresenceVector();
			unsigned int getNumberOfElements() const;
			NodeSeq* const getElement(unsigned int index);
			int setElement(unsigned int index, const NodeSeq &value);
			int addElement(const NodeSeq &value);
			int deleteElement(unsigned int index);
			int deleteLastElement();
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			NodeList &operator=(const NodeList &value);
			bool operator==(const NodeList &value) const;
			bool operator!=(const NodeList &value) const;
			NodeList();
			NodeList(const NodeList &value);
			virtual ~NodeList();
		
		protected:
			Body* m_parent;
			std::vector<NodeSeq> m_NodeSeq;
		};
	
		NodeList* const getNodeList();
		int setNodeList(const NodeList &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		Body &operator=(const Body &value);
		bool operator==(const Body &value) const;
		bool operator!=(const Body &value) const;
		Body();
		Body(const Body &value);
		virtual ~Body();
	
	protected:
		NodeList m_NodeList;
	};

	unsigned int getID() { return ID; };
	AppHeader* const getAppHeader();
	int setAppHeader(const AppHeader &value);
	Body* const getBody();
	int setBody(const Body &value);
	const unsigned int getSize();
	virtual void encode(unsigned char *bytes);
	virtual void decode(const unsigned char *bytes);
	ReportConfiguration &operator=(const ReportConfiguration &value);
	bool operator==(const ReportConfiguration &value) const;
	bool operator!=(const ReportConfiguration &value) const;
	ReportConfiguration();
	ReportConfiguration(const ReportConfiguration &value);
	virtual ~ReportConfiguration();

protected:
	AppHeader m_AppHeader;
	Body m_Body;
};

}

#endif // URN_IS4S_DISCOVERY_CLIENT_1_0_REPORTCONFIGURATION_H
