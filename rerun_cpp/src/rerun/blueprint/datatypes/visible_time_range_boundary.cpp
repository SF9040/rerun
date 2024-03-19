// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/blueprint/datatypes/visible_time_range.fbs".

#include "visible_time_range_boundary.hpp"

#include "../../datatypes/time_int.hpp"
#include "visible_time_range_boundary_kind.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::blueprint::datatypes {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>&
        Loggable<blueprint::datatypes::VisibleTimeRangeBoundary>::arrow_datatype() {
        static const auto datatype = arrow::struct_({
            arrow::field(
                "kind",
                Loggable<rerun::blueprint::datatypes::VisibleTimeRangeBoundaryKind>::arrow_datatype(
                ),
                false
            ),
            arrow::field("time", Loggable<rerun::datatypes::TimeInt>::arrow_datatype(), false),
        });
        return datatype;
    }

    Result<std::shared_ptr<arrow::Array>>
        Loggable<blueprint::datatypes::VisibleTimeRangeBoundary>::to_arrow(
            const blueprint::datatypes::VisibleTimeRangeBoundary* instances, size_t num_instances
        ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(
                Loggable<blueprint::datatypes::VisibleTimeRangeBoundary>::fill_arrow_array_builder(
                    static_cast<arrow::StructBuilder*>(builder.get()),
                    instances,
                    num_instances
                )
            );
        }
        std::shared_ptr<arrow::Array> array;
        ARROW_RETURN_NOT_OK(builder->Finish(&array));
        return array;
    }

    rerun::Error Loggable<blueprint::datatypes::VisibleTimeRangeBoundary>::fill_arrow_array_builder(
        arrow::StructBuilder* builder,
        const blueprint::datatypes::VisibleTimeRangeBoundary* elements, size_t num_elements
    ) {
        if (builder == nullptr) {
            return rerun::Error(ErrorCode::UnexpectedNullArgument, "Passed array builder is null.");
        }
        if (elements == nullptr) {
            return rerun::Error(
                ErrorCode::UnexpectedNullArgument,
                "Cannot serialize null pointer to arrow array."
            );
        }

        {
            auto field_builder = static_cast<arrow::SparseUnionBuilder*>(builder->field_builder(0));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                RR_RETURN_NOT_OK(
                    Loggable<rerun::blueprint::datatypes::VisibleTimeRangeBoundaryKind>::
                        fill_arrow_array_builder(field_builder, &elements[elem_idx].kind, 1)
                );
            }
        }
        {
            auto field_builder = static_cast<arrow::Int64Builder*>(builder->field_builder(1));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                RR_RETURN_NOT_OK(Loggable<rerun::datatypes::TimeInt>::fill_arrow_array_builder(
                    field_builder,
                    &elements[elem_idx].time,
                    1
                ));
            }
        }
        ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements), nullptr));

        return Error::ok();
    }
} // namespace rerun
