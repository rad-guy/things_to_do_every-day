#include "tools/CStringUtils.h"
#include <vector>
#include <tchar.h>
#include <cctype>
#include <algorithm>
#include <atlstr.h>
#include <codecvt>
#include <comutil.h>
#include <regex>
#include <time.h>

LPSTR mcs_strdup(LPCSTR s)
{
	if(!s)
		return NULL;

	LPSTR pDest = new char[strlen(s) + 1];
	if(pDest)
		strcpy(pDest, s);

	return pDest;
}

//////////////////////////////////////////////////////////////////////
// class CStringUtils
//


BOOL CStringUtils::isNull_Epy(const string& str)
{
	if(str.c_str()==NULL)
		return TRUE;
	if(str.empty())
		return TRUE;
	else
		return FALSE;
}

BOOL CStringUtils::isBlank(const string& str)
{
	const std::regex express("\\s + ");
	return isNull_Epy(str) || regex_match(str.begin(), str.end(), express);
}

string CStringUtils::newGuid()
{
	char buffer[64] = { 0 };
	GUID guid;  
	CoCreateGuid(&guid);

	_snprintf_s(buffer, sizeof(buffer),   
		"%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",   
		guid.Data1, guid.Data2, guid.Data3,   
		guid.Data4[0], guid.Data4[1], guid.Data4[2],   
		guid.Data4[3], guid.Data4[4], guid.Data4[5],   
		guid.Data4[6], guid.Data4[7]);

	return buffer;
}

int CStringUtils::vasprintf(char **strp, const char *fmt, va_list ap, int size) 
{
	*strp = (char *) malloc(size);
	int result = 0;
	if ((result = vsnprintf(*strp, size, fmt, ap)) == -1) 
	{
		free(*strp);
		return vasprintf(strp, fmt, ap, size + size / 2);
	} else 
	{
		return result;
	}
}

string CStringUtils::getPriorityValue(const string & a,const string & b,const string & defaultvalue)
{
	if(a.empty()&&b.empty())
		return defaultvalue;
	else if(a.empty())
		return b;
	else
		return a;
}

int  CStringUtils::countSubString(string const& str, string const& substr)
{
	int nCount = 0;

	string::size_type substrSize = substr.size();
	string::size_type idxSub = str.find(substr, 0);
	while (idxSub!=string::npos) {
		++nCount;
		++idxSub;
		idxSub = str.find(substr, idxSub);      
	}
	return nCount;
}

string	CStringUtils::formatTime(time_t lTime, LPCTSTR lpFmt)
{
	struct tm * lpTimeInfo;
	static TCHAR cTime[32];

	memset(cTime, 0, sizeof(cTime));

	lpTimeInfo = localtime(&lTime);
	if (lpTimeInfo != NULL)
		_tcsftime(cTime, sizeof(cTime) / sizeof(TCHAR), lpFmt, lpTimeInfo);

	return CStringConvet::wStringToString(cTime);
}

string CStringUtils::format(const char *pFormat, ...) 
{
	int n = 0;
	char *pBuffer = NULL;
	{
		va_list ap;
		va_start(ap, pFormat);

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif /* __clang__ */

		if (vasprintf(&pBuffer, pFormat, ap) == -1 || !pBuffer) 
		{
			if (pBuffer) free(pBuffer);
			va_end(ap);
			return "";
		}

#ifdef __clang__
#pragma clang diagnostic pop
#endif /* __clang__ */
		va_end(ap);

		n = strlen(pBuffer);
		free(pBuffer);
	}

	char * buffer = (char *) malloc(n + 1);
	memset(buffer, 0, n + 1);

	va_list ap;
	va_start(ap, pFormat);
	size_t ret = ::vsnprintf(buffer, n, pFormat, ap);
	va_end(ap);

	string result = CStringConvet::toUTF8(buffer);
	free(buffer);

	return result;
}

