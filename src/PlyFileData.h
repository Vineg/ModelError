//
// Created by Vineg on 02-Jan-20.
//

#ifndef MODELERROR_PLYFILEDATA_H
#define MODELERROR_PLYFILEDATA_H

#include "Face.h"

struct PlyFileData : geometry {
    vector<Face> triangles;
};


#endif //MODELERROR_PLYFILEDATA_H
