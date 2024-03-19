// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/blueprint/datatypes/visible_time_range.fbs".

#pragma once

#include "../../result.hpp"

#include <cstdint>
#include <memory>

namespace arrow {
    class Array;
    class DataType;
    class SparseUnionBuilder;
} // namespace arrow

namespace rerun::blueprint::datatypes {
    /// **Datatype**: Kind of boundary for visible history, see `VisibleTimeRangeBoundary`.
    enum class VisibleTimeRangeBoundaryKind : uint8_t {

        /// Boundary is a value relative to the time cursor.
        RelativeToTimeCursor = 1,

        /// Boundary is an absolute value.
        Absolute = 2,

        /// The boundary extends to infinity.
        Infinite = 3,
    };
} // namespace rerun::blueprint::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<blueprint::datatypes::VisibleTimeRangeBoundaryKind> {
        static constexpr const char Name[] =
            "rerun.blueprint.datatypes.VisibleTimeRangeBoundaryKind";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::blueprint:: datatypes::VisibleTimeRangeBoundaryKind` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const blueprint::datatypes::VisibleTimeRangeBoundaryKind* instances,
            size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::SparseUnionBuilder* builder,
            const blueprint::datatypes::VisibleTimeRangeBoundaryKind* elements, size_t num_elements
        );
    };
} // namespace rerun