wstring CStringUtils::format(const wchar_t* format, ...) {
	va_list ap;
	va_start(ap, format);
	size_t length = std::vswprintf(nullptr, 0, format, ap);
	if (length <= 0)
	{
		va_end(ap);
		return L"";
	}

	wchar_t* buf = new wchar_t[length + 1];
	std::vswprintf(buf, length + 1, format, ap);

	va_end(ap);

	std::wstring str(buf);
	delete[] buf;
	return std::move(str);
}

void CStringUtils::replace(string &target, const string & search, const string & replacement) 
{
	if (search.compare(replacement) == 0)
		return;

	else if (search.compare("") == 0)
		return;

	string::size_type i = string::npos;
	string::size_type lastPos = 0;
	while ((i = target.find(search, lastPos)) != string::npos) {
		target.replace(i, search.length(), replacement);
		lastPos = i + replacement.length();
	}
}

void CStringUtils::replace(wstring& target, const wstring& search, const wstring& replacement)
{
    if (search.compare(replacement) == 0)
        return;

    else if (search.compare(L"") == 0)
        return;

    string::size_type i = string::npos;
    string::size_type lastPos = 0;
    while ((i = target.find(search, lastPos)) != string::npos) {
        target.replace(i, search.length(), replacement);
        lastPos = i + replacement.length();
    }
}

void CStringUtils::split(const string & str, const string & separator, vector<string> &result) 
{
	result.clear();
	if(CStringUtils::isNull_Epy(str))
		return;
	string::size_type position = str.find(separator);
	string::size_type lastPosition = 0;
	int separatorLength = (int) separator.length();

	while (position != str.npos) 
	{
		result.push_back(str.substr(lastPosition, position - lastPosition));
		lastPosition = position + separatorLength;

		position = str.find(separator, lastPosition);
	}
	result.push_back(str.substr(lastPosition, string::npos));
}

void CStringUtils::split(const wstring & str, const wstring & separator, vector<wstring> &result) 
{
	result.clear();
	if(str.c_str()==NULL || str.empty())
		return;
	wstring::size_type position = str.find(separator);
	wstring::size_type lastPosition = 0;
	int separatorLength = (int) separator.length();

	while (position != str.npos) 
	{
		result.push_back(str.substr(lastPosition, position - lastPosition));
		lastPosition = position + separatorLength;

		position = str.find(separator, lastPosition);
	}
	result.push_back(str.substr(lastPosition, wstring::npos));
}

string changeCase(const string & value, bool lowerCase) 
{
	string newvalue(value);
	for (string::size_type i = 0, l = newvalue.length(); i < l; ++i)
	{
		newvalue[i] = (char) (lowerCase ? tolower(newvalue[i]) : toupper(newvalue[i]));
	}

	return newvalue;
}

void lTrim(string &value) 
{
	string::size_type i = 0;
	for (i = 0; i < value.length(); i++) 
	{
		if (value[i] != ' ' &&
			value[i] != '\t' &&
			value[i] != '\n' &&
			value[i] != '\r')
		{
			break;
		}
	}

	value = value.substr(i);
}

string CStringUtils::lowerCase(const string & value) 
{
	return changeCase(value, true);
}

string CStringUtils::upperCase(const string & value) 
{
	return changeCase(value, false);
}

void CStringUtils::ltrim(string &value) 
{
	string::size_type i = 0;
	for (i = 0; i < value.length(); i++) 
	{
		if (value[i] != ' ' &&
			value[i] != '\t' &&
			value[i] != '\n' &&
			value[i] != '\r')
		{
			break;
		}
	}

	value = value.substr(i);
}

void CStringUtils::rtrim(string &value) 
{
	int32_t i = 0;
	for (i = (int32_t) value.length() - 1; i >= 0; i--) 
	{
		if (value[i] != ' ' &&
			value[i] != '\t' &&
			value[i] != '\n' &&
			value[i] != '\r')
		{
			break;
		}
	}

	value = value.substr(0, i + 1);
}

