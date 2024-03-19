// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/rotation3d.fbs".

#pragma once

#include "../datatypes/rotation3d.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>

namespace rerun::components {
    /// **Component**: A 3D rotation, represented either by a quaternion or a rotation around axis.
    struct Rotation3D {
        /// Representation of the rotation.
        rerun::datatypes::Rotation3D repr;

      public:
        // Extensions to generated type defined in 'rotation3d_ext.cpp'

        static const Rotation3D IDENTITY;

        /// Construct Rotation3d from Quaternion.
        Rotation3D(datatypes::Quaternion quaternion) : repr{quaternion} {}

        /// Construct Rotation3d from axis-angle
        Rotation3D(datatypes::RotationAxisAngle axis_angle) : repr{axis_angle} {}

      public:
        Rotation3D() = default;

        Rotation3D(rerun::datatypes::Rotation3D repr_) : repr(repr_) {}

        Rotation3D& operator=(rerun::datatypes::Rotation3D repr_) {
            repr = repr_;
            return *this;
        }

        /// Cast to the underlying Rotation3D datatype
        operator rerun::datatypes::Rotation3D() const {
            return repr;
        }
    };
} // namespace rerun::components

namespace rerun {
    static_assert(sizeof(rerun::datatypes::Rotation3D) == sizeof(components::Rotation3D));

    /// \private
    template <>
    struct Loggable<components::Rotation3D> {
        static constexpr const char Name[] = "rerun.components.Rotation3D";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype() {
            return Loggable<rerun::datatypes::Rotation3D>::arrow_datatype();
        }

        /// Serializes an array of `rerun::components::Rotation3D` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::Rotation3D* instances, size_t num_instances
        ) {
            return Loggable<rerun::datatypes::Rotation3D>::to_arrow(
                &instances->repr,
                num_instances
            );
        }
    };
} // namespace rerun
