#pragma once

#include <map>
#include <string>
#include <vector>
using namespace std;

#ifndef uint32
typedef unsigned long	uint32;
#endif

#ifndef int32
typedef  long	int32;
#endif

#ifndef uint16
typedef  unsigned short	uint16;
#endif

#if !defined(int32_t)
typedef signed int int32_t;
#endif

#ifdef WIN32
#include <windows.h>
#endif

LPSTR mcs_strdup(LPCSTR s);

class CStringUtils
{
public:
	static BOOL		isNull_Epy(const string& str);
	static BOOL		isBlank(const string& str);
	static string	format(const char *format, ...);
	static wstring	format(const wchar_t *pFormat, ...);
	static void		replace(string &tar, const string & ser, const string & rep) ;
    static void		replace(wstring& tar, const wstring& ser, const wstring& rep);
	static void		split(const string & str, const string & sep, vector<string> &res);
	static void		split(const wstring & str, const wstring & separator, vector<wstring> &result);
	static int		countSubString(string const& str, string const& substr);//countSubStr
	static string	lowerCase(const string & v);
	static string	upperCase(const string & v);
	static void		ltrim(string &v);
	static void		rtrim(string &v);
	static void		rtrim(wstring &v) ;
	static void		trim(string &v);
	static BOOL		toBool(const string& v);
	static char*	toChar(const string& value);
	static int		hexStringToInt(const string& v);
	static void		urlEncode(const string & src, string & dst);//urlEncode
	static void		urlDecode(string & s);//urlDecode
	static wstring   urlDecodeWstr(const wstring& text);
	static string	urlDecodeToGb2312(const string& s);//urlDecodeToGb2312
	static wstring	urlDecodeToUnicode(const string& src);
	static string	urlEncodeToUtf8(const string & src);//urlEncodeToUtf8
	static string	trimEx(const char *str);
	static string	formatTime(time_t lTime, LPCTSTR lpFmt) ;//formatTime
	static string getPriorityValue(const string & a1,const string & b1,const string & defaultvalue);
	static string	newGuid();	//创建一个新的GUID    //newGuid

private:
    static int		vasprintf(char **strp, const char *fmt, va_list ap, int size = 256);
};


//防止json中包含另外一个json字符串，解析失败的情况 ， 请大家不要重复复制代码，想办法减少代码行数，

#define REPLACE_DOUBLE(str) \
CStringUtils::replace(str, "\\", "\\\\");\
CStringUtils::replace(str, "\"", "\\\"");


class CStringTokeners
{
public:
	CStringTokeners(
		LPCSTR srcstr, 
		LPCSTR del_s = "\t\n\r\f ", 
		bool   ret_tokens = false);

	int  countTokens();//countTokens
	bool hasMore();//hasMore

	bool nextToken(string & token);//nextToken

private:
	string              m_srcStr;
	string              m_dels_s;
	bool                m_ret_tokens;
	string::size_type   m_currpos;
	string::size_type   m_maxpos;
};

class CUrlParseTool
{
public:
	CUrlParseTool();
	virtual ~CUrlParseTool();

	void	parse(const string & url_str, bool decode = false);
	string	get_param(const string & key_str);//getParam

	map<string, string >::const_iterator  begin() const	{ return m_list.begin(); }
	map<string, string >::const_iterator  end() const	{ return m_list.end(); }

private:
	map<string, string >   m_list;
};


class CStringConvet
{
public:
	static int      isUTF8String(const string& str);//(0: utf8 1: ASCII) -1: 其他
	static int      isGBKString(const string& str); //(0: GBK 1: ASCII) -1: 其他
	static wstring	stringToWString(const string& str);//stringToWString
	static string	wStringToString(const wstring& wstr);//wStringToString
	static string   toUTF8(const string& str);
	static string   toASCII(const string& str);

	static std::string wstringToGBK(const std::wstring& utf8Data);
	static std::string wstringToUTF8(const std::wstring& utf8Data);

	static std::wstring utf8ToWString(const std::string& utf8Data);
	static std::wstring gbkToWString(const std::string& gbkData);

	static std::string utf8ToGBK(const std::string& utf8Data);
	static std::string gbkToUTF8(const std::string& gbkData);

	static string	encryptionAES(const string& str);//encryptionAES
	static string	decryptionAES(const string& str);//decryptionAES
	static string	decryptionECB(const string& str);//decryptionECB
};
class IMcsBuffer
{
public:
	virtual ~IMcsBuffer() {}

	virtual void	clear() = 0;
	virtual bool	empty() const = 0;
	virtual unsigned char*	data()  const = 0;
	virtual int		size()  const = 0;
};

template<int LOCAL_BUF_SIZE>
class StackAlloc : public IMcsBuffer
{
public:
	StackAlloc()  { this->clear(); }
	virtual ~StackAlloc() {}

	void	clear()       { *data_buf_ = '\0';         }
	bool	empty() const { return false;              }
	unsigned char*	data()  const { return (unsigned char*)data_buf_;   }
	int		size()  const { return sizeof(data_buf_);  }

private:
	char data_buf_[ LOCAL_BUF_SIZE ];
};

//CStringUtils::format()使用中偶发bug，可以使用string(PRT<>("%s_%d",  "hello world", 10))方式替代格式化字符串功能，add by aimingzhang
template < class T = StackAlloc<32> >
class PRT
{
public:
	PRT() : buf_(), str_len_(0) { }

	PRT( LPCSTR pattern, ... ) : buf_(), str_len_(0)
	{
		va_list ap;
		va_start(ap, pattern);
		this->format_ap(pattern, ap);
		va_end(ap);
	}

	LPCSTR format(LPCSTR pattern, ... )
	{
		va_list ap;
		va_start(ap, pattern);
		this->format_ap(pattern, ap);
		va_end(ap);

		return (LPCSTR)this->buf_.data();
	}

	LPCSTR to_upper()
	{
		LPSTR p = buf_.data();
		while (*p != '\0')
		{
			*p = toupper(*p);
			++ p;
		}

		return (LPCSTR)(*this);
	}

	LPCSTR to_lower()
	{
		LPSTR p = (LPSTR)buf_.data();
		while (*p != '\0')
		{
			*p = tolower(*p);
			++ p;
		}

		return (LPCSTR)(*this);
	}

	~PRT()
	{
	}

	operator LPCSTR() const { return (LPCSTR)this->buf_.data(); }
	int      length() const { return this->str_len_;    }

private:
	void format_ap(LPCSTR pattern, va_list ap)
	{
		str_len_ = ::vsnprintf((LPSTR)buf_.data(), buf_.size(), pattern, ap);
		if( str_len_ + 1 > buf_.size() )
		{
			str_len_ = buf_.size() - 1;
			if(str_len_ < 0)
				str_len_ = 0;
		}
	}

private:
	T      buf_;
	int    str_len_;
};