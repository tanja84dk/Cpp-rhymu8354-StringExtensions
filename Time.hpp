#ifndef SYSTEM_ABSTRACTIONS_TIME_HPP
#define SYSTEM_ABSTRACTIONS_TIME_HPP

/**
 * @file Time.hpp
 *
 * This module declares the SystemAbstractions::Time class.
 *
 * Copyright (c) 2016 by Richard Walters
 */

#include <memory>

namespace SystemAbstractions {

    /**
     * This class contains methods dealing with time.
     */
    class Time {
        // Public methods
    public:
        /**
         * This is the instance constructor.
         */
        Time();

        /**
         * This is the instance destructor.
         */
        ~Time();

        /**
         * @todo Needs documentation
         */
        double GetTime();

        // Private properties
    private:
        /**
         * This contains any platform-specific state for the object.
         */
        std::unique_ptr< struct TimeImpl > _impl;
    };

}

#endif /* SYSTEM_ABSTRACTIONS_TIME_HPP */