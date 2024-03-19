// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/class_description.fbs".

#pragma once

#include "../collection.hpp"
#include "../result.hpp"
#include "annotation_info.hpp"
#include "keypoint_pair.hpp"

#include <cstdint>
#include <memory>

namespace arrow {
    class Array;
    class DataType;
    class StructBuilder;
} // namespace arrow

namespace rerun::datatypes {
    /// **Datatype**: The description of a semantic Class.
    ///
    /// If an entity is annotated with a corresponding `ClassId`, rerun will use
    /// the attached `AnnotationInfo` to derive labels and colors.
    ///
    /// Keypoints within an annotation class can similarly be annotated with a
    /// `KeypointId` in which case we should defer to the label and color for the
    /// `AnnotationInfo` specifically associated with the Keypoint.
    ///
    /// Keypoints within the class can also be decorated with skeletal edges.
    /// Keypoint-connections are pairs of `KeypointId`s. If an edge is
    /// defined, and both keypoints exist within the instance of the class, then the
    /// keypoints should be connected with an edge. The edge should be labeled and
    /// colored as described by the class's `AnnotationInfo`.
    struct ClassDescription {
        /// The `AnnotationInfo` for the class.
        rerun::datatypes::AnnotationInfo info;

        /// The `AnnotationInfo` for all of the keypoints.
        rerun::Collection<rerun::datatypes::AnnotationInfo> keypoint_annotations;

        /// The connections between keypoints.
        rerun::Collection<rerun::datatypes::KeypointPair> keypoint_connections;

      public:
        // Extensions to generated type defined in 'class_description_ext.cpp'

        /// Create a new `ClassDescription` from a single annotation info.
        ClassDescription(
            uint16_t id, std::optional<std::string> label = std::nullopt,
            std::optional<datatypes::Rgba32> color = std::nullopt
        )
            : info(id, label, color) {}

        ClassDescription(
            AnnotationInfo info_, Collection<AnnotationInfo> keypoint_annotations_ = {},
            Collection<KeypointPair> keypoint_connections_ = {}
        )
            : info(std::move(info_)),
              keypoint_annotations(std::move(keypoint_annotations_)),
              keypoint_connections(std::move(keypoint_connections_)) {}

      public:
        ClassDescription() = default;
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::ClassDescription> {
        static constexpr const char Name[] = "rerun.datatypes.ClassDescription";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::datatypes::ClassDescription` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const datatypes::ClassDescription* instances, size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StructBuilder* builder, const datatypes::ClassDescription* elements,
            size_t num_elements
        );
    };
} // namespace rerun
