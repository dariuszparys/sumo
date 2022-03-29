#!/usr/bin/env python
# Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
# Copyright (C) 2009-2022 German Aerospace Center (DLR) and others.
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# https://www.eclipse.org/legal/epl-2.0/
# This Source Code may also be made available under the following Secondary
# Licenses when the conditions for such availability set forth in the Eclipse
# Public License 2.0 are satisfied: GNU General Public License, version 2
# or later which is available at
# https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
# SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later

# @file    test.py
# @author  Pablo Alvarez Lopez
# @date    2016-11-25

# import common functions for netedit tests
import os
import sys

testRoot = os.path.join(os.environ.get('SUMO_HOME', '.'), 'tests')
neteditTestRoot = os.path.join(
    os.environ.get('TEXTTEST_HOME', testRoot), 'netedit')
sys.path.append(neteditTestRoot)
import neteditTestFunctions as netedit  # noqa

# Open netedit
neteditProcess, referencePosition = netedit.setupAndStart(neteditTestRoot)

# recompute
netedit.rebuildNetwork()

# force save additionals
netedit.forceSaveAdditionals()

# go to select mode
netedit.selectMode()

# select first edge
netedit.leftClick(referencePosition, 250, 180)

# select second edge
netedit.leftClick(referencePosition, 250, 110)

# go to inspect mode
netedit.inspectMode()

# force save additionals
netedit.forceSaveAdditionals()

# inspect selected edges
netedit.leftClick(referencePosition, 250, 180)

# Change parameter 7 with an non valid value
netedit.modifyAttribute(netedit.attrs.Enums.edge.inspectSelection.disallowed, "DummyDisallowed", False)

# Change parameter 7 with a valid value (empty)
netedit.modifyAttribute(netedit.attrs.Enums.edge.inspectSelection.disallowed, "", False)

# Change parameter 7 with a valid value (different separators)
netedit.modifyAttribute(netedit.attrs.Enums.edge.inspectSelection.disallowed, "authority  army, passenger; taxi. tram", False)

# Change parameter 7 with a valid value (empty)
netedit.modifyAttribute(netedit.attrs.Enums.edge.inspectSelection.disallowed, "", False)

# Change parameter 8 with a valid value (empty)
netedit.modifyAllowDisallowValue(netedit.attrs.Enums.edge.inspectSelection.disallowedButton, False)

# Change parameter 7 with a valid value (empty)
netedit.modifyAttribute(netedit.attrs.Enums.edge.inspectSelection.disallowed,
                        "emergency authority army vip passenger hov bus coach tram rail_urban rail " +
                        "rail_electric motorcycle moped pedestrian custom1", False)

# recompute
netedit.rebuildNetwork()

# Check undos
netedit.undo(referencePosition, 3)

# recompute
netedit.rebuildNetwork()

# check redos
netedit.redo(referencePosition, 3)

# save additionals
netedit.saveAdditionals(referencePosition)

# save network
netedit.saveNetwork(referencePosition)

# quit netedit
netedit.quit(neteditProcess)
