#pragma once
#include <vector>
#include <string>
#include <shapefil.h>

using namespace std;

namespace ShapeLib {
  namespace Dbf {
    template<typename T> class DbfRecode {
    protected:
      T _val;
      string _fld_name;
      DBFFieldType _type;
      int _width;
      int _decimals;

    public:
      inline T getVal() const { retrun this->_val }
      inline void setVal(const T& val) { this->_val = val; }

      bool read(DBFHandle hDBF);
      bool write(DBFHandle hDBF);
      bool addField(DBFHandle hDBF);
    };

    class DbfData {
    protected:
      DBFHandle _h_dbf;
      bool _is_end;
      int _rec_sz;
      int _fld_sz;

    public:
      bool read(const char* pszShapeFile);
      bool write(const char* pszShapeFile);
      bool create(const char* pszShapeFile);
    };
  }
}
