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
neteditProcess, referencePosition = netedit.setupAndStart(neteditTestRoot, ['--new'])

# rebuild network
netedit.rebuildNetwork()

# Change to create mode
netedit.createEdgeMode()

# Create two nodes
netedit.leftClick(referencePosition, 87, 108)
netedit.leftClick(referencePosition, 510, 108)

# Create another two nodes
netedit.leftClick(referencePosition, 87, 185)
netedit.leftClick(referencePosition, 510, 185)
netedit.leftClick(referencePosition, 510, 185)
netedit.leftClick(referencePosition, 87, 185)

# select two-way mode
netedit.changeEditMode(netedit.attrs.Enums.Modes.Network.twoWayMode)

# create square
netedit.leftClick(referencePosition, 87, 292)
netedit.leftClick(referencePosition, 87, 400)

netedit.leftClick(referencePosition, 87, 400)
netedit.leftClick(referencePosition, 510, 400)

netedit.leftClick(referencePosition, 510, 400)
netedit.leftClick(referencePosition, 510, 292)

netedit.leftClick(referencePosition, 510, 292)
netedit.leftClick(referencePosition, 87, 292)

# rebuild network
netedit.rebuildNetwork()

# Check undo and redo
netedit.undo(referencePosition, 7)
netedit.redo(referencePosition, 7)

# rebuild network
netedit.rebuildNetwork()

# save network
netedit.saveNetwork(referencePosition)

# quit netedit
netedit.quit(neteditProcess)
