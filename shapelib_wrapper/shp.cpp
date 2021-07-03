#include "shp.h"


namespace ShapeLib {
  namespace Shp {
    bool ShpT::read(const SHPHandle& hSHP, const int &iShape)
    {
      if (hSHP == nullptr) {
        fprintf(stderr, "SHPHandle is null.");
        return false;
      }

      SHPObject* psShape = SHPReadObject(hSHP, iShape);
      if (psShape == NULL)
      {
        fprintf(stderr, "Unable to read shape %d, terminating object reading.\n", iShape);
        return false;
      }

      for (int i = 0; i < psShape->nVertices; i++) {
        this->push_back(Point(psShape->padfX[i], psShape->padfY[i], psShape->padfZ[i]));
      }
 
      return true;
    }
    bool ShpT::write(const SHPHandle& hSHP)
    {
      if (hSHP == nullptr) {
        fprintf(stderr, "SHPHandle is null.\n");
        return false;
      }

      SHPObject* psOutObj;
      double* padfX = new double[this->size()];
      double* padfY = new double[this->size()];
      double* padfZ = new double[this->size()];

      for (vector<Point>::const_iterator it = this->begin(); it != this->end() ; ++it) {
        padfX[0] = it->getX();
        padfY[0] = it->getY();
        padfZ[0] = it->getZ();
      }

      psOutObj = SHPCreateSimpleObject(SHPT_POINTZ, 1, padfX, padfY, padfZ);
      SHPWriteObject(hSHP, -1, psOutObj);
      SHPDestroyObject(psOutObj);

      delete[] padfX;
      delete[] padfY;
      delete[] padfZ;

      return true;
    }
  }
}
