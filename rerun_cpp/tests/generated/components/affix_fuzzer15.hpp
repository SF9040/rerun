// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/components/fuzzy.fbs".

#pragma once

#include "../datatypes/affix_fuzzer3.hpp"

#include <cstdint>
#include <memory>
#include <optional>
#include <rerun/result.hpp>
#include <utility>

namespace arrow {
    class Array;
    class DataType;
    class DenseUnionBuilder;
} // namespace arrow

namespace rerun::components {
    struct AffixFuzzer15 {
        std::optional<rerun::datatypes::AffixFuzzer3> single_optional_union;

      public:
        AffixFuzzer15() = default;

        AffixFuzzer15(std::optional<rerun::datatypes::AffixFuzzer3> single_optional_union_)
            : single_optional_union(std::move(single_optional_union_)) {}

        AffixFuzzer15& operator=(
            std::optional<rerun::datatypes::AffixFuzzer3> single_optional_union_
        ) {
            single_optional_union = std::move(single_optional_union_);
            return *this;
        }

        /// Cast to the underlying AffixFuzzer3 datatype
        operator std::optional<rerun::datatypes::AffixFuzzer3>() const {
            return single_optional_union;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::AffixFuzzer15> {
        static constexpr const char Name[] = "rerun.testing.components.AffixFuzzer15";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::components::AffixFuzzer15` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::AffixFuzzer15* instances, size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::DenseUnionBuilder* builder, const components::AffixFuzzer15* elements,
            size_t num_elements
        );
    };
} // namespace rerun
