
/* Copyright (c) 2014, Human Brain Project
 *                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 *                     Stefan.Eilemann@epfl.ch
 */

#ifndef ZEQ_PUBLISHER_H
#define ZEQ_PUBLISHER_H

#include <boost/noncopyable.hpp>
#include <zeq/types.h>

namespace zeq
{

namespace detail { class Publisher; }

/** Serves and publishes events, consumed by Subscriber. */
class Publisher : public boost::noncopyable
{
public:
    /**
     * Create a publisher on the given URI.
     *
     * @param uri publishing URI in the format scheme://[*|host|IP|IF][:port]
     */
    explicit Publisher( const lunchbox::URI& uri );

    ~Publisher();

    /**
     * Publish the given event to any subscriber.
     *
     * If there is no subscriber for that event, no event will be send.
     *
     * @param event the serialized event to publish
     * @return true if publish was successful
     */
    bool publish( const Event& event );

private:
    detail::Publisher* const _impl;
};

}

#endif
