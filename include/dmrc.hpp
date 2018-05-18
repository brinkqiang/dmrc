

#ifndef __DMRC_HPP_INCLUDE__
#define __DMRC_HPP_INCLUDE__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <string>

#include "dmrc.h"

class CDMRC
{
public:
    CDMRC()
    {
        SetEncryptKey(m_strEncryptKey);
        SetDecryptKey(m_strDecryptKey);
    }

    void SetKey(const std::string& strtKey)
    {
        SetEncryptKey(strtKey);
        SetDecryptKey(strtKey);
    }

    void SetEncryptKey(const std::string& strEncryptKey)
    {
        m_strEncryptKey = strEncryptKey;
        m_strEncryptKey.resize(256);
        arc4_setup(&m_oEncryptContext, (const unsigned char*)m_strEncryptKey.c_str(), (unsigned int)m_strEncryptKey.size());
    }

    void SetDecryptKey(const std::string& strDecryptKey)
    {
        m_strDecryptKey = strDecryptKey;
        m_strDecryptKey.resize(256);
        arc4_setup(&m_oDecryptContext, (const unsigned char*)m_strDecryptKey.c_str(), (unsigned int)m_strDecryptKey.size());
    }

    std::string& Encrypt(std::string& strBuf)
    {
        arc4_crypt( &m_oEncryptContext, strBuf.size(), (const unsigned char*)strBuf.data(), (unsigned char*)strBuf.data());
        return strBuf;
    }

    char* Encrypt(char* pBuf, size_t len)
    {
        arc4_crypt( &m_oEncryptContext, len, (unsigned char*)pBuf, (unsigned char*)pBuf);
        return pBuf;
    }

    unsigned char* Encrypt(unsigned char* pBuf, size_t len)
    {
        arc4_crypt( &m_oEncryptContext, len, pBuf, pBuf);
        return pBuf;
    }

    std::string& Decrypt(std::string& strBuf)
    {
        arc4_crypt( &m_oDecryptContext, strBuf.size(), (const unsigned char*)strBuf.data(), (unsigned char*)strBuf.data());
        return strBuf;
    }

    unsigned char* Decrypt(unsigned char* pBuf, size_t len)
    {
        arc4_crypt( &m_oDecryptContext, len, pBuf, pBuf);
        return pBuf;
    }

    char* Decrypt(char* pBuf, size_t len)
    {
        arc4_crypt( &m_oDecryptContext, len,  (const unsigned char*)pBuf,  (unsigned char*)pBuf);
        return pBuf;
    }
private:
    std::string m_strEncryptKey;
    std::string m_strDecryptKey;

    arc4_context m_oEncryptContext;
    arc4_context m_oDecryptContext;
};

#endif // __DMRC_HPP_INCLUDE__
