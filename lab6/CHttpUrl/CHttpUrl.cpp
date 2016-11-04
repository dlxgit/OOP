#include "stdafx.h"
#include "CHttpUrl.h"


CHttpUrl::CHttpUrl(std::string const & url)
{
	/*	m_domain = domain;
	m_document = document;
	m_protocol = protocol;
	m_port = port;
	*/
	std::string unparsedPartOfUrl = url;
	std::string protocol = ParseProtocol(url);
	protocol == std::string("http") ? m_protocol = HTTP : m_protocol = HTTPS;

	unparsedPartOfUrl = url.substr(protocol.length() + 3);
	short port = 0;

	
	size_t documentBeginIndex = unparsedPartOfUrl.find('/');
	if (documentBeginIndex != std::string::npos)
	{
		m_document = unparsedPartOfUrl.substr(documentBeginIndex);
		ValidateDocument(GetDocument());
		unparsedPartOfUrl = unparsedPartOfUrl.substr(0, documentBeginIndex);
	}

	ParseDomainAndPort(unparsedPartOfUrl, port);
	ValidateDomain(GetDomain());
	m_port = port;
}


void CHttpUrl::ValidateDomain(const std::string & domain)
{
	for (auto elem : domain)
	{
		if ((elem == 45 || elem == 46 || (elem > 47 && elem < 58) || (elem > 64 && elem < 90) || (elem > 96 && elem < 123)) == 0)
		{
			throw CUrlParsingError("Error: invalid symbols in domain");
		}
	}

	if (domain.find('.') == std::string::npos)
	{
		throw CUrlParsingError("Error: invalid domain");
	}

	if (domain.find(' ') != std::string::npos)
	{
		throw CUrlParsingError("Error: invalid domain");
	}
}

void CHttpUrl::ValidateDocument(const std::string & document)
{
	if (document.find(' ') != std::string::npos)
	{
		throw CUrlParsingError("Error: invalid symbols in document");
	}
}

std::string CHttpUrl::ParseDomainAndPort(const std::string & str, short & port) //finds Domain in given str (url without Protocol)
{
	size_t domainEndIndex = str.find(':');

	if (domainEndIndex == std::string::npos)
	{
		domainEndIndex = str.length();
		port = GetProtocol();
	}
	else
	{
		std::string portStr = str.substr(domainEndIndex + 1, str.length() - domainEndIndex);
		try
		{
			port = std::stoi(portStr);
		}
		catch (std::invalid_argument)
		{
			throw CUrlParsingError("Error: invalid port");
		}
	}

	std::string domain = str.substr(0, domainEndIndex);

	if (domain.length() > 2 && domain[0] == '.')
	{
		throw CUrlParsingError("Error: invalid symbols in domain");
	}

	m_domain = domain;

	return domain;
}

std::string CHttpUrl::ParsePort(const std::string & url)
{
	std::string port;
	return port;
}

std::string CHttpUrl::ParseProtocol(const std::string & url)
{
	if (url.find("http://") == 0)
	{
		return std::string("http");
	}
	else if (url.find("https://") == 0)
	{
		return std::string("https");
	}
	else
	{
		throw(CUrlParsingError("Error parsing Protocol"));
	}
}

std::string GetStringProtocolValue(Protocol protocol)
{
	
	if (protocol == HTTP)
	{
		return std::string("http");
	}
	return std::string("https");
	
}

/* инициализирует URL на основе переданных параметров.
При недопустимости входных параметров выбрасывает исключение
std::invalid_argument
Если имя документа не начинается с символа /, то добавляет / к имени документа
*/

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol, unsigned short port)
{
	ValidateDomain(domain);
	ValidateDocument(document);

	m_domain = domain;
	m_protocol = protocol;
	m_port = port;

	document[0] != '/' ? m_document = '/' + document : m_document = document;
}

// возвращает строковое представление URL-а. Порт, являющийся стандартным для
// выбранного протокола (80 для http и 443 для https) в URL не должен включаться


std::string CHttpUrl::GetURL()const
{
	std::stringstream ss;
	ss << GetPort();
	std::string portStr = ss.str();
	std::string protocolStr = GetStringProtocolValue(GetProtocol());

	return (m_protocol == m_port) ? protocolStr + "://" + GetDomain() + GetDocument() : protocolStr + "://" + GetDomain() + ":" + portStr + GetDocument();
}


// возвращаетдоменноеимя
std::string CHttpUrl::GetDomain()const
{
	return m_domain;
}

/*
Возвращает имя документа. Примеры:
/
/index.html
/images/photo.jpg
*/

std::string CHttpUrl::GetDocument()const
{
	return m_document;
}

// возвращаеттиппротокола
Protocol CHttpUrl::GetProtocol()const
{
	return m_protocol;
}

// возвращаетномерпорта
unsigned short CHttpUrl::GetPort()const
{
	return m_port;
}