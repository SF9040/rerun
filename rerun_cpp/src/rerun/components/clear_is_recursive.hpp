// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/clear_is_recursive.fbs".

#pragma once

#include "../result.hpp"

#include <cstdint>
#include <memory>

namespace arrow {
    class Array;
    class BooleanBuilder;
    class DataType;
} // namespace arrow

namespace rerun::components {
    /// **Component**: Configures how a clear operation should behave - recursive or not.
    struct ClearIsRecursive {
        /// If true, also clears all recursive children entities.
        bool recursive;

      public:
        ClearIsRecursive() = default;

        ClearIsRecursive(bool recursive_) : recursive(recursive_) {}

        ClearIsRecursive& operator=(bool recursive_) {
            recursive = recursive_;
            return *this;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::ClearIsRecursive> {
        static constexpr const char Name[] = "rerun.components.ClearIsRecursive";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::components::ClearIsRecursive` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::ClearIsRecursive* instances, size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::BooleanBuilder* builder, const components::ClearIsRecursive* elements,
            size_t num_elements
        );
    };
} // namespace rerun
