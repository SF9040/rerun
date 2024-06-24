// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/tensor_dimension_selection.fbs".

#include "tensor_dimension_selection.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::datatypes {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>&
        Loggable<datatypes::TensorDimensionSelection>::arrow_datatype() {
        static const auto datatype = arrow::struct_({
            arrow::field("dimension", arrow::uint32(), false),
            arrow::field("invert", arrow::boolean(), false),
        });
        return datatype;
    }

    Result<std::shared_ptr<arrow::Array>> Loggable<datatypes::TensorDimensionSelection>::to_arrow(
        const datatypes::TensorDimensionSelection* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(
                Loggable<datatypes::TensorDimensionSelection>::fill_arrow_array_builder(
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

    rerun::Error Loggable<datatypes::TensorDimensionSelection>::fill_arrow_array_builder(
        arrow::StructBuilder* builder, const datatypes::TensorDimensionSelection* elements,
        size_t num_elements
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
            auto field_builder = static_cast<arrow::UInt32Builder*>(builder->field_builder(0));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                ARROW_RETURN_NOT_OK(field_builder->Append(elements[elem_idx].dimension));
            }
        }
        {
            auto field_builder = static_cast<arrow::BooleanBuilder*>(builder->field_builder(1));
            ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                ARROW_RETURN_NOT_OK(field_builder->Append(elements[elem_idx].invert));
            }
        }
        ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements), nullptr));

        return Error::ok();
    }
} // namespace rerun
