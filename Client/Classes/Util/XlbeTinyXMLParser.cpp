#include "XlbeResourceProvider.h"
#include "XlbeXMLHandler.h"
#include "XlbeXMLAttributes.h"
#include "XlbeTinyXmlParser.h"
#include "XlbeDefualtResourceProvider.h"
#include "XlbeEncryptResourceProvider.h"
#include "xlbetinyxml/tinyxml.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace xlbe {

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tiny_Xml_Document : public xlbe_tinyxml_namespace::TiXmlDocument
{
public:
	Tiny_Xml_Document(Xml_Handler* handler, const std::string& filename, bool encrypt);
    ~Tiny_Xml_Document() {}

protected:
    void process_element(const xlbe_tinyxml_namespace::TiXmlElement* element);

private:
    Xml_Handler* handler_;
};

Tiny_Xml_Document::Tiny_Xml_Document(Xml_Handler* handler, const std::string& filename, bool encrypt)
{
    handler_ = handler;

	Raw_Data_Container raw_xml_data;
	Resource_Provider *resource_provider = 0;

	if (encrypt)
	{
		resource_provider = new Encrypt_Resource_Provider;
	}
	else
	{
		resource_provider = new Default_Resource_Provider;
	}

	resource_provider->load_raw_data_container(filename, raw_xml_data);

    size_t size = raw_xml_data.get_size();
    char* buf = new char[size + 2];
    memcpy(buf, raw_xml_data.get_data_ptr(), size);

    buf[size] = '\n';
    buf[size+1] = 0;

    xlbe_tinyxml_namespace::TiXmlDocument doc;
    if (!doc.Parse((const char*)buf))
    {
        delete[] buf;
		resource_provider->unload_raw_data_container(raw_xml_data);
		delete resource_provider;

		assert(false);
		return ;
    }

    const xlbe_tinyxml_namespace::TiXmlElement* curr_element = doc.RootElement();
    if (curr_element)
    {
        try
        {
            process_element(curr_element);
        }
        catch(...)
        {
            delete [] buf;
			resource_provider->unload_raw_data_container(raw_xml_data);
			delete resource_provider
				;
			assert(false);
			return;
        }
    }

    delete [] buf;
	resource_provider->unload_raw_data_container(raw_xml_data);
	delete resource_provider;
}


void Tiny_Xml_Document::process_element(const xlbe_tinyxml_namespace::TiXmlElement* element)
{
    Xml_Attributes attrs;

    const xlbe_tinyxml_namespace::TiXmlAttribute *curr_attr = element->FirstAttribute();
    while (curr_attr)
    {
        attrs.insert(curr_attr->Name(), curr_attr->Value());
        curr_attr = curr_attr->Next();
    }

    handler_->element_start(element->Value(), attrs);

    const xlbe_tinyxml_namespace::TiXmlNode* child_node = element->FirstChild();
    while (child_node)
    {
        switch(child_node->Type())
        {
        case xlbe_tinyxml_namespace::TiXmlNode::ELEMENT:
            process_element(child_node->ToElement());
            break;
        case xlbe_tinyxml_namespace::TiXmlNode::TEXT:
            if (child_node->ToText()->Value() != '\0')
                handler_->text(child_node->ToText()->Value());
            break;
        };

        child_node = child_node->NextSibling();
    }

    handler_->element_end(element->Value());
}

Tiny_Xml_Parser::Tiny_Xml_Parser()
{
}

Tiny_Xml_Parser::~Tiny_Xml_Parser()
{}

void Tiny_Xml_Parser::parse_xml_file(Xml_Handler* handler, const std::string& filename, bool encrypt)
{
	Tiny_Xml_Document doc(handler, filename, encrypt);
}


bool Tiny_Xml_Parser::initialise_impl()
{
    return true;
}

void Tiny_Xml_Parser::cleanup_impl(void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
} 
