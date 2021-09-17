/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2006-2021 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GNEChangeGroup.h
/// @author  Pablo Alvarez Lopez
/// @date    Sep 2021
///
//
/****************************************************************************/
#pragma once
#include <config.h>

#include "GNEChange.h"

/**
* Group of undoable commands.  A group may comprise multiple
* individual actions which together undo (or redo) a larger
* operation.  Even larger operations may be built by nesting
* multiple undo groups.
*/
class GNEChangeGroup : public GNEChange {
    FXDECLARE(GNEChangeGroup)

public:
    /// @name declare friend class
    friend class GNEUndoList;

    /**@brief Construct initially empty undo command group
     * @param[in] supermode related with this group
     */
    GNEChangeGroup(Supermode supermode, const std::string &description);

    /// @brief Delete undo command and sub-commands
    ~GNEChangeGroup();

    /// @brief Undo whole command group
    void undo();

    /// @brief Redo whole command group
    void redo();

    /// @brief get undo Name
    std::string undoName() const;

    /// @brief get redo name
    std::string redoName() const;

    /// @brief Return the size of the command group
    int size() const;

    /// @brief get supermode
    Supermode getSupermode() const;

    /// @brief get description
    const std::string& getDescription();

    /// @brief Return TRUE if empty
    bool empty() const;

protected:
    /// @brief FOX need this
    GNEChangeGroup();

    /// @brief supermode related with this change
    const Supermode mySupermode;

    /// @brief description of command
    const std::string myDescription;

private:
    /// @brief undo list command (can be access by GNEUndoList)
    GNEChange* undoList;

    /// @brief redo list command (can be access by GNEUndoList)
    GNEChange* redoList;

    /// @brief group (can be access by GNEUndoList)
    GNEChangeGroup* group;  

    /// @brief invalidate copy constructor
    GNEChangeGroup(const GNEChangeGroup&);
    
    /// @brief invalidate assignment operator
    GNEChangeGroup &operator=(const GNEChangeGroup&) = delete;
};