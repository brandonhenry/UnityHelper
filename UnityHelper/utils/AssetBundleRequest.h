#ifndef ASSET_BUNDLE_REQUEST_H
#define ASSET_BUNDLE_REQUEST_H

#include "AsyncOperation.h"
#include "UnityObject.h"

struct AssetBundleRequest : AsyncOperation
{
    UnityObject* allAssets;
    UnityObject asset;
};

#endif