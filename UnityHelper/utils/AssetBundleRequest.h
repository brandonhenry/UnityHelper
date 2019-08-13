#include <vector>

#ifndef ASSET_BUNDLE_REQUEST_H
#define ASSET_BUNDLE_REQUEST_H

#include "AsyncOperation.h"
#include "UnityObject.h"

using std::vector;

struct AssetBundleRequest : AsyncOperation
{
    vector<UnityObject> allAssets;
    UnityObject asset;
};

#endif