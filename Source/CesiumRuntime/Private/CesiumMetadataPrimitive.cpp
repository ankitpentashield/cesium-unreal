// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#include "CesiumMetadataPrimitive.h"
#include "CesiumGltf/ExtensionMeshPrimitiveExtFeatureMetadata.h"
#include "CesiumGltf/Model.h"

FCesiumMetadataPrimitive::FCesiumMetadataPrimitive(
    const FCesiumPrimitiveFeatures& PrimitiveFeatures,
    const FCesiumPrimitiveMetadata& PrimitiveMetadata,
  const FCesiumModelMetadata& ModelMetadata)
    : _pPrimitiveFeatures(&PrimitiveFeatures),
      _pPrimitiveMetadata(&PrimitiveMetadata) {}

const TArray<FCesiumFeatureIdAttribute>
UCesiumMetadataPrimitiveBlueprintLibrary::GetFeatureIdAttributes(
    UPARAM(ref) const FCesiumMetadataPrimitive& MetadataPrimitive) {
  TArray<FCesiumFeatureIdAttribute> featureIDAttributes;
  if (!MetadataPrimitive._pPrimitiveFeatures) {
    return featureIDAttributes;
  }

  const TArray<FCesiumFeatureIdSet> featureIDSets =
      UCesiumPrimitiveFeaturesBlueprintLibrary::GetFeatureIDSetsOfType(
          *MetadataPrimitive._pPrimitiveFeatures,
          ECesiumFeatureIdType::Attribute);

  featureIDAttributes.Reserve(featureIDSets.Num());
  for (const FCesiumFeatureIdSet& featureIDSet : featureIDSets) {
    featureIDAttributes.Add(
        UCesiumFeatureIdSetBlueprintLibrary::GetAsFeatureIDAttribute(
            featureIDSet));
  }

  return featureIDAttributes;
}

const TArray<FCesiumFeatureIdTexture>
UCesiumMetadataPrimitiveBlueprintLibrary::GetFeatureIdTextures(
    UPARAM(ref) const FCesiumMetadataPrimitive& MetadataPrimitive) {
  TArray<FCesiumFeatureIdTexture> featureIDTextures;
  if (!MetadataPrimitive._pPrimitiveFeatures) {
    return featureIDTextures;
  }

  const TArray<FCesiumFeatureIdSet> featureIDSets =
      UCesiumPrimitiveFeaturesBlueprintLibrary::GetFeatureIDSetsOfType(
          *MetadataPrimitive._pPrimitiveFeatures,
          ECesiumFeatureIdType::Texture);

  featureIDTextures.Reserve(featureIDSets.Num());
  for (const FCesiumFeatureIdSet& featureIDSet : featureIDSets) {
    featureIDTextures.Add(
        UCesiumFeatureIdSetBlueprintLibrary::GetAsFeatureIDTexture(
            featureIDSet));
  }

  return featureIDTextures;
}

const TArray<FString>
UCesiumMetadataPrimitiveBlueprintLibrary::GetFeatureTextureNames(
    UPARAM(ref) const FCesiumMetadataPrimitive& MetadataPrimitive) {
  TArray<FString> propertyTextureNames;
  if (!MetadataPrimitive._pPrimitiveMetadata) {
    return;
  }

  const TArray<int64>& propertyTextureIndices =
      UCesiumPrimitiveMetadataBlueprintLibrary::GetPropertyTextureIndices(
          *MetadataPrimitive._pPrimitiveMetadata);

  // this requires model metadata
 /* const TArray<FCesiumPropertyTexture> propertyTextures = UCesiumM

  propertyTextureNames.Reserve(propertyTextureIndices.Num());
  for (const int64 index : propertyTextureIndices) {
    propertyTextureNames.Add(::GetAsFeatureIDTexture(
            featureIDSet));
  }*/

  return propertyTextureNames;
}

int64 UCesiumMetadataPrimitiveBlueprintLibrary::GetFirstVertexIDFromFaceID(
    UPARAM(ref) const FCesiumMetadataPrimitive& MetadataPrimitive,
    int64 FaceID) {
  return UCesiumPrimitiveFeaturesBlueprintLibrary::GetFirstVertexFromFace(
      *MetadataPrimitive._pPrimitiveFeatures,
      FaceID);
}