void CStringUtils::rtrim(wstring &value) 
{
	int32_t i = 0;
	for (i = (int32_t) value.length() - 1; i >= 0; i--) 
	{
		if (value[i] != ' ' &&
			value[i] != '\t' &&
			value[i] != '\n' &&
			value[i] != '\r')
		{
			break;
		}
	}

	value = value.substr(0, i + 1);
}

void CStringUtils::trim(string &value)
{
	ltrim(value);
	rtrim(value);
}

/*字符串是true 或者是1判断为true，其他均为false*/
BOOL CStringUtils::toBool(const string& v)
{
	string lower=CStringUtils::lowerCase(v);
	return (lower.compare("true")==0||lower.compare("1")==0);
}


char* CStringUtils::toChar(const string& v)
{
	char *cstr = new char[v.length() + 1];
	strcpy(cstr,v.c_str());
	return cstr;
}

/**
*将16进制表示的字符串转换为int类型
*/
int CStringUtils::hexStringToInt(const string& v)
{
	int cov=0;
	if(CStringUtils::isNull_Epy(v))
		return cov;
	if(v.find("0x")==string::npos&&v.find("0X")==string::npos)
		return cov;

	char* p = CStringUtils::toChar(v);
	char* q=p;
	/* reach its tail */
	while(*q)
		q++;

	if(*p == '0' && *(p + 1) != 0)
		/* skip "0x" or "0X" */
			p += 2;

	while(*p)
	{
		int c;
		if(*p >= '0' && *p <= '9')
			c = *p - '0';
		else if(*p >= 'A' && *p <= 'F')
			c = *p - 'A' + 0xA;
		else if(*p >= 'a' && *p <= 'f')
			c = *p - 'a' + 0xA;
		else
			/* invalid char */
			return 0;

		cov += c << ((int)(q - p - 1) * 4);
		p++;
	}
	return cov;
}

string CStringUtils::trimEx(const char * pstr)
{
	string out = "";
	int index=0;
	for(int i=0;i<strlen(pstr);i++)
	{
		if( pstr[i] != 0x20)
		{
			out += pstr[i];
		}
	}
	return out;
}

void CStringUtils::urlEncode(const string & src, string & dst)
{
	for( size_t i = 0; i < src.size(); ++ i )
	{
		BYTE c = src[i];

		if ((c >= 'a' && c <= 'z') || 
			(c >= 'A' && c <= 'Z') || 
			(c >= '0' && c <= '9') || 
			c == '.' || c == '-' || c == '_' || c == '*' )
		{
			dst += c;
		}
		//注释空格编码，与js编码统一,否则js解析结果与C++不同 by wd
		//else if( c == ' ')
		//{
		//	dst += '+';
		//}

		else
		{
			char szTmp[10];
			sprintf(szTmp, "%02X", (int)c);

			dst += '%';
			dst += (BYTE)szTmp[0];
			dst += (BYTE)szTmp[1]; 
		}
	}
}

void CStringUtils::urlDecode(string & s)
{
	// orlando protect 0 size string decode here, 2008-3-26 14:21:57
	if(s.length() == 0)
		return;

	LPSTR pE = (LPSTR)(s.c_str() + s.length());
	LPSTR p  = (LPSTR)s.c_str();
	LPSTR q  = p;

	while (p < pE)
	{
		switch (*p)
		{
		case '+' :
			*(q ++) = ' ';
			++ p;
			break;

		case '%' :
			if (*(p + 1) == '%')
			{
				*(q ++) = '%';
				p += 2;
			}
			else
			{
				char ch1 = *(p + 1);
				char ch2 = *(p + 2);
				ch1 = ch1 >= 'A' ? ((ch1 & 0xdf) - 'A' + 10) : ch1 - '0';
				ch2 = ch2 >= 'A' ? ((ch2 & 0xdf) - 'A' + 10) : ch2 - '0';
				*(q ++) = (char)(ch1*16 + ch2);

				p += 3;
			}
			break;

		default :
			*(q ++) = *(p ++);
			break;
		}
	}

	*q = '\0';
	s.resize(q - s.c_str());
}

