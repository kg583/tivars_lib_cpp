/*
 * Part of tivars_lib_cpp
 * (C) 2015-2021 Adrien "Adriweb" Bertrand
 * https://github.com/adriweb/tivars_lib_cpp
 * License: MIT
 */

#ifndef TIMODEL_H
#define TIMODEL_H

#include "CommonTypes.h"
#include "TIVarType.h"

namespace tivars
{

    class TIModel
    {

    public:

        TIModel() = default;

        TIModel(int orderId, const std::string& name, uint32_t flags, const std::string& sig) : orderID(orderId), name(name), flags(flags), sig(sig)
        {}

        ~TIModel() = default;

        /* Getters */
        int getOrderId() const { return this->orderID; }
        std::string getName() const { return this->name; }
        uint32_t getFlags() const { return this->flags; }
        std::string getSig() const { return this->sig; }

        bool supportsType(const TIVarType& type);


        /*** "Constructors" ***/
        /**
         * @param   string  name   The version name
         * @return  TIModel
         * @throws  \Exception
         */
        static TIModel createFromName(const std::string& name);

        /**
         * @param   string  sig    The signature (magic bytes)
         * @return  TIModel
         * @throws  \Exception
         */
        static TIModel createFromSignature(const std::string& sig);


    private:
        int orderID      = -1;
        std::string name = "Unknown";
        uint32_t flags   = 0;
        std::string sig  = "";

    };

}

#endif
