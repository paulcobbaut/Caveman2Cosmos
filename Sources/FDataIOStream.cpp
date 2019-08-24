
//	AIAndy: An implementation of FDataStreamBase for manual caching, based on fstream

#include "CvGameCoreDLL.h"
#include "FDataIOStream.h"

void FDataIOStream::OpenRead(CvString szFile)
{
	stream.open(szFile.c_str(),std::ios::binary | std::ios::in);
}

void FDataIOStream::OpenWrite(CvString szFile)
{
	stream.open(szFile.c_str(),std::ios::binary | std::ios::out | std::ios::trunc);
	FAssert(stream.good());
}

void FDataIOStream::Close()
{
	stream.close();
}

bool FDataIOStream::IsOpen()
{
	return stream.is_open();
}

void FDataIOStream::Rewind()
{

}

bool FDataIOStream::AtEnd()
{
	return true;
}

void FDataIOStream::FastFwd()
{

}

unsigned int FDataIOStream::GetPosition() const
{
	return 0;
}

void FDataIOStream::SetPosition(unsigned int position)
{

}

void FDataIOStream::Truncate()
{

}

void FDataIOStream::Flush()
{

}

unsigned int FDataIOStream::GetEOF() const
{
	return 0;
}

unsigned int FDataIOStream::GetSizeLeft() const
{
	return 0;
}

void FDataIOStream::CopyToMem(void *mem)
{

}

unsigned int FDataIOStream::WriteString(const wchar *szName)
{
	stream.write((char*)szName, (std::wcslen(szName) + 1) * sizeof (wchar));
	FAssert(stream.good());
	return 0;
}

unsigned int FDataIOStream::WriteString(const char *szName)
{
	stream.write(szName, std::strlen(szName) + 1);
	FAssert(stream.good());
	return 0;
}

unsigned int FDataIOStream::WriteString(const std::string& szName)
{
	stream.write(szName.c_str(), szName.length() + 1);
	FAssert(stream.good());
	return 0;
}

unsigned int FDataIOStream::WriteString(const std::wstring& szName)
{
	stream.write((char*)szName.c_str(), (szName.length() + 1) * sizeof (wchar));
	FAssert(stream.good());
	return 0;
}

unsigned int FDataIOStream::WriteString(int count, std::string values[])
{
	for (int i=0; i<count; i++)
	{
		WriteString(values[i]);
	}
	return 0;
}

unsigned int FDataIOStream::WriteString(int count, std::wstring values[])
{
	for (int i=0; i<count; i++)
	{
		WriteString(values[i]);
	}
	return 0;
}
	
unsigned int FDataIOStream::ReadString(char *szName)
{
	char c;
	do
	{
		stream.get(c);
		*szName = c;
		szName++;
	}
	while (c != '\0');
	FAssert(stream.good());
	return 0;
}
unsigned int FDataIOStream::ReadString(wchar *szName)
{
	wchar c;
	do
	{
		stream.read((char*)&c, sizeof(wchar));
		*szName = c;
		szName++;
	}
	while (c != L'\0');
	FAssert(stream.good());
	return 0;
}
unsigned int FDataIOStream::ReadString(std::string& szName)
{
	char c;
	stream.get(c);
	szName.clear();

	while (c != '\0')
	{
		szName.push_back(c);
		stream.get(c);
	}
	FAssert(stream.good());
	return 0;
}
unsigned int FDataIOStream::ReadString(std::wstring& szName)
{
	wchar c;
	stream.read((char*)&c, sizeof(wchar));
	szName.clear();

	while (c != L'\0')
	{
		szName.push_back(c);
		stream.read((char*)&c, sizeof(wchar));
	}
	FAssert(stream.good());
	return 0;
}
unsigned int FDataIOStream::ReadString(int count, std::string values[])
{
	for (int i=0; i<count; i++)
	{
		ReadString(values[i]);
	}
	return 0;
}
unsigned int FDataIOStream::ReadString(int count, std::wstring values[])
{
	for (int i=0; i<count; i++)
	{
		ReadString(values[i]);
	}
	return 0;
}
	
char * FDataIOStream::ReadString()		// allocates memory 
{
	CvString s;
	ReadString(s);
	char* szName = new char[s.length()+1];
	memcpy((void*)szName, (void*)s.c_str(), s.length()+1);
	return szName;
}

wchar * FDataIOStream::ReadWideString()	// allocates memory 
{
	CvWString s;
	ReadString(s);
	wchar* szName = new wchar[s.length()+1];
	memcpy((void*)szName, (void*)s.c_str(), (s.length()+1)*sizeof(wchar));
	return szName;
}

void FDataIOStream::Read(char * pC)
{
	stream.get(*pC);
	FAssert(stream.good());
}

void FDataIOStream::Read(byte *pC)
{
	stream.get(*((char*)pC));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, char values[])
{
	stream.read(values, count);
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, byte values[])
{
	stream.read((char*)values, count);
	FAssert(stream.good());
}

