
/* Copyright (c) 2014, Human Brain Project
 *                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 */

#ifndef ZEQ_VOCABULARY_H
#define ZEQ_VOCABULARY_H

#include <zeq/types.h>

namespace zeq
{

/**
 * An application specific vocabulary of supported events including their
 * serialization. The implementation is dependend on a certain serialization
 * backend, which is flatbuffers by default.
 */
namespace vocabulary
{

/**
 * The supported event types by this vocabulary
 */
enum EventType
{
    EVENT_EXIT,
    EVENT_CAMERA,
    EVENT_SELECTION,
    EVENT_INVALID
};

/**
 * Serialize the given camera matrix into an Event of type camera.
 * @param matrix the 4x4 camera matrix in OpenGL data layout
 * @return the serialized event
 */
Event serializeCamera( const std::vector< float >& matrix );

/**
 * Deserialize the given camera event into the 4x4 matrix.
 * @param camera the camera event generated by serializeCamera()
 * @return the 4x4 camera matrix in OpenGL data layout
 */
std::vector< float > deserializeCamera( const Event& camera );

/**
 * Serialize the given selection into an Event of type selection.
 * @param vector of id (uint) 
 * @return the serialized event
 */
Event serializeSelection( const std::vector< unsigned int >& selection );

/**
 * Deserialize the given selection event into the vector of ids.
 * @param selection event generated by serializeSelection()
 * @return The vector of ids (uint)
 */
std::vector< unsigned int > deserializeSelection( const Event& selection );

}
}

#endif
