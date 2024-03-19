// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/class_id.fbs".

#pragma once

#include "../datatypes/class_id.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>

namespace rerun::components {
    /// **Component**: A 16-bit ID representing a type of semantic class.
    struct ClassId {
        rerun::datatypes::ClassId id;

      public:
        ClassId() = default;

        ClassId(rerun::datatypes::ClassId id_) : id(id_) {}

        ClassId& operator=(rerun::datatypes::ClassId id_) {
            id = id_;
            return *this;
        }

        ClassId(uint16_t id_) : id(id_) {}

        ClassId& operator=(uint16_t id_) {
            id = id_;
            return *this;
        }

        /// Cast to the underlying ClassId datatype
        operator rerun::datatypes::ClassId() const {
            return id;
        }
    };
} // namespace rerun::components

namespace rerun {
    static_assert(sizeof(rerun::datatypes::ClassId) == sizeof(components::ClassId));

    /// \private
    template <>
    struct Loggable<components::ClassId> {
        static constexpr const char Name[] = "rerun.components.ClassId";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype() {
            return Loggable<rerun::datatypes::ClassId>::arrow_datatype();
        }

        /// Serializes an array of `rerun::components::ClassId` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::ClassId* instances, size_t num_instances
        ) {
            return Loggable<rerun::datatypes::ClassId>::to_arrow(&instances->id, num_instances);
        }
    };
} // namespace rerun
