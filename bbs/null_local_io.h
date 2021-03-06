/**************************************************************************/
/*                                                                        */
/*                              WWIV Version 5.0x                         */
/*             Copyright (C)1998-2015, WWIV Software Services             */
/*                                                                        */
/*    Licensed  under the  Apache License, Version  2.0 (the "License");  */
/*    you may not use this  file  except in compliance with the License.  */
/*    You may obtain a copy of the License at                             */
/*                                                                        */
/*                http://www.apache.org/licenses/LICENSE-2.0              */
/*                                                                        */
/*    Unless  required  by  applicable  law  or agreed to  in  writing,   */
/*    software  distributed  under  the  License  is  distributed on an   */
/*    "AS IS"  BASIS, WITHOUT  WARRANTIES  OR  CONDITIONS OF ANY  KIND,   */
/*    either  express  or implied.  See  the  License for  the specific   */
/*    language governing permissions and limitations under the License.   */
/**************************************************************************/
#ifndef __INCLUDED_BBS_NULL_LOCAL_IO_H__
#define __INCLUDED_BBS_NULL_LOCAL_IO_H__
#include "bbs/local_io.h"

#include <string>

#if defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4125 4100 )
#endif

class NullLocalIO : public LocalIO {
public:
  NullLocalIO();
  ~NullLocalIO();
  virtual void LocalPutch(unsigned char ch) override {};
  virtual void LocalGotoXY(int x, int y) override {}
  virtual int WhereX() override { return 0; }
  virtual int WhereY() override { return 0; }
  virtual void LocalLf() override {}
  virtual void LocalCr() override {}
  virtual void LocalCls() override {}
  virtual void LocalBackspace() override {}
  virtual void LocalPutchRaw(unsigned char ch) override {}
  virtual void LocalPuts(const std::string& s) override {}
  virtual void LocalXYPuts(int x, int y, const std::string& text) override {}
  virtual void LocalFastPuts(const std::string& text) override {}
  virtual int LocalPrintf(const char *pszFormattedText, ...) override { return 0; }
  virtual int LocalXYPrintf(int x, int y, const char *pszFormattedText, ...) override { return 0; }
  virtual int LocalXYAPrintf(int x, int y, int nAttribute, const char *pszFormattedText, ...) override { return 0; }
  virtual void set_protect(int l) override {}
  virtual void savescreen() override {}
  virtual void restorescreen() override {}
  virtual void skey(char ch) override {}
  virtual void tleft(bool bCheckForTimeOut) override {}
  virtual bool LocalKeyPressed() override { return false; }
  virtual void SaveCurrentLine(char *cl, char *atr, char *xl, char *cc) override {}
  virtual unsigned char LocalGetChar() override { return static_cast<unsigned char>(getchar()); }
  virtual void MakeLocalWindow(int x, int y, int xlen, int ylen) override {}
  virtual void SetCursor(int cursorStyle) override {}
  virtual void LocalClrEol() override {}
  virtual void LocalWriteScreenBuffer(const char *pszBuffer) override {}
  virtual int GetDefaultScreenBottom() override { return 24; }
  virtual void LocalEditLine(char *s, int len, int statusx, int *returncode, char *ss) override {}
  virtual void UpdateNativeTitleBar() override {}
  virtual void UpdateTopScreen(WStatus* pStatus, WSession *pSession, int nInstanceNumber) override {}

  std::string* captured_;
};

#if defined( _MSC_VER )
#pragma warning( pop )
#endif // _MSC_VER


#endif  // __INCLUDED_BBS_NULL_LOCAL_IO_H__