/**
* 解析包含宽字节字符的函数 和urlDecode 互补，使用方法参考：LPSTR _url = CW2A(url);WDecode(_url);return CString(CA2W(_url, CP_UTF8));
因为utils编译不依赖ATL 此处不直接提供返回CString类型的函数
*/
wstring CStringUtils::urlDecodeWstr(const wstring& text)
{
	//wstring text;
	std::wstring decoded = L"";
	wchar_t temp[] = L"0x00";
	size_t len = text.length();
	int sequence = 0;
	wchar_t conwch = 0;
	for (size_t i = 0; i < len; i++)
	{
		wchar_t wch = text.at(i++);
		if ((wch == '%') && (i + 1 < len))
		{
			temp[2] = text.at(i++);
			temp[3] = text.at(i);
			long tconwch = wcstol(temp, NULL, 16);
			if (tconwch <= 0x7F) {
				decoded += tconwch; // normal ascii char
			}
			else if (tconwch >= 0x80 && tconwch <= 0xBF) { // partial byte
				tconwch = tconwch & 0x3F;
				if (sequence-- == 2)
					tconwch = tconwch << 6;
				conwch |= tconwch;
				if (sequence == 0)
					decoded += conwch;
			}
			else if (tconwch >= 0xC0 && tconwch <= 0xDF) {
				conwch = (tconwch & 0x1F) << 6; // make space for partial bytes
				sequence = 1; // 1 more partial bytes follow
			}
			else if (tconwch >= 0xE0 && tconwch <= 0xEF) {
				conwch = (tconwch & 0xF) << 12; // make space for partial bytes
				sequence = 2; // 2 more partial bytes follow
			} // TODO add case fore 3 partial bytes ... very rare
		}
		else {
			decoded += text.at(--i);
		}
	}
	return  decoded;
}

//路径带有特殊字符处理
wstring CStringUtils::urlDecodeToUnicode(const string& src)
{
	string path = src;
	CStringUtils::urlDecode(path);
	return CStringConvet::stringToWString(path.c_str());
}

string CStringUtils::urlDecodeToGb2312(const string& s)
{
	string dest = s;
	CStringUtils::urlDecode(dest);//urldecode
    if (CStringConvet::isUTF8String(dest) == 0)
        dest = CW2A(CA2W(dest.data(), CP_UTF8));

	return dest;
}

string	CStringUtils::urlEncodeToUtf8(const string & src)
{
	string url, dest;
    if (CStringConvet::isUTF8String(src) != 0)
        dest = CW2A(CA2W(src.data()), CP_UTF8);
    else
        dest = src;
	urlEncode(dest, url);

	return url;
}

//////////////////////////////////////////////////////////////////////
// class CStringTokeners
//

LPCSTR my_assign(LPCSTR src, string & dest)
{
	dest.clear();
	if ( !src )
		return NULL;

	// if src is not NULL, assign to dest
	dest.assign(src);
	return dest.c_str();
}

CStringTokeners::CStringTokeners(LPCSTR src, LPCSTR delims, bool ret)
	: m_srcStr(),
	m_dels_s(),
	m_ret_tokens(ret),
	m_currpos(0),
	m_maxpos(0)
{
	//_ASSERT(src);
	//_ASSERT(delims);

	my_assign(src,    m_srcStr);
	my_assign(delims, m_dels_s);

	m_maxpos = m_srcStr.length();
}

int CStringTokeners::countTokens()
{
	int count = 0;
	string::size_type curr_pos = m_currpos;

	while (curr_pos < m_maxpos) 
	{
		while (!m_ret_tokens && curr_pos < m_maxpos && m_dels_s.find(m_srcStr.at(curr_pos)) != string::npos) 
			++ curr_pos;

		if (curr_pos >= m_maxpos)
			break;

		string::size_type start = curr_pos;

		while (curr_pos < m_maxpos && m_dels_s.find(m_srcStr.at(curr_pos)) == string::npos) 
			++ curr_pos;

		if (m_ret_tokens && start == curr_pos && m_dels_s.find(m_srcStr.at(curr_pos)) != string::npos)
			++ curr_pos;

		++ count;
	}

	return count;
}

