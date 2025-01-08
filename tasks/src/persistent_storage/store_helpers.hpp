#ifndef STOREHELPERS_H_
#define STOREHELPERS_H_

#include <string>
#include <string_view>
#include <cstring>


template <typename T>
void* save_simple_type(T t, void* src) {
  memcpy(src, &t, sizeof(t));
  return static_cast<char*>(src) + sizeof(t);
}

template<typename T>
const void * restore_simple_type(T& type ,const void * src)
{
    memcpy(&type,src,sizeof(T));
    return static_cast<const char *>(src) + sizeof(T);
}


inline void* save_str(const std::string_view& str, void* dest) {
  auto size = str.length();
  memcpy(dest, &size, sizeof(size));
  char* charDest = static_cast<char*>(dest) + sizeof(size);
  memcpy(charDest, str.data(), str.length());
  return charDest + str.length();
}

inline const void* restore_str(std::string& str, const void* src)
{
    std::string::size_type size;
    memcpy(&size,src,sizeof(size));
    const char * Strsrc = static_cast<const char*>(src) + sizeof(size);   
    str.reserve(size);
    str.insert(0,static_cast<const char *>(Strsrc),size);
    return static_cast<const char *>(Strsrc) + size;
}


#endif