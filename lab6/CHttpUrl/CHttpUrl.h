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
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������
	CHttpUrl(std::string const & url);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(std::string const & domain, std::string const & document, Protocol protocol = HTTP, unsigned short port = 80);

	// ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
	// ���������� ��������� (80 ��� http � 443 ��� https) � URL �� ������ ����������


	std::string GetURL()const;
	// ���������������������
	std::string GetDomain()const;
	/*
	���������� ��� ���������. �������:
	/
	/index.html
	/images/photo.jpg
	*/
	std::string GetDocument()const;
	// ����������������������
	Protocol GetProtocol()const;
	// ��������������������
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