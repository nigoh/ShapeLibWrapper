#pragma once

#include <vector>
#include <shapefil.h>

using namespace std;
namespace ShapeLib {
  namespace Shp {

    class Point {
    protected:
      double _x;
      double _y;
      double _z;

    public:
      Point(const double x, const double y, const double z) : _x(x), _y(y), _z(z) {};
      ~Point() = default;

      inline const double getX() const { return this->_x; }
      inline const double getY() const { return this->_y; }
      inline const double getZ() const { return this->_z; }
      inline void setX(const double& val) { this->_x = val; }
      inline void setY(const double& val) { this->_y = val; }
      inline void setZ(const double& val) { this->_z = val; }
    };

    class ShpT : public vector<Point> {
    protected:
      int _shp_type;

    public:
      ShpT(int shpType) : _shp_type(shpType) {};
      ShpT() : _shp_type(0) {};
      ~ShpT() = default;
      bool read(const SHPHandle& hShp, const int &iShape);
      bool write(const SHPHandle& hShp);
    };

    class ShpTPoint : public ShpT {
      ShpTPoint() { _shp_type = SHPT_POINTZ; };
      ~ShpTPoint() = default;
    };

    class ShpTLineString : public ShpT{
      ShpTLineString() { _shp_type = SHPT_ARCZ; };
      ~ShpTLineString() = default;
    };

    class ShpTPolygon : public ShpT {
      ShpTPolygon() { _shp_type = SHPT_POLYGONZ; };
      ~ShpTPolygon() = default;
    };

    class ShpInfo {
    private:
      SHPHandle _h_shp;
      int _shp_type;
      int _rec_sz;
      double	_x_min;
      double	_y_min;
      double	_z_min;
      double	_x_max;
      double	_y_max;
      double	_z_max;

    public:
      ShpInfo() = default;
      ~ShpInfo() = default;

      inline const double getMinX() const { return this->_x_min; }
      inline const double getMinY() const { return this->_y_min; }
      inline const double getMinZ() const { return this->_z_min; }
      inline const double getMaxX() const { return this->_x_max; }
      inline const double getMaxY() const { return this->_y_max; }
      inline const double getMaxZ() const { return this->_z_max; }
    };

    class ShpData : public ShpInfo {
      bool _is_end;
      int _conter;

    public:
      ShpData() = default;
      ~ShpData() = default;

      virtual bool readAll(const char* pszShapeFile);
      virtual bool readShape(const char* pszShapeFile);
      virtual bool write(const char* pszShapeFile);
      virtual bool create(const char* pszShapeFile);
    };
  }
}