bool CStringTokeners::hasMore()
{
	while (!m_ret_tokens && m_currpos < m_maxpos &&  m_dels_s.find(m_srcStr.at(m_currpos)) != string::npos)
		++ m_currpos;

	return m_currpos < m_maxpos;
}

bool CStringTokeners::nextToken(string & token)
{
	if (!this->hasMore())
		return false;

	string::size_type start_pos = m_currpos;
	while (m_currpos < m_maxpos && m_dels_s.find(m_srcStr.at(m_currpos)) == string::npos)
		++ m_currpos;

	if (m_ret_tokens && (start_pos == m_currpos) && m_dels_s.find(m_srcStr.at(m_currpos)) != string::npos)
		++ m_currpos;

	token = m_srcStr.substr(start_pos, m_currpos - start_pos);
	return true;
}

//////////////////////////////////////////////////////////////////////
// class CUrlParseTool
//

CUrlParseTool::CUrlParseTool()
{
}

CUrlParseTool::~CUrlParseTool()
{
}

string CUrlParseTool::get_param(const string & key)
{
	map<string, string >::iterator it = m_list.find(key);
	if (it != m_list.end())
		return it->second;

	return "";
}

void CUrlParseTool::parse(const string & url, bool decode)
{
	int nStartPos = 0, nEndPos   = 0, n = 0;

	string strReq(url);
	if (decode)
		CStringUtils::urlDecode(strReq);

	n = strReq.find('?');
	if (n != string::npos)
		nStartPos = n + 1;

	while (nStartPos != string::npos)
	{
		n = strReq.find('=', nStartPos);
		if (n == string::npos || n <= nStartPos)
			break;

		string key, value;
		key.resize(n - nStartPos);

		strncpy((char*)key.data(), strReq.substr(nStartPos, n - nStartPos).c_str(), n - nStartPos);
		//((char*)key.data())[n - nStartPos] = '\0';

		++ n;       
		nEndPos = strReq.find('&', n);
		if (nEndPos == string::npos)
			nEndPos = strReq.length();

		if (n <= nEndPos)
		{
			value.resize(nEndPos - n);

			strncpy((char*)value.data(), strReq.substr(n, nEndPos - n).c_str(), nEndPos - n);
			//((char*)value.data())[nEndPos - n] = '\0';
		}

		m_list.insert(make_pair(key, value));

		nStartPos = strReq.find('&', n);

		if (nStartPos != string::npos)
			++ nStartPos;
	}
}


//////////////////////////////////////////////////////////////////////
// class CStringConvet
//

bool STD_IsUTF8(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
	try
	{
		converter.from_bytes(str);
		return true;
	}
	catch (const std::range_error&)
	{
		return false;
	}
}

int CStringConvet::isUTF8String(const string& str)
{
	unsigned int nBytes = 0;//UFT8可用1-6个字节编码,ASCII用一个字节
	unsigned char chr = 0;
	bool bAllAscii = true, isUTF8 = false;
	for (int i = 0; i < str.size(); i++)
	{
		chr = str.at(i);
		if (nBytes == 0 && (chr & 0x80) != 0)
			bAllAscii = false;

		if (nBytes == 0)
		{
			//如果不是ASCII码,应该是多字节符,计算字节数
			if (chr >= 0x80)
			{
				if (chr >= 0xFC && chr <= 0xFD)
					nBytes = 6, isUTF8 = true;
				else if (chr >= 0xF8)
					nBytes = 5, isUTF8 = true;
				else if (chr >= 0xF0)
					nBytes = 4, isUTF8 = true;
				else if (chr >= 0xE0)
					nBytes = 3, isUTF8 = true;
				else if (chr >= 0xC0)
					nBytes = 2;
				else
					return -1;

				nBytes--;
			}
		}
		else
		{
			//多字节符的非首字节,应为 10xxxxxx
			if ((chr & 0xC0) != 0x80)
				return -1;
			//减到为零为止
			nBytes--;
		}
	}

	//违返UTF8编码规则
	if (nBytes != 0)
		return -1;

	//如果全部都是ASCII, 也是UTF8
	if (bAllAscii)
		return 1;

	//// 是UTF8，有非ASCII
	//return (isUTF8 || isGBKString(str) < 0) ? 0 : 1;

	// add by xdh at 10/30/23
	if (isUTF8) return 0;

	int is_gbk = isGBKString(str);
	if (is_gbk < 0)
		return 0;
	// 平方 这个字符 isUTF8String isGBKString 都识别不出来
	// 使用 STD_IsUTF8 这个字符可以识别
	// 因为这块代码用的地方实在太多，所以基于以前的逻辑进行修改，不进行大的改动
	if (is_gbk == 0)
	{
		if (STD_IsUTF8(str)) return 0;
		else return -1;
	}

	return 1;
}