void FDataIOStream::Read(bool *b)
{
	stream.read((char*)b, sizeof(bool));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, bool values[])
{
	stream.read((char*)values, sizeof(bool)*count);
	FAssert(stream.good());
}

void FDataIOStream::Read(short	*s)
{
	stream.read((char*)s, sizeof(short));
	FAssert(stream.good());
}

void FDataIOStream::Read(unsigned short	*s)
{
	stream.read((char*)s, sizeof(unsigned short));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, short values[])
{
	stream.read((char*)values, sizeof(short)*count);
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, unsigned short values[])
{
	stream.read((char*)values, sizeof(unsigned short)*count);
	FAssert(stream.good());
}

void FDataIOStream::Read(int* i)
{
	stream.read((char*)i, sizeof(int));
	FAssert(stream.good());
}

void FDataIOStream::Read(unsigned int* i)
{
	stream.read((char*)i, sizeof(unsigned int));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, int values[])
{
	stream.read((char*)values, sizeof(int)*count);
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, unsigned int values[])
{
	stream.read((char*)values, sizeof(unsigned int)*count);
	FAssert(stream.good());
}


void FDataIOStream::Read(long* l)
{
	stream.read((char*)l, sizeof(long));
	FAssert(stream.good());
}

void FDataIOStream::Read(unsigned long* l)
{
	stream.read((char*)l, sizeof(unsigned long));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, long values[])
{
	stream.read((char*)values, sizeof(long)*count);
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, unsigned long values[])
{
	stream.read((char*)values, sizeof(unsigned long)*count);
	FAssert(stream.good());
}


void FDataIOStream::Read(float* value)
{
	stream.read((char*)value, sizeof(float));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, float values[])
{
	stream.read((char*)values, sizeof(float)*count);
	FAssert(stream.good());
}


void FDataIOStream::Read(double* value)
{
	stream.read((char*)value, sizeof(double));
	FAssert(stream.good());
}

void FDataIOStream::Read(int count, double values[])
{
	stream.read((char*)values, sizeof(double)*count);
	FAssert(stream.good());
}

bool FDataIOStream::TryRead(int* i)
{
	stream.read((char*)i, sizeof(int));
	return stream.good();
}

bool FDataIOStream::TryRead(unsigned long* l)
{
	stream.read((char*)l, sizeof(unsigned long));
	return stream.good();
}

void FDataIOStream::Write( char value)
{
	stream.put(value);
	FAssert(stream.good());
}

void FDataIOStream::Write(byte value)
{
	stream.put((char)value);
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const  char values[])
{
	stream.write(values, count);
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const  byte values[])
{
	stream.write((char*)values, count);
	FAssert(stream.good());
}


void FDataIOStream::Write(bool value)
{
	stream.write((char*)&value, sizeof(bool));
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const bool values[])
{
	stream.write((char*)values, sizeof(bool)*count);
	FAssert(stream.good());
}


void FDataIOStream::Write(short value)
{
	stream.write((char*)&value, sizeof(short));
	FAssert(stream.good());
}

void FDataIOStream::Write(unsigned short value)
{
	stream.write((char*)&value, sizeof(unsigned short));
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const short values[])
{
	stream.write((char*)values, sizeof(short)*count);
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const unsigned short values[])
{
	stream.write((char*)values, sizeof(unsigned short)*count);
	FAssert(stream.good());
}


void FDataIOStream::Write(int value)
{
	stream.write((char*)&value, sizeof(int));
	FAssert(stream.good());
}

void FDataIOStream::Write(unsigned int value)
{
	stream.write((char*)&value, sizeof(unsigned int));
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const int values[])
{
	stream.write((char*)values, sizeof(int)*count);
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const unsigned int values[])
{
	stream.write((char*)values, sizeof(unsigned int)*count);
	FAssert(stream.good());
}


void FDataIOStream::Write(long value)
{
	stream.write((char*)&value, sizeof(long));
	FAssert(stream.good());
}

void FDataIOStream::Write(unsigned long  value)
{
	stream.write((char*)&value, sizeof(unsigned long));
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const long values[])
{
	stream.write((char*)values, sizeof(long)*count);
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const unsigned long values[])
{
	stream.write((char*)values, sizeof(unsigned long)*count);
	FAssert(stream.good());
}


void FDataIOStream::Write(float value)
{
	stream.write((char*)&value, sizeof(float));
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const float values[])
{
	stream.write((char*)values, sizeof(float)*count);
	FAssert(stream.good());
}


void FDataIOStream::Write(double value)
{
	stream.write((char*)&value, sizeof(double));
	FAssert(stream.good());
}

void FDataIOStream::Write(int count, const double values[])
{
	stream.write((char*)values, sizeof(double)*count);
	FAssert(stream.good());
}



