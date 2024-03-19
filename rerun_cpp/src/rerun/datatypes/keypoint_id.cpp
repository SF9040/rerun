// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/keypoint_id.fbs".

#include "keypoint_id.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::datatypes {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<datatypes::KeypointId>::arrow_datatype() {
        static const auto datatype = arrow::uint16();
        return datatype;
    }

    Result<std::shared_ptr<arrow::Array>> Loggable<datatypes::KeypointId>::to_arrow(
        const datatypes::KeypointId* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<datatypes::KeypointId>::fill_arrow_array_builder(
                static_cast<arrow::UInt16Builder*>(builder.get()),
                instances,
                num_instances
            ));
        }
        std::shared_ptr<arrow::Array> array;
        ARROW_RETURN_NOT_OK(builder->Finish(&array));
        return array;
    }

    rerun::Error Loggable<datatypes::KeypointId>::fill_arrow_array_builder(
        arrow::UInt16Builder* builder, const datatypes::KeypointId* elements, size_t num_elements
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

        static_assert(sizeof(*elements) == sizeof(elements->id));
        ARROW_RETURN_NOT_OK(builder->AppendValues(&elements->id, static_cast<int64_t>(num_elements))
        );

        return Error::ok();
    }
} // namespace rerun