int CStringConvet::isGBKString(const string& str)
{
	unsigned int nBytes = 0;//GBK可用1-2个字节编码,中文两个 ,英文一个
	unsigned char chr = 0;
	bool bAllAscii = true; //如果全部都是ASCII,
	for (int i = 0; i < str.size(); i++)
	{
		chr = str.at(i);
		if ((chr & 0x80) != 0 && nBytes == 0)
		{
			// 判断是否ASCII编码,如果不是,说明有可能是GBK
			bAllAscii = false;
		}
		if (nBytes == 0)
		{
			if (chr >= 0x80)
			{
				if (chr >= 0x81 && chr <= 0xFE)
					nBytes = +2;
				else
					return -1;
				nBytes--;
			}
		}
		else
		{
			if (chr < 0x40 || chr>0xFE)
				return -1;
			nBytes--;
		}//else end
	}

	if (nBytes != 0)
	{   //违返规则
		return -1;
	}
	if (bAllAscii)
	{
		//如果全部都是ASCII, 也是GBK
		return 1;
	}
	return 0;
}


wstring CStringConvet::stringToWString(const std::string& str)
{
	try
	{
		wstring result;
		if (CStringConvet::isUTF8String(str) == 0)
			result = utf8ToWString(str);
		else
			result = gbkToWString(str);
		return result;
	}
	catch (const std::exception& e)
	{
		return wstring(CA2W(str.data()));
	}
}


string  CStringConvet::wStringToString(const wstring& src)
{
	string result = wstringToUTF8(src);
	return result;
}

string CStringConvet::toUTF8(const string& src)
{
	if (CStringConvet::isUTF8String(src) == 0)
		return src;

	return gbkToUTF8(src);
}

string CStringConvet::toASCII(const string& src)
{
	if (CStringConvet::isUTF8String(src) == 0)
		return utf8ToGBK(src);
	return src;
}


std::string CStringConvet::wstringToGBK(const std::wstring& utf8Data)
{
	string gbk;
	gbk = CW2A(utf8Data.data());
	return gbk;
}

std::string CStringConvet::wstringToUTF8(const std::wstring& utf8Data)
{
	std::string utf8str;
	utf8str = CW2A(utf8Data.data(), CP_UTF8);
	return utf8str;
}

std::wstring_convert<codecvt_utf8<wchar_t>> utf8conv;

std::wstring CStringConvet::utf8ToWString(const std::string& utf8Data)
{
	std::wstring wString;
	try
	{
		wString = utf8conv.from_bytes(utf8Data);    // utf-8 => wstring	
	}
	catch (...)
	{
		wString = CA2W(utf8Data.data(), CP_UTF8);

	}

	return wString;

}

std::wstring CStringConvet::gbkToWString(const std::string& gbkData)
{
	std::wstring wString;
	wString = CA2W(gbkData.data());
	return wString;
}

std::string CStringConvet::utf8ToGBK(const std::string& utf8Data)
{
	return wstringToGBK(utf8ToWString(utf8Data));
}

std::string CStringConvet::gbkToUTF8(const std::string& gbkData)
{
	return wstringToUTF8(gbkToWString(gbkData));
}