#pragma once

typedef UINT32 uint32_t;
typedef UINT64 uint64_t;

//�ֽ����Сͷ�ʹ�ͷ������
#define ZEN_LITTLE_ENDIAN  0x0123
#define ZEN_BIG_ENDIAN     0x3210

//Ŀǰ���еĴ��붼��Ϊ��Сͷ������ģ���֪������֮�����״����Ƿ񻹻�Ϊ��ͷ������һ�Σ�
#ifndef ZEN_BYTES_ORDER
#define ZEN_BYTES_ORDER    ZEN_LITTLE_ENDIAN
#endif

#ifndef ZEN_SWAP_UINT16
#define ZEN_SWAP_UINT16(x)  ((((x) & 0xff00) >>  8) | (((x) & 0x00ff) <<  8))
#endif
#ifndef ZEN_SWAP_UINT32
#define ZEN_SWAP_UINT32(x)  ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
	(((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
#endif
#ifndef ZEN_SWAP_UINT64
#define ZEN_SWAP_UINT64(x)  ((((x) & 0xff00000000000000) >> 56) | (((x) & 0x00ff000000000000) >>  40) | \
	(((x) & 0x0000ff0000000000) >> 24) | (((x) & 0x000000ff00000000) >>  8) | \
	(((x) & 0x00000000ff000000) << 8 ) | (((x) & 0x0000000000ff0000) <<  24) | \
	(((x) & 0x000000000000ff00) << 40 ) | (((x) & 0x00000000000000ff) <<  56))
#endif



///MD5�Ľ�����ݳ���
static const size_t ZEN_MD5_HASH_SIZE   = 16;
///SHA1�Ľ�����ݳ���
static const size_t ZEN_SHA1_HASH_SIZE  = 20;

namespace ZEN_LIB
{


	/*!
	@brief      ��ĳ���ڴ���MD5��
	@return     unsigned char* ���صĵĽ����
	@param[in]  buf    ��MD5���ڴ�BUFFERָ��
	@param[in]  size   BUFFER����
	@param[out] result ���
	*/
	unsigned char *md5(const unsigned char *buf,
		size_t size,
		unsigned char result[ZEN_MD5_HASH_SIZE]);


	/*!
	@brief      ���ڴ��BUFFER��SHA1ֵ
	@return     unsigned char* ���صĵĽ��
	@param[in]  buf    ��SHA1���ڴ�BUFFERָ��
	@param[in]  size   BUFFER����
	@param[out] result ���
	*/
	unsigned char *sha1(const unsigned char *buf,
		size_t size,
		unsigned char result[ZEN_SHA1_HASH_SIZE]);
};

int base64_decode( const char * base64, unsigned char * bindata );