#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include "CUrlParsingError.h"
#include <sstream>

enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};


class CHttpUrl
{
public:
	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(std::string const & url);

	/* инициализирует URL на основе переданных параметров.
	При недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol = HTTP, unsigned short port = 80);

	// возвращает строковое представление URL-а. Порт, являющийся стандартным для
	// выбранного протокола (80 для http и 443 для https) в URL не должен включаться


	std::string GetURL()const;
	// возвращаетдоменноеимя
	std::string GetDomain()const;
	/*
	Возвращает имя документа. Примеры:
	/
	/index.html
	/images/photo.jpg
	*/
	std::string GetDocument()const;
	// возвращаеттиппротокола
	Protocol GetProtocol()const;
	// возвращаетномерпорта
	unsigned short GetPort()const;
	
	std::string ParseProtocol(const std::string & url);
	std::string ParseDomainAndPort(const std::string & url, short & port);
	std::string ParsePort(const std::string & url);
	void ValidateDocument(const std::string & document);
	void ValidateDomain(const std::string & domain);
private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};

std::string GetStringProtocolValue(Protocol protocol